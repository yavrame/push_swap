/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_sort_exec_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:34 by emarion           #+#    #+#             */
/*   Updated: 2022/02/20 18:27:35 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_moves(t_stk **stack_a, t_specs *params)
{
	while (params->min_rotate_score.steps_a > 0)
	{
		if (params->min_rotate_score.direction_a)
			c_rra(*stack_a, 1);
		else
			c_ra(*stack_a, 1);
		params->min_rotate_score.steps_a--;
	}
}

void	b_moves(t_stk **stack_b, t_specs *params)
{
	while (params->min_rotate_score.steps_b > 0)
	{
		if (params->min_rotate_score.direction_b)
			c_rrb(*stack_b, 1);
		else
			c_rb(*stack_b, 1);
		params->min_rotate_score.steps_b--;
	}
}

void	joint_moves(t_stk **stack_a, t_stk **stack_b, t_specs *specs)
{
	while (specs->min_rotate_score.steps_a > 0
		   && specs->min_rotate_score.steps_b > 0)
	{
		if (specs->min_rotate_score.direction_a
			== specs->min_rotate_score.direction_b)
		{
			if (specs->min_rotate_score.direction_a)
				c_rrr(*stack_a, *stack_b, 1);
			else
				c_rr(*stack_a, *stack_b, 1);
			specs->min_rotate_score.steps_a--;
			specs->min_rotate_score.steps_b--;
		}
		else
			break ;
	}
}

void	exec_next_command(t_stk **stack_a, t_stk **stack_b, t_specs *specs)
{
	specs->size_a = ft_stk_size(*stack_a);
	specs->size_b = ft_stk_size(*stack_b);
	calc_score(stack_a, stack_b, specs);
	joint_moves(stack_a, stack_b, specs);
	a_moves(stack_a, specs);
	b_moves(stack_b, specs);
	c_pa(stack_a, stack_b, 1);
}
