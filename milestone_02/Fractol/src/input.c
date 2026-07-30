/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:03:58 by kpineda-          #+#    #+#             */
/*   Updated: 2025/03/08 23:36:34 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	exit_program(t_data *data)
{
	if (data->color_table)
		free(data->color_table);
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx, data->img.img_ptr);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

int	handle_input(int keysym, t_data *data)
{
	float	move_step;

	move_step = 0.1 / data->zoom;
	if (keysym == XK_Escape)
		exit_program(data);
	else if (keysym == XK_w || keysym == XK_Up)
		data->move_y -= move_step;
	else if (keysym == XK_s || keysym == XK_Down)
		data->move_y += move_step;
	else if (keysym == XK_a || keysym == XK_Left)
		data->move_x -= move_step;
	else if (keysym == XK_d || keysym == XK_Right)
		data->move_x += move_step;
	draw_fractal(data, data->color_table);
	return (0);
}

int	hand_mouse_input(int button, t_data *data, t_point *point)
{
	if (button == 4)
	{
		point->zoom_factor = 1.1;
		point->mouse_x = -((point->x - WIDTH / 2.0) / (0.5 * data->zoom
					* WIDTH)) + data->move_x;
		point->mouse_y = -((point->y - HEIGHT / 2.0) / (0.5 * data->zoom
					* HEIGHT)) + data->move_y;
		data->max_iter += 7;
		allocate_color_table(data);
	}
	else if (button == 5)
	{
		point->zoom_factor = 0.9;
		if (data->max_iter > 20)
		{
			data->max_iter -= 7;
			allocate_color_table(data);
		}
	}
	else
		return (0);
	return (1);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.zoom_factor = 1;
	point.mouse_x = (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH)
		+ data->move_x;
	point.mouse_y = (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT)
		+ data->move_y;
	if (hand_mouse_input(button, data, &point) == 0)
		return (0);
	if (data->color == 3)
		generate_rd_color_table(data->max_iter, data->color_table);
	else
		generate_color_table(data->max_iter, data->color_table, data->color);
	data->zoom *= point.zoom_factor;
	data->move_x = point.mouse_x + (data->move_x - point.mouse_x)
		* point.zoom_factor;
	data->move_y = point.mouse_y + (data->move_y - point.mouse_y)
		* point.zoom_factor;
	draw_fractal(data, data->color_table);
	return (0);
}

void	allocate_color_table(t_data *data)
{
	if (data->color_table != NULL)
		free(data->color_table);
	data->color_table = malloc(sizeof(int) * data->max_iter);
	if (!data->color_table)
	{
		fprintf(stderr, "Error: No se asignó memoria para color_table\n");
		exit(EXIT_FAILURE);
	}
}
