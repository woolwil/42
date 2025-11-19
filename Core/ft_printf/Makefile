# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 13:28:30 by ngvo              #+#    #+#              #
#    Updated: 2025/11/18 13:28:30 by ngvo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
RM			= rm -f
INCLUDES	= -I.
TEST_NAME	= ft_printf
MAIN		= main.c
LINK_AR		= -lftprintf
LIB_SEARCH	= -L.

SRCS		= ft_printf.c \
			print_format.c \
			print_fts.c

# BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(TEST_NAME)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

test: $(NAME) $(MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAIN) $(LIB_SEARCH) $(LINK_AR) -o $(TEST_NAME)
