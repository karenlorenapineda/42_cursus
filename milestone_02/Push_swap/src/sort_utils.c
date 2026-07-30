/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:32:45 by kpineda-          #+#    #+#             */
/*   Updated: 2025/04/23 01:53:32 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_i(t_stack *stack)
{
	t_node	*current;
	int		min_i;

	current = stack->head;
	min_i = current->s_index;
	while (current->next)
	{
		current = current->next;
		if (current->s_index < min_i)
			min_i = current->s_index;
	}
	return (min_i);
}

int	count_r(t_node *stack, int i)
{
	int	counter;

	counter = 0;
	while (stack && stack->s_index != i)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

int	is_sort(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	while (stack)
		pop_stack(stack);
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *numbers, int len)
{
	if (is_sort(stack_a))
	{
		free(numbers);
		free_stack(stack_a);
		display_error("", 1);
	}
	else if (len == 2)
		swap(stack_a, 'a', true);
	else if (len == 3)
		simple_sort(stack_a, len);
	else if (len <= 7)
		s_insertion_sort(stack_a, stack_b, len);
	else if (len > 7)
	{
		k_sort1(stack_a, stack_b, len);
		k_sort2(stack_a, stack_b, len);
	}
	else
		display_error("", 1);
}
