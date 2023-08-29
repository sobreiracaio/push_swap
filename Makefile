# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 17:32:47 by admin             #+#    #+#              #
#    Updated: 2023/08/29 17:34:28 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =  ./sort_algorithms/sort_3.c \
        ./sort_algorithms/simple_sort.c \
        ./sort_algorithms/radix_sort.c \
        ./libft/ft_atoi.c \
        ./libft/ft_isdigit.c \
        ./libft/ft_lstadd_back.c \
        ./libft/ft_lstlast.c \
        ./libft/ft_lstnew.c \
        ./libft/ft_lstsize.c \
        ./libft/ft_split.c \
        ./moves/push.c \
        ./moves/reverse.c \
        ./moves/rotate.c \
        ./moves/swap.c \
		./utils/check_args.c \
        ./utils/error.c \
        ./utils/free.c \
        ./utils/utilities.c \
        push_swap.c
OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re