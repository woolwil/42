# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/13 15:15:48 by ngvo              #+#    #+#              #
#    Updated: 2026/02/17 18:39:58 by ngvo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
INCLUDES	= -I.
SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)
LIBFT_DIR	= ./libft
LIBFT_A	= $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re


all: $(LIBFT_A) $(NAME)


$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) -L$(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all