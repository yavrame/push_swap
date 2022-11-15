NAME		=	push_swap
NAME_B		=	checker

SRC_DIR		=	srcs/
SRC_B_DIR	=	srcs_bonus/

SRCS 		=	main.c str_tools.c fill_stk_a.c five_nodes_stk_sort.c stack_tools.c commands_a.c commands_b.c commands_r.c ft_split.c ft_atoi.c stk_sort.c stk_sort_find_score.c array_utils.c stk_sort_exec_commands.c three_nodes_stk_sort.c mem_free_tools.c stack_tools_2.c
SRCS_B		= 	checker.c get_next_line.c get_next_line_utils.c commands_a.c commands_b.c commands_r.c stack_tools.c stack_tools_2.c str_tools.c mem_free_tools.c fill_stk_a.c ft_atoi.c ft_split.c

HEADER		=	includes/push_swap.h
HEADER_B 	=	includes/checker.h

SRC			=	$(addprefix $(SRC_DIR), $(SRCS))
SRC_B		=	$(addprefix $(SRC_B_DIR), $(SRCS_B))

OBJS 	= 	$(SRC:.c=.o)
OBJS_B 	= 	$(SRC_B:.c=.o)

CC		= 	gcc
CFLAGS 	=	-Wall -Wextra -Werror

RM 		= 	rm -f

.c.o		:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all			:	$(NAME)

$(NAME)		: 	$(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -I ${HEADER}

bonus	: 	$(OBJS_B)
	${CC} ${CFLAGS} ${OBJS_B} -o ${NAME_B} -I ${HEADER_B}

clean		:
	${RM} ${OBJS} ${OBJS_B}

fclean		:	clean
	${RM} ${NAME} ${NAME_B}

re			:	fclean all

norm	:
	norminette -R CheckForbiddenSourceHeader ${SRC} ${SRC_B}
	norminette -R CheckDefine ${HEADER} ${HEADER_B}

.PHONY	:	all bonus clean fclean re norm