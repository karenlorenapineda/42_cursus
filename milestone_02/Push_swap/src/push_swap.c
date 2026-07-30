/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:54:21 by kpineda-          #+#    #+#             */
/*   Updated: 2025/04/23 01:16:44 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;
	int		*numbers;

	if (ac == 1)
		display_error("", 1);
	count = check_digits(ac, av);
	numbers = arg_parse(ac, av, count);
	if (count <= 1 || check_duplicates_bf(numbers, count))
	{
		free(numbers);
		if (count == 1)
			display_error("", 1);
		display_error("Error\n", 1);
	}
	init_stack(&stack_a, &stack_b, numbers, count);
	sort(&stack_a, &stack_b, numbers, count);
	free(numbers);
	free_stack(&stack_a);
	return (0);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int c)
{
	int		i;
	t_node	*tmp;

	stack_b->head = NULL;
	stack_a->head = NULL;
	stack_b->size = 0;
	stack_a->size = 0;
	i = c - 1;
	while (i >= 0)
	{
		push_stack(stack_a, 0, nb[i]);
		i--;
	}
	insertion_sort(nb, c);
	tmp = stack_a->head;
	while (tmp)
	{
		tmp->s_index = index_of(tmp->data, nb);
		tmp = tmp->next;
	}
}
