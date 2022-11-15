/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stk_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:27:03 by emarion           #+#    #+#             */
/*   Updated: 2022/02/20 18:27:03 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fill_stack(int argc, char **argv, t_stk **stack)
{
	int		i;
	t_atoi	atoi_res;

	i = 1;
	while (i < argc)
	{
		atoi_res.error = 0;
		atoi_res.value = 0;
		atoi_res = ft_atoi(argv[i], atoi_res);
		if (atoi_res.error || dublicates_on_stack(stack, atoi_res.value))
		{
			ft_clear_stack(stack);
			return (0);
		}
		ft_stack_add_back(stack, ft_node_new(atoi_res.value));
		i ++;
	}
	return (1);
}

int	splited_size(char **words)
{
	int	size;

	size = 0;
	while (*words)
	{
		words++;
		size++;
	}
	return (size);
}

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	char	*mem;
//	size_t	i;
//	size_t	len1;
//	size_t	len2;
//
//	if (!(s1 && s2))
//		return (NULL);
//	i = -1;
//	len1 = ft_strlen(s1);
//	len2 = ft_strlen(s2);
//	mem = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
//	if (!mem)
//		exit (2);
//	while (++ i < len1)
//		mem[i] = s1[i];
//	i = -1;
//	while (++ i < len2)
//		mem[len1 + i] = s2[i];
//	mem[len1 + i] = '\0';
//	return (mem);
//}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
}

void	fill_stk_a(int argc, char **argv, t_stk **stack_a,
				t_stk **stack_b)
{
	char	**mod_argv;
	char	*program_name;
	int		mod_argc;

	if (argc == 1)
		stk_mem_free_and_exit(stack_a, stack_b, 0);
	if (argc == 2)
	{
		program_name = ft_strjoin("push_swap ", argv[1]);
		mod_argv = ft_split(program_name, ' ');
		free(program_name);
		mod_argc = splited_size(mod_argv);
		if (!fill_stack(mod_argc, mod_argv, stack_a))
		{
			free_argv(mod_argv);
			stk_mem_free_and_exit(stack_a, stack_b, 1);
		}
		free_argv(mod_argv);
	}
	else
	{
		if (!fill_stack(argc, argv, stack_a))
			stk_mem_free_and_exit(stack_a, stack_b, 1);
	}
}
