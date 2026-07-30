/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:07:56 by kpineda-          #+#    #+#             */
/*   Updated: 2025/04/23 01:17:07 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack, int index, int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->data = data;
	tmp->s_index = index;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}

int	pop_stack(t_stack *stack)
{
	t_node	*top;
	int		data;

	if (!stack->head)
		exit(1);
	top = stack->head;
	data = top->data;
	stack->head = top->next;
	free(top);
	top = NULL;
	stack->size--;
	return (data);
}
