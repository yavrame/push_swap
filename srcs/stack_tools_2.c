/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:46:46 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:03:12 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	dublicates_on_stack(t_stk **stack, int new_node_value)
{
	t_stk	*next_stack_node;

	next_stack_node = *stack;
	while (next_stack_node)
	{
		if (next_stack_node->value == new_node_value)
			return (1);
		next_stack_node = next_stack_node->next;
	}
	return (0);
}

int	stk_is_sorted(t_stk *stk)
{
	t_stk	*tmp;
	int		current;

	tmp = stk;
	current = INT32_MIN;
	while (tmp)
	{
		if (tmp->value < current)
			return (0);
		current = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

int	ft_stk_size(t_stk *lst)
{
	int		i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
