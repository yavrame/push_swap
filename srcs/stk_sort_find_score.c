/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_sort_find_score.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:39 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:05:08 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calc_steps_a(t_stk *stk_a, t_rotate *rotate,
				  t_specs *specs, int value)
{
	int	i;
	int	min;

	min = INT32_MAX;
	i = 0;
	while (stk_a)
	{
		if (stk_a->value < min && stk_a->value > value)
		{
			min = stk_a->value;
			rotate->direction_a = 1;
			rotate->steps_a = specs->size_a - i;
			if (i <= specs->size_a / 2)
			{
				rotate->direction_a = 0;
				rotate->steps_a = i;
			}
		}
		if (!stk_a->next)
			break ;
		stk_a = stk_a->next;
		i++;
	}
}

void	find_min_score_node(t_stk *stack_b, t_specs *specs)
{
	specs->min_rotate_score.steps_a = INT32_MAX;
	specs->min_rotate_score.steps_b = INT32_MAX;
	while (stack_b)
	{
		if (stack_b->rotate.steps_a + stack_b->rotate.steps_b
			< specs->min_rotate_score.steps_a + specs->min_rotate_score.steps_b)
		{
			specs->min_rotate_score.steps_a = stack_b->rotate.steps_a;
			specs->min_rotate_score.steps_b = stack_b->rotate.steps_b;
			specs->min_rotate_score.direction_a = stack_b->rotate.direction_a;
			specs->min_rotate_score.direction_b = stack_b->rotate.direction_b;
		}
		if (!stack_b->next)
			break ;
		stack_b = stack_b->next;
	}
}

void	calc_score(t_stk **stack_a, t_stk **stack_b,
				t_specs *specs)
{
	t_stk	*tmp;
	int		i;

	tmp = *stack_b;
	i = 0;
	while (tmp)
	{
		if (i <= specs->size_b / 2)
		{
			tmp->rotate.direction_b = 0;
			tmp->rotate.steps_b = i;
			calc_steps_a(*stack_a, &tmp->rotate, specs, tmp->value);
		}
		else
		{
			tmp->rotate.direction_b = 1;
			tmp->rotate.steps_b = specs->size_b - i;
			calc_steps_a(*stack_a, &tmp->rotate, specs, tmp->value);
		}
		if (!tmp->next)
			break ;
		tmp = tmp->next;
		i++;
	}
	find_min_score_node(*stack_b, specs);
}
