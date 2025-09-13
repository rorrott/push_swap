/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:25:29 by rtorres           #+#    #+#             */
/*   Updated: 2024/07/30 14:23:49 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../.libft/libft.h"
# include "../.libft/printf/ft_printf.h"

typedef struct s_lists
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_lists;

void	push_swap(char **av);
void	sa(t_lists *stack, int num);
void	sb(t_lists *stack, int num);
void	ss(t_lists *stack, int num);
void	pb(t_lists *stack, int num);
void	pa(t_lists *stack, int num);
void	ra(t_lists *stack, int num);
void	rb(t_lists *stack, int num);
void	rr(t_lists *stack, int num);
void	rra(t_lists *stack, int num);
void	rrb(t_lists *stack, int num);
void	rrr(t_lists *stack, int num);
void	print_error(int *stack);
void	is_doubles(int *stack, int size);
int		check_sorted(int *stack, int size, int order);
void	tmp_sort(int *stack_tmp, int size);
void	three_num_sort_a(t_lists *stack);
int		sort(t_lists *stack, int size);
int		ft_push(t_lists *stack, int len, int push);
void	quicksort_stack_three_a_b(t_lists *stack, int len);
int		sort_b_three(t_lists *stack, int len);
int		median_numbers(int *midpoint, int *stack, int size);
int		quicksort_stack_a(t_lists *stack, int len, int count_rotate);
int		quicksort_stack_b(t_lists *stack, int len, int count_rotate);
int		ps_atoi(char *str, int *stack);
int		push_swap_len(char **str);

#endif