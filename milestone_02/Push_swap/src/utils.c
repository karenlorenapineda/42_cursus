/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:05:26 by kpineda-          #+#    #+#             */
/*   Updated: 2025/04/23 01:17:15 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_isspace(int32_t c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
		c == '\v' || c == '\f' || c == '\r')
		return (true);
	return (false);
}

int64_t	ft_atoll(const char *str)
{
	size_t	i;
	int32_t	sign;
	int64_t	out;

	i = 0;
	sign = 1;
	out = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		out = (out * 10) + (str[i++] - '0');
	return (out * sign);
}

void	free_2d(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr && arr[i])
		{
			if (arr[i] != NULL)
			{
				free(arr[i]);
				arr[i] = NULL;
			}
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

int	check_duplicates_bf(int	*numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_sqrt(int num)
{
	int	i;

	if (num < 4)
		return (1);
	i = 2;
	while (i * i < num)
		i++;
	if (i * i > num)
	{
		if ((i * i - num) < ((i - 1) * (i - 1) + (-num)))
			return (i);
	}
	return (i - 1);
}
