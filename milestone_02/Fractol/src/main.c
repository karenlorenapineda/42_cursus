/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:01:41 by kpineda-          #+#    #+#             */
/*   Updated: 2025/03/15 22:29:43 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	set_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract_ol");
	data->img.img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.img_pixels_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel,
			&data->img.line_len,
			&data->img.endian);
	data->zoom = 0.8;
	data->move_x = 0;
	data->move_y = 0;
	data->max_iter = 200;
	data->color_table = NULL;
	allocate_color_table(data);
	if (data->color == 3)
		generate_rd_color_table(data->max_iter, data->color_table);
	else
		generate_color_table(data->max_iter, data->color_table, data->color);
}

void	check_color(t_data *data, char *av, int j)
{
	if (!av)
		data->color = 0;
	else if (ft_strcmp(av, "r") == 0)
		data->color = 0;
	else if (ft_strcmp(av, "g") == 0)
		data->color = 1;
	else if (ft_strcmp(av, "b") == 0)
		data->color = 2;
	else if (ft_strcmp(av, "a") == 0)
		data->color = 3;
	else if (j == 0)
	{
		fprintf(stderr, "Colors: [r/g/b/a]\n");
		exit(0);
	}
}

int	check_julia_set(t_data *data, char **av, int ac)
{
	const double	julia_re_vals[4] = {-0.7, -0.8, -0.4, 0.355};
	const double	julia_im_vals[4] = {0.27015, 0.156, 0.6, 0.355};
	int				index;

	index = ft_atoi(av[2]);
	if (index < 0 || index > 3)
		return (ft_printf("Julia sets: [0/1/2/3]\n"), 0);
	data->julia_re = julia_re_vals[index];
	data->julia_im = julia_im_vals[index];
	if (ac > 3)
		check_color(data, av[3], 0);
	return (1);
}

void	check_fractol_name(t_data *data, char **av, int ac)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->fractal = 1;
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		data->fractal = 0;
		data->julia_re = -0.7;
		data->julia_im = 0.27015;
		data->color = 0;
		if (ac > 2)
		{
			if (ft_strcmp(av[2], "r") == 0 || ft_strcmp(av[2], "g") == 0
				|| ft_strcmp(av[2], "b") == 0 || ft_strcmp(av[2], "a") == 0)
				check_color(data, av[2], 0);
			else if (check_julia_set(data, av, ac) == 0)
				check_color(data, av[2], 0);
		}
	}
	else if (ft_strcmp(av[1], "tricorn") == 0)
		data->fractal = 2;
	else
	{
		ft_printf("Valid fractals: [julia/mandelbrot/tricorn]\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1 && ac < 4)
		check_fractol_name(&data, av, ac);
	else if (ac > 1 && ac < 5 && ft_strcmp(av[1], "julia") == 0)
		check_fractol_name(&data, av, ac);
	else
	{
		ft_printf("Valid arguments: ./fractol [m/j/t] [r/g/b/]\n");
		return (1);
	}
	if ((ac == 2 || ac == 3) && ft_strcmp(av[1], "julia") != 0)
		check_color(&data, av[2], 0);
	set_data(&data);
	draw_fractal(&data, data.color_table);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_hook(data.win, DestroyNotify, NoEventMask, (void *)exit_program, &data);
	mlx_loop(data.mlx);
	return (0);
}
