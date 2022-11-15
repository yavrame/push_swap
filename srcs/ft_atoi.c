/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:22 by emarion           #+#    #+#             */
/*   Updated: 2022/02/20 18:27:23 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_atoi	atoi_error_found(t_atoi res)
{
	res.error = 1;
	return (res);
}

t_atoi	ft_atoi(char *str, t_atoi res)
{
	int				sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str ++;
	}
	else if (*str == '+')
		str ++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (atoi_error_found(res));
		res.value = (10 * res.value) + *str - '0';
		if (res.value * sign < INT_MIN || res.value * sign > INT_MAX)
			return (atoi_error_found(res));
		str ++;
	}
	res.value = (res.value * sign);
	return (res);
}
