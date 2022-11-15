/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nodes_stk_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:16 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:07:45 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	check_is_at_min(t_stk *stack)
{
	t_stk	*tmp;
	int		head;

	tmp = stack;
	head = tmp->value;
	while (tmp)
	{
		if (tmp->value < head)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

char	check_is_bigger(t_stk *stack, int num)
{
	t_stk	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value > num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	merge_b_to_a(t_stk **stack_a, t_stk **stack_b, size_t size_b)
{
	while (size_b > 0)
	{
		if ((*stack_a)->value > (*stack_b)->value)
		{
			c_pa(stack_a, stack_b, 1);
			size_b--;
		}
		else if (check_is_at_min(*stack_a) \
				 && check_is_bigger(*stack_a, (*stack_b)->value))
		{
			c_pa(stack_a, stack_b, 1);
			size_b--;
		}
		else
			c_ra(*stack_a, 1);
	}
}

void	less_five_sort(t_stk **stack_a, t_stk **stack_b, size_t size_a)
{
	size_t	size_b;

	while (!stk_is_sorted(*stack_a) && size_a > 3)
	{
		c_pb(stack_a, stack_b, 1);
		size_a--;
	}
	sort_three_in_a(stack_a);
	sort_three_in_b(stack_b);
	size_b = ft_stk_size(*stack_b);
	merge_b_to_a(stack_a, stack_b, size_b);
	while (!stk_is_sorted(*stack_a))
		c_ra(*stack_a, 1);
}
