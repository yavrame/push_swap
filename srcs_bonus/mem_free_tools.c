/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:48:24 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 00:48:25 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	stk_mem_free_and_exit(t_stk **stack_a, \
						   t_stk **stack_b, int print_error)
{
	if (print_error)
		ft_putstr_fd("Error!", 1);
	free (stack_a);
	free (stack_b);
	exit (2);
}

void	ft_clear_stack(t_stk **stack)
{
	t_stk	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
