/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:19:56 by kpineda-          #+#    #+#             */
/*   Updated: 2025/04/23 01:45:54 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int array[], int n)
{
	int	element;
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		element = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > element)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = element;
		i++;
	}
}

int	index_of(int n, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != n)
		i++;
	return (i);
}
