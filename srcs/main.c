/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:29 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:06:41 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stk_a(t_stk **stack_a, t_stk **stack_b)
{
	int	stk_a_size;

	stk_a_size = ft_stk_size(*stack_a);
	if (stk_a_size == 1)
		return ;
	if (stk_a_size <= 5)
		less_five_sort(stack_a, stack_b, stk_a_size);
	else
		more_five_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stk	**stack_a;
	t_stk	**stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	fill_stk_a(argc, argv, stack_a, stack_b);
	sort_stk_a(stack_a, stack_b);
	ft_clear_stack(stack_a);
	ft_clear_stack(stack_b);
	free (stack_a);
	free (stack_b);
	return (0);
}
