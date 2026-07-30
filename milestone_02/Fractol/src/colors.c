/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:31:00 by kpineda-          #+#    #+#             */
/*   Updated: 2025/03/08 23:27:25 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	generate_color_table(int iter, int *color_table, int colortype)
{
	int		r;
	int		g;
	double	t;
	int		i;

	i = 0;
	g = 0;
	while (i < iter)
	{
		t = (double)i / iter;
		r = (int)(sin(t * 3.14) * 255);
		if (r > 100)
			g = r / 5;
		if (colortype == 0)
			color_table[i] = (r << 16) | (g << 8) | 0;
		if (colortype == 1)
			color_table[i] = (0 << 16) | (r << 8) | g;
		if (colortype == 2)
			color_table[i] = (0 << 16) | (g << 8) | r;
		i++;
	}
}

void	generate_rd_color_table(int iter, int *color_table)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		i;

	i = 0;
	while (i < iter)
	{
		t = (double)i / iter;
		r = (int)((cos(t * 3.14 * 6) * 0.5 + 0.5) * 255);
		g = (int)((sin(t * 3.14 * 20) * 0.5 + 0.5) * 255);
		b = (int)((cos(t * 3.14 * 25 + 1) * 0.5 + 0.5) * 255);
		if (r < 100)
			r += 100;
		if (g < 100)
			g += 80;
		if (b < 100)
			b += 100;
		color_table[i] = (r << 16) | (i * 30) % 256 | (b << 8);
		i++;
	}
}
