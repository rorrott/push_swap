/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:09:47 by rtorres           #+#    #+#             */
/*   Updated: 2024/07/30 14:27:57 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quicksort_stack_three_a_b(t_lists *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		three_num_sort_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack, 0);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				sa(stack, 0);
			else if (len++)
				pa(stack, 0);
		}
	}
}

int	sort_b_three(t_lists *stack, int len)
{
	if (len == 1)
		pa(stack, 0);
	else if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack, 0);
		while (len--)
			pa(stack, 0);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				sa(stack, 0);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1])
				|| (len == 3 && stack->b[0] > stack->b[2]))
				len = ft_push(stack, len, 1);
			else
				sb(stack, 0);
		}
	}
	return (0);
}

int	median_numbers(int *midpoint, int *stack, int size)
{
	int	i;
	int	*tmp_stack;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	tmp_sort(tmp_stack, size);
	*midpoint = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}

int	quicksort_stack_a(t_lists *stack, int len, int count_rotate)
{
	int	num;
	int	midpoint;

	if (check_sorted(stack->a, len, 0) == 1)
		return (1);
	num = len;
	if (len <= 3)
	{
		quicksort_stack_three_a_b(stack, len);
		return (1);
	}
	if (!median_numbers(&midpoint, stack->a, len))
		return (0);
	while (len != num / 2 + num % 2)
	{
		if (stack->a[0] < midpoint && (len--))
			pb(stack, 0);
		else if (++count_rotate)
			ra(stack, 0);
	}
	while (num / 2 + num % 2 != stack->size_a && count_rotate--)
		rra(stack, 0);
	return (quicksort_stack_a(stack, num / 2 + num % 2, 0)
		&& quicksort_stack_b(stack, num / 2, 0));
	return (1);
}

int	quicksort_stack_b(t_lists *stack, int len, int count_rotate)
{
	int	midpoint;
	int	num;

	if (check_sorted(stack->b, len, 1) == 1)
		while (len--)
			pa(stack, 0);
	if (len <= 3)
	{
		sort_b_three(stack, len);
		return (1);
	}
	num = len;
	if (!median_numbers(&midpoint, stack->b, len))
		return (0);
	while (len != num / 2)
	{
		if (stack->b[0] >= midpoint && len--)
			pa(stack, 0);
		else if (++count_rotate)
			rb(stack, 0);
	}
	while (num / 2 != stack->size_b && count_rotate--)
		rrb(stack, 0);
	return (quicksort_stack_a(stack, num / 2 + num % 2, 0)
		&& quicksort_stack_b(stack, num / 2, 0));
}
