/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:26:57 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:08:35 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	c_sb(t_stk *stk, int print)
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
		ft_putstr_fd("sb", 1);
}

void	c_pb(t_stk **stk_a, t_stk **stk_b, int print)
{
	t_stk	*tmp;

	if (*stk_a)
	{
		ft_stkpush_front(stk_b, ft_node_new((*stk_a)->value));
		tmp = *stk_a;
		*stk_a = (*stk_a)->next;
		free(tmp);
		tmp = 0;
	}
	if (print)
		ft_putstr_fd("pb", 1);
}

void	c_rb(t_stk *stk, int print)
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
		ft_putstr_fd("rb", 1);
}

void	c_rrb(t_stk *stk, int print)
{
	t_stk	*tmp;
	int		tmp_val;
	int		last_val;

	tmp = stk;
	if (tmp)
	{
		last_val = tmp->value;
		while (tmp->next)
			tmp = tmp->next;
		last_val = tmp->value;
		tmp = stk;
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
		ft_putstr_fd("rrb", 1);
}
