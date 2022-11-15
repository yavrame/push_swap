/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:52:03 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 00:52:04 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char)*s1 - (unsigned char)*s2) != 0)
			|| *s1 == '\0' || *s2 == '\0')
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1 ++;
		s2 ++;
		i ++;
	}
	return (0);
}

int	exec_command(char *str, t_stk **stk_a, t_stk **stk_b)
{
	if (ft_strncmp("sa", str, 2) == 0)
		c_sa(*stk_a, 0);
	else if (ft_strncmp("sb", str, 2) == 0)
		c_sb(*stk_b, 0);
	else if (ft_strncmp("ss", str, 2) == 0)
		c_ss(*stk_a, *stk_b, 0);
	else if (ft_strncmp("pa", str, 2) == 0)
		c_pa(stk_a, stk_b, 0);
	else if (ft_strncmp("pb", str, 2) == 0)
		c_pb (stk_a, stk_b, 0);
	else if (ft_strncmp("ra", str, 2) == 0)
		c_ra(*stk_a, 0);
	else if (ft_strncmp("rb", str, 2) == 0)
		c_rb(*stk_b, 0);
	else if (ft_strncmp("rra", str, 3) == 0)
		c_rra(*stk_a, 0);
	else if (ft_strncmp("rrb", str, 3) == 0)
		c_rrb(*stk_b, 0);
	else if (ft_strncmp("rrr", str, 3) == 0)
		c_rrr(*stk_a, *stk_b, 0);
	else if (ft_strncmp("rr", str, 2) == 0)
		c_rr(*stk_a, *stk_b, 0);
	else
		return (0);
	return (1);
}

void	check_solution(t_stk **stack_a, t_stk **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (!exec_command(str, stack_a, stack_b))
		{
			ft_putstr_fd ("Error!", 1);
			free(str);
			return ;
		}
		free(str);
		str = get_next_line(0);
	}
	if (stk_is_sorted(*stack_a) && !ft_stk_size(*stack_b))
		ft_putstr_fd ("OK", 1);
	else
		ft_putstr_fd ("KO", 1);
}

int	main(int argc, char **argv)
{
	t_stk	**stack_a;
	t_stk	**stack_b;

	init_stk(&stack_a);
	init_stk(&stack_b);
	fill_stk_a(argc, argv, stack_a, stack_b);
	check_solution(stack_a, stack_b);
	ft_clear_stack(stack_a);
	ft_clear_stack(stack_b);
	free (stack_a);
	free (stack_b);
	return (0);
}
