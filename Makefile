# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 01:22:30 by jotavare          #+#    #+#              #
#    Updated: 2023/08/28 22:54:03 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASIC
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
GDB = gdb
VAL = valgrind --leak-check=full --track-origin=yes

#colors
RESET			:= \033[0m
GREEN			=	\e[32m
CYAN			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m
RED				:= \033[1;31m
BOLD			:= \033[1;1m

# PUSH_SWAP
NAME = push_swap.a
SRCS =  ./sort_algorithms/sort_3.c \
        ./sort_algorithms/simple_sort.c \
        ./sort_algorithms/radix_sort.c \
        ./libft/ft_atoi.c \
        ./libft/ft_isdigit.c \
        ./libft/ft_lstadd_back.c \
        #./libft/ft_lstadd_front.c \
        ./libft/ft_lstlast.c \
        ./libft/ft_lstnew.c \
        ./libft/ft_lstsize.c \
        ./libft/ft_memcpy.c \
        ./libft/ft_split.c \
        ./libft/ft_strchr.c \
        ./libft/ft_strdup.c \
        ./libft/ft_substr.c \
        ./moves/push.c \
        ./moves/reverse.c \
        ./moves/rotate.c \
        ./moves/swap.c \
		./utils/check_args.c \
        ./utils/error.c \
        ./utils/free.c \
        ./utils/utilities.c \
        push_swap.c

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

# MAKE RULES
all: $(NAME) push_swap

$(NAME): $(OBJS)
	@echo "$(GREEN)$(BOLD)Creating objects directory...$(RESET)"
	ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)Objects created!$(RESET)"
	
$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

push_swap: $(PUSH_SWAP_OBJ) $(NAME)
	@echo "$(GREEN)$(BOLD)Creating executable...$(RESET)"
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(NAME) -o push_swap
	@echo "$(GREEN)$(BOLD)Executable created!$(RESET)"

clean:
	@echo "$(YELLOW)$(BOLD)Removing objects...$(RESET)"
	$(RM) $(OBJSDIR)
	@echo "$(YELLOW)$(BOLD)Objects removed!$(RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)Removing executable...$(RESET)"
	$(RM) push_swap push_swap.a
	@echo "$(RED)$(BOLD)Executable removed!$(RESET)"

re: fclean all
	@echo "$(GREEN)$(BOLD)Recompiled successfully!$(RESET)"

.SILENT: