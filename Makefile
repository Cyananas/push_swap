# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pravry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 13:59:54 by pravry            #+#    #+#              #
#    Updated: 2021/05/19 14:53:50 by pravry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

PUSH = push_swap

SRCS =		cmd.c \
		checker.c \
		ft_apply_cmd.c \
		ft_check_sorted.c \
		ft_free_tab.c \
		ft_gnl.c \
		ft_gnl_check.c \
		ft_rev_rotate.c \
		ft_rotate.c \
		init_stack.c \
		init_utils.c \
		swap.c

SRCS_PUSH = init_stack.c \
		init_utils.c \
		ft_rotate.c \
		ft_rev_rotate.c \
		swap.c \
		ft_free_tab.c \
		ft_check_sorted.c \
		ft_apply_cmd.c \
		sort_easy.c \
		sort_easy_utils.c \
		sort_push.c \
		push_swap.c \
		apply_strat.c \
		calc_nbr_rot.c \
		calc_opti.c \
		get_pos.c \
		get_to_top.c \
		init_rules.c

CC 	= @clang

CFLAGS = -Wall -Wextra -Werror

RM = @rm -rf

INC_DIR = ./includes

LIB_DIR 	= ./libft

OBJS	= $(addprefix srcs/, $(SRCS:.c=.o))
OBJS_PUSH = $(addprefix srcs/, $(SRCS_PUSH:.c=.o))

.c.o:
	$(CC) $(CFLAGS) -I includes -I libft -c $< -o $(<:.c=.o) 

$(NAME): $(OBJS) $(OBJS_PUSH) $(INC_DIR)/push_swap.h
		@make -s -C $(LIB_DIR)
		$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)
		$(CC) $(CFLAGS) $(OBJS_PUSH) -L$(LIB_DIR) -lft -o $(PUSH)

all: $(NAME)

clean :
	@make clean -s -C $(LIB_DIR)
	$(RM) $(OBJS) $(OBJS_PUSH)

fclean:	clean
	$(RM) libft/libft.a
	$(RM) $(NAME) $(PUSH)
	$(RM) $(NAME) $(PUSH)

re:	fclean all

.PHONY:	all clean fclean re
