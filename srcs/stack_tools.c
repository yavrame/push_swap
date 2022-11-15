/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:31 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:07:58 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_stk ***stack)
{
	*stack = malloc (sizeof (t_stk *));
	if (!*stack)
		exit(1);
	**stack = NULL;
}

t_stk	*ft_stack_find_last_node(t_stk *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_stack_add_back(t_stk **stack, t_stk *new_node)
{
	t_stk	*last_node;

	if (stack)
	{
		if (*stack)
		{
			last_node = ft_stack_find_last_node(*stack);
			last_node->next = new_node;
		}
		else
			*stack = new_node;
	}
}

t_stk	*ft_node_new(int content)
{
	t_stk	*struc;

	struc = malloc(sizeof(t_stk));
	if (!struc)
		return (NULL);
	struc->value = content;
	struc->next = NULL;
	return (struc);
}

void	ft_stkpush_front(t_stk **lst, t_stk *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
