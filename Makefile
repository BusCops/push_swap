NAME = push_swap

BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = utils/helper_function1.c utils/helper_function2.c utils/helper_function3.c utils/helper_function4.c \
 sorting_function/sorting_algo.c sorting_function/sorting_operation1.c sorting_function/sorting_operation2.c sorting_function/sorting_operation3.c \
 args_checkers/args_check_and_combinor1.c args_checkers/args_check_and_combinor2.c sorting_function/sorting_utils4.c \
 main/push_swap.c sorting_function/sorting_utils1.c sorting_function/sorting_utils2.c sorting_function/sorting_utils3.c \
 sorting_function/sorting_operation4.c

SRC_BONUS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c checker_bonus/main.c checker_bonus/op_fun1.c

OBJS = ${SRCS:.c=.o}

OBJS_BNS = ${SRC_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus : ${BONUS_NAME}

${BONUS_NAME} : ${OBJS_BNS}
	${CC} ${CFLAGS} ${OBJS_BNS} -o ${BONUS_NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	${RM} ${OBJS} ${OBJS_BNS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean all re bonus
