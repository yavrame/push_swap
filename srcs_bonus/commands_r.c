/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:47:49 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 00:49:45 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	c_rr(t_stk *stk_a, t_stk *stk_b, int print)
{
	c_ra(stk_a, 0);
	c_rb(stk_b, 0);
	if (print)
		ft_putstr_fd("rr", 1);
}

void	c_rrr(t_stk *stk_a, t_stk *stk_b, int print)
{
	c_rra(stk_a, 0);
	c_rrb(stk_b, 0);
	if (print)
		ft_putstr_fd("rrr", 1);
}

void	c_ss(t_stk *stk_a, t_stk *stk_b, int print)
{
	c_sa(stk_a, 0);
	c_sb(stk_b, 0);
	if (print)
		ft_putstr_fd("ss", 1);
}
