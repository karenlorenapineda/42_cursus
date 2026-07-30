/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:38:20 by kpineda-          #+#    #+#             */
/*   Updated: 2025/03/15 20:22:27 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

float	abs_float(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	len;

	i = -1;
	len = ft_strlen(s1);
	while (++i < len)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char) s2[i]);
		if (s1[i] == '\0' && s2[i] != '\0')
			return (1);
	}
	return (0);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int	index;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		index = (y * data->img.line_len) + (x * (data->img.bits_per_pixel / 8));
		*(int *)(data->img.img_pixels_ptr + index) = color;
	}
}

int	set_color(int iter, int *color_table, t_data *data)
{
	if (iter == data->max_iter)
		return (0);
	return (color_table[iter]);
}

void	draw_fractal_row(t_data *data, int y, int *color_table)
{
	int		x;
	int		iter;
	double	scaled_x;
	double	scaled_y;

	x = 0;
	scaled_y = (y - HEIGHT / 2.0) * (1.0 / (0.5 * data->zoom * HEIGHT))
		+ data->move_y;
	while (x < WIDTH)
	{
		scaled_x = (x - WIDTH / 2.0) * (1.0 / (0.5 * data->zoom * WIDTH))
			+ data->move_x;
		if (data->fractal == 0)
			iter = julia(scaled_x, scaled_y, data);
		else if (data->fractal == 1)
			iter = mandelbrot(scaled_x, scaled_y, data);
		else if (data->fractal == 2)
			iter = tricorn(scaled_x, scaled_y, data);
		put_pixel(data, x, y, set_color(iter, color_table, data));
		x++;
	}
}
