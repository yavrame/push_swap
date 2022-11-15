/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nodes_stk_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:49 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:03:46 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	test_sort(t_stk *stack, void sort(t_stk *stack, int mode),
			  int check(t_stk *stack))
{
	t_stk	*new_lst;
	t_stk	*new_elem;
	int		res;

	new_elem = ft_node_new(stack->value);
	if (!new_elem)
		return (0);
	new_lst = new_elem;
	stack = stack->next;
	while (stack)
	{
		new_elem = ft_node_new(stack->value);
		if (!new_elem)
		{
			ft_clear_stack(&new_lst);
			break ;
		}
		stack = stack->next;
		ft_stack_add_back(&new_lst, new_elem);
	}
	sort(new_lst, 0);
	res = check(new_lst);
	ft_clear_stack(&new_lst);
	return (res);
}

void	sort_three_in_a(t_stk **stack_a)
{
	while (!stk_is_sorted(*stack_a))
	{
		if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
		{
			if (test_sort(*stack_a, c_ra, stk_is_sorted))
				c_ra(*stack_a, 1);
			else
				c_sa(*stack_a, 1);
		}
		else
			c_rra(*stack_a, 1);
	}
}

void	sort_three_in_b(t_stk **stack_b)
{
	while (!stk_is_sorted(*stack_b))
	{
		if ((*stack_b)->next && (*stack_b)->value > (*stack_b)->next->value)
		{
			if (test_sort(*stack_b, c_rb, stk_is_sorted))
				c_rb(*stack_b, 1);
			else
				c_sb(*stack_b, 1);
		}
		else
			c_rrb(*stack_b, 1);
	}
}
