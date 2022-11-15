/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:26:53 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:08:23 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	c_sa(t_stk *stk, int print)
{
	t_stk	*tmp;
	int		tmp_val;

	tmp = stk;
	if (tmp && tmp->next)
	{
		tmp_val = tmp->next->value;
		tmp->next->value = tmp->value;
		tmp->value = tmp_val;
	}
	if (print)
		ft_putstr_fd("sa", 1);
}

void	c_pa(t_stk **stk_a, t_stk **stk_b, int print)
{
	t_stk	*tmp;

	if (*stk_b)
	{
		ft_stkpush_front(stk_a, ft_node_new((*stk_b)->value));
		tmp = *stk_b;
		*stk_b = (*stk_b)->next;
		free(tmp);
		tmp = 0;
	}
	if (print)
		ft_putstr_fd("pa", 1);
}

void	c_ra(t_stk *stk, int print)
{
	t_stk	*tmp;
	int		tmp_val;

	tmp = stk;
	if (tmp)
	{
		tmp_val = tmp->value;
		while (tmp->next)
		{
			tmp->value = tmp->next->value;
			tmp = tmp->next;
		}
		tmp->value = tmp_val;
	}
	if (print)
		ft_putstr_fd("ra", 1);
}

void	c_rra(t_stk *stack, int print)
{
	t_stk	*tmp;
	int		tmp_val;
	int		last_val;

	tmp = stack;
	if (tmp)
	{
		last_val = tmp->value;
		while (tmp->next)
			tmp = tmp->next;
		last_val = tmp->value;
		tmp = stack;
		tmp_val = tmp->value;
		tmp->value = last_val;
		while (tmp->next)
		{
			tmp = tmp->next;
			last_val = tmp->value;
			tmp->value = tmp_val;
			tmp_val = last_val;
		}
	}
	if (print)
		ft_putstr_fd("rra", 1);
}
