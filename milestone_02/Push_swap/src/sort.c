/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:48:09 by kpineda-          #+#    #+#             */
/*   Updated: 2025/04/23 03:00:55 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rot_sort(t_stack *stack, int min_s_i)
{
	int	a;
	int	b;
	int	c;

	(void)min_s_i;
	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}

void	simple_sort(t_stack *stack, int len)
{
	int	min_s_i;
	int	r;

	if (is_sort(stack))
		return ;
	min_s_i = get_min_i(stack);
	r = count_r(stack->head, min_s_i);
	if (is_rot_sort(stack, min_s_i))
	{
		if (r < len - r)
			rotate(stack, 'a', true);
		else
			reverse_rotate(stack, 'a', true);
	}
	else
	{
		swap(stack, 'a', true);
		if (is_sort(stack))
			return ;
		if (r < len - r)
			rotate(stack, 'a', true);
		else
			reverse_rotate(stack, 'a', true);
	}
}

void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	min_i;
	int	iter;
	int	n;

	iter = 0;
	n = len;
	while (iter++ < n - 3)
	{
		min_i = get_min_i(stack_a);
		if (count_r(stack_a->head, min_i) <= n - min_i - \
			count_r(stack_a->head, min_i))
			while (stack_a->head->s_index != min_i)
				rotate(stack_a, 'a', true);
		else
			while (stack_a->head->s_index != min_i)
				reverse_rotate(stack_a, 'a', true);
		if (is_sort(stack_a) && stack_b->size == 0)
			return ;
		push(stack_b, stack_a, 'b', true);
		len--;
	}
	simple_sort(stack_a, len);
	iter = 0;
	while (iter++ < n - 3)
		push(stack_a, stack_b, 'a', true);
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(len) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->s_index <= i)
		{
			push(stack_b, stack_a, 'b', true);
			rotate(stack_b, 'b', true);
			i++;
		}
		else if (stack_a->head->s_index <= i + range)
		{
			push(stack_b, stack_a, 'b', true);
			i++;
		}
		else
			rotate(stack_a, 'a', true);
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	rb_count;
	int	rrb_count;

	while (len - 1 >= 0)
	{
		rb_count = count_r(stack_b->head, len - 1);
		rrb_count = (len + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->s_index != len - 1)
				rotate(stack_b, 'b', true);
			push(stack_a, stack_b, 'a', true);
			len--;
		}
		else
		{
			while (stack_b->head->s_index != len - 1)
				reverse_rotate(stack_b, 'b', true);
			push(stack_a, stack_b, 'a', true);
			len--;
		}
	}
}
