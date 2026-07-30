/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:24:54 by kpineda-          #+#    #+#             */
/*   Updated: 2025/03/15 20:19:58 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mandelbrot(double cre, double cim, t_data *data)
{
	float	zr;
	float	zi;
	int		iter;
	float	zr2;
	float	zi2;

	zr = 0;
	zi = 0;
	iter = 0;
	while ((zr * zr + zi * zi) < ESCAPE_RADIUS && iter < data->max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zr2 > ESCAPE_RADIUS)
			break ;
		zi = 2 * zr * zi + cim;
		zr = zr2 - zi2 + cre;
		iter++;
	}
	return (iter);
}

int	julia(double zr, double zi, t_data *data)
{
	int		iter;
	float	zr2;
	float	zi2;

	iter = 0;
	while ((zr * zr + zi * zi) < ESCAPE_RADIUS && iter < data->max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > ESCAPE_RADIUS)
			break ;
		zi = 2 * zr * zi + data->julia_im;
		zr = zr2 - zi2 + data->julia_re;
		iter++;
	}
	return (iter);
}

int	tricorn(double cre, double cim, t_data *data)
{
	float	zr;
	float	zi;
	int		iter;
	float	zr2;
	float	zi2;

	zr = 0;
	zi = 0;
	iter = 0;
	while ((zr * zr + zi * zi) < ESCAPE_RADIUS && iter < data->max_iter)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > ESCAPE_RADIUS)
			break ;
		zi = -2 * zr * zi + cim;
		zr = zr2 - zi2 + cre;
		iter++;
	}
	return (iter);
}

void	draw_fractal(t_data *data, int *color_table)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		draw_fractal_row(data, y, color_table);
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
