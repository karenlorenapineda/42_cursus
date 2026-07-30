/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:56:59 by kpineda-          #+#    #+#             */
/*   Updated: 2025/04/23 03:18:52 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				data;
	int				s_index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}			t_stack;

int		*arg_parse(int ac, char **av, int len);
int		check_digits(int ac, char **av);
void	check_range(char **s_numbers, int *numbers);

void	init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int c);
void	push_stack(t_stack *stack, int index, int data);
int		pop_stack(t_stack *stack);

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *stack1, t_stack *stack2, char x, bool b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack	*stack, char x, bool b);
void	swap_both(t_stack *stack1, t_stack *stack2);
void	rotate(t_stack *stack, char x, bool b);
void	swap(t_stack *stack, char x, bool b);

void	sort(t_stack *stack_a, t_stack	*stack_b, int *numbers, int len);
void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int i);
void	k_sort1(t_stack *stack_a, t_stack *stack_b, int len);
void	k_sort2(t_stack *stack_a, t_stack *stack_b, int len);
void	simple_sort(t_stack *stack, int len);
int		is_sort(t_stack *stack);

int		count_r(t_node *stack, int i);
int		get_min_i(t_stack *stack);
void	free_stack(t_stack *stack);
bool	ft_isspace(int32_t c);
int64_t	ft_atoll(const char *str);
void	free_2d(char **arr);
void	display_error(char *error_msg, bool yeet);
int		check_duplicates_bf(int	*numbers, int count);
int		ft_sqrt(int num);
void	insertion_sort(int array[], int n);
int		index_of(int n, int *arr);

#endif