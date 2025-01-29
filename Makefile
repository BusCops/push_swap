NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = utils/helper_function1.c utils/helper_function2.c utils/helper_function3.c utils/helper_function4.c \
 sorting_function/sorting_algo.c sorting_function/sorting_operation1.c sorting_function/sorting_operation2.c sorting_function/sorting_operation3.c \
 args_checkers/args_check_and_combinor1.c args_checkers/args_check_and_combinor2.c sorting_function/sorting_utils4.c \
 main/push_swap.c sorting_function/sorting_utils1.c sorting_function/sorting_utils2.c sorting_function/sorting_utils3.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean all re