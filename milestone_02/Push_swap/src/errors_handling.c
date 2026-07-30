/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:18:06 by kpineda-          #+#    #+#             */
/*   Updated: 2025/04/23 02:56:34 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(char *error_msg, bool yeet)
{
	write(2, error_msg, ft_strlen(error_msg));
	if (yeet == true)
		exit(EXIT_FAILURE);
}

int	check_digits(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
				return (-1);
			if (ft_isdigit(av[i][j]) && (av[i][j + 1] == ' ' || av[i][j
				+ 1] == '\0'))
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_range(char **s_numbers, int *numbers)
{
	int	i;

	i = 0;
	while (s_numbers[i])
	{
		if (ft_atoll(s_numbers[i]) > INT_MAX \
			|| ft_atoll(s_numbers[i]) < INT_MIN \
			|| ft_strlen(s_numbers[i]) > 11)
		{
			free_2d(s_numbers);
			free(numbers);
			display_error("Error\n", 1);
		}
		i++;
	}
}

int	*arg_parse(int ac, char **av, int count)
{
	char	**s_numbers;
	int		*numbers;
	int		i;
	int		j;
	int		k;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < ac)
	{
		s_numbers = ft_split(av[i], ' ');
		if (!s_numbers)
			display_error("", 1);
		check_range(s_numbers, numbers);
		k = 0;
		while (s_numbers[k])
			numbers[j++] = ft_atoi(s_numbers[k++]);
		free_2d(s_numbers);
	}
	return (numbers);
}
