/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:26:43 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:04:43 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_array(int **array, int array_size)
{
	*array = malloc(sizeof(int) * array_size);
	if (!*array)
		exit(2);
}

void	fill_array(int *array, t_stk **stk_a, int stk_a_size)
{
	int		i;
	t_stk	*tmp;

	tmp = *stk_a;
	i = 0;
	while (i < stk_a_size)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
}

void	sort_array(int *array, int arr_size)
{
	int		i;
	int		circles;
	int		tmp;

	circles = arr_size;
	while (circles > 0)
	{
		i = 0;
		while (i < arr_size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
			i++;
		}
		circles--;
	}
}
