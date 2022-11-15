/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:43 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:05:29 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_min_med_max(t_stk **stk_a, t_specs *specs)
{
	int		stk_a_size;
	int		*array;

	stk_a_size = ft_stk_size(*stk_a);
	init_array(&array, stk_a_size);
	fill_array(array, stk_a, stk_a_size);
	sort_array(array, stk_a_size);
	specs->min = array[0];
	specs->med = array[stk_a_size / 2 - 1];
	specs->max = array[stk_a_size - 1];
	free(array);
}

void	rotate_min_node_up(t_stk *stack_a, t_specs *params)
{
	t_stk	*tmp;
	int		i;

	tmp = stack_a;
	i = 0;
	while (tmp && tmp->value != params->min && ++i)
		tmp = tmp->next;
	if (i <= params->size_a / 2)
	{
		while (i > 0)
		{
			c_ra(stack_a, 1);
			i--;
		}
	}
	else
	{
		while (params->size_a - i > 0)
		{
			c_rra(stack_a, 1);
			i++;
		}
	}
}

void	push_to_stk_b(t_stk **stk_a, t_stk **stk_b, t_specs *specs)
{
	while (ft_stk_size(*stk_a) > 2)
	{
		if (((*stk_a)->value == specs->min)
			|| ((*stk_a)->value == specs->max))
			c_ra(*stk_a, 1);
		else
		{
			c_pb(stk_a, stk_b, 1);
			if ((*stk_b)->value >= specs->med)
				c_rb(*stk_b, 1);
		}
	}
}

void	more_five_sort(t_stk **stack_a, t_stk **stack_b)
{
	t_specs		specs;

	specs.size_a = ft_stk_size(*stack_a);
	if (stk_is_sorted(*stack_a))
		return ;
	find_min_med_max(stack_a, &specs);
	push_to_stk_b(stack_a, stack_b, &specs);
	while (ft_stk_size(*stack_b))
		exec_next_command(stack_a, stack_b, &specs);
	if (!stk_is_sorted(*stack_a))
	{
		specs.size_a = ft_stk_size(*stack_a);
		rotate_min_node_up(*stack_a, &specs);
	}
}
