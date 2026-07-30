/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:03:37 by kpineda-          #+#    #+#             */
/*   Updated: 2025/03/08 23:04:33 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "./libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# define ESCAPE_RADIUS 4.0

# define WIDTH 600
# define HEIGHT 600

# define ESC_RAD 4

/* Structs */
typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_point
{
	float	mouse_x;
	float	mouse_y;
	int		x;
	int		y;
	float	zoom_factor;
}			t_point;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		fractal;
	float	zoom;
	float	move_x;
	float	move_y;
	t_img	img;
	float	julia_re;
	float	julia_im;
	float	max_iter;
	int		color;
	int		*color_table;
}			t_data;

typedef struct t_data
{
	double	julia_re;
	double	julia_im;
}			t_julia_set;

/* Utils */
float	abs_float(float x);
int		ft_strcmp(const char *s1, const char *s2);
void	put_pixel(t_data *data, int x, int y, int color);
int		set_color(int iter, int *color_table, t_data *data);
void	draw_fractal_row(t_data *data, int y, int *color_table);
void	allocate_color_table(t_data *data);

/* Input */
int		handle_input(int keysym, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
void	exit_program(t_data *data);

/* Fractals */
int		julia(double cre, double cim, t_data *data);
int		mandelbrot(double zr, double zi, t_data *data);
int		tricorn(double cre, double cim, t_data *data);
void	draw_fractal(t_data *data, int *color_table);

/* Colors */
void	generate_color_table(int iter, int *color_table, int colortp);
void	generate_rd_color_table(int iter, int *color_table);

#endif
