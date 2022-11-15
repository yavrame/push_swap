/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:54:24 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 00:54:24 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FDM
#  define FDM 4096
# endif

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

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
void	ft_stkpush_front(t_stk **lst, t_stk *new);
void	init_stk(t_stk ***stack);
int		dublicates_on_stack(t_stk **stack, int new_node_value);
void	ft_clear_stack(t_stk **stack);
void	ft_stk_add_back(t_stk **stack, t_stk *new_node);
t_stk	*ft_node_new(int content);
int		ft_stk_size(t_stk *lst);
void	ft_putstr_fd(char *s, int fd);
t_atoi	ft_atoi(char *str, t_atoi res);
void	fill_stk_a(int argc, char **argv, t_stk **stack_a, \
				t_stk **stack_b);
void	c_sa(t_stk *stack, int print);
void	c_sb(t_stk *stack, int print);
void	c_ra(t_stk *stk, int print);
void	c_rb(t_stk *stack, int print);
void	c_rra(t_stk *stack, int print);
void	c_rrb(t_stk *stack, int print);
void	c_ss(t_stk *stack_a, t_stk *stack_b, int print);
void	c_pb(t_stk **stack_a, t_stk **stack_b, int print);
void	c_pa(t_stk **stack_a, t_stk **stack_b, int print);
void	c_rr(t_stk *stack_a, t_stk *stack_b, int print);
void	c_rrr(t_stk *stack_a, t_stk *stack_b, int print);
void	c_ss(t_stk *stack_a, t_stk *stack_b, int print);
void	stk_mem_free_and_exit(t_stk **stack_a, t_stk **stack_b, \
							int print_error);
int		stk_is_sorted(t_stk *stk);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen_g(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr_g(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_g(char const *s1, char const *s2);

#endif