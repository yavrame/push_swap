/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:54:18 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 17:11:04 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_atoi
{
	long int		value;
	int				error;
}	t_atoi;

typedef struct s_rotate
{
	size_t	direction_a;
	size_t	steps_a;
	size_t	direction_b;
	size_t	steps_b;
}	t_rotate;

typedef struct s_stk
{	
	int				value;
	t_rotate		rotate;
	struct s_stk	*next;
}	t_stk;

typedef struct s_specs
{
	int			min;
	int			med;
	int			max;
	int			size_a;
	int			size_b;
	t_rotate	min_rotate_score;
	int			error;
}	t_specs;

void	init_array(int **array, int array_size);
void	fill_array(int *array, t_stk **stk_a, int stk_a_size);
void	sort_array(int *array, int arr_size);
void	calc_score(t_stk **stack_a, t_stk **stack_b, t_specs *specs);
void	a_moves(t_stk **stack_a, t_specs *params);
void	b_moves(t_stk **stack_b, t_specs *params);
void	exec_next_command(t_stk **stack_a, t_stk **stack_b, t_specs *specs);
void	ft_stkpush_front(t_stk **lst, t_stk *new);
void	init_stack(t_stk ***stack);
int		dublicates_on_stack(t_stk **stack, int new_node_value);
void	ft_clear_stack(t_stk **stack);
t_stk	*ft_stack_find_last_node(t_stk *lst);
void	ft_stack_add_back(t_stk **stack, t_stk *new_node);
t_stk	*ft_node_new(int content);
int		ft_stk_size(t_stk *lst);
void	ft_putstr_fd(char *s, int fd);
void	validate_args(int argc, char **argv, t_stk **stack_a, t_stk **stack_b);
t_atoi	ft_atoi(char *str, t_atoi res);
void	fill_stk_a(int argc, char **argv, t_stk **stack_a, t_stk **stack_b);
void	sort_stk_a(t_stk **stack_a, t_stk **stack_b);
void	c_sa(t_stk *stk, int print);
void	c_sb(t_stk *stk, int print);
void	c_ra(t_stk *stk, int print);
void	c_rb(t_stk *stk, int print);
void	c_rra(t_stk *stack, int print);
void	c_rrb(t_stk *stk, int print);
void	c_pb(t_stk **stk_a, t_stk **stk_b, int print);
void	c_pa(t_stk **stk_a, t_stk **stk_b, int print);
void	c_rr(t_stk *stk_a, t_stk *stk_b, int print);
void	c_rrr(t_stk *stk_a, t_stk *stk_b, int print);
void	f_ss(t_stk *stack_a, t_stk *stack_b, int print);
void	stk_mem_free_and_exit(t_stk **stack_a, t_stk **stack_b, \
							int print_error);
int		stk_is_sorted(t_stk *stk);
char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *s);
void	less_five_sort(t_stk **stack_a, t_stk **stack_b, size_t size_a);
void	more_five_sort(t_stk **stack_a, t_stk **stack_b);
void	sort_three_in_a(t_stk **stack_a);
void	sort_three_in_b(t_stk **stack_b);
void	stk_mem_free_and_exit(t_stk **stack_a, t_stk **stack_b, \
							int print_error);
char	*ft_strjoin(char const *s1, char const *s2);

#endif