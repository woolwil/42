# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 23:55:32 by ngvo              #+#    #+#              #
#    Updated: 2025/11/10 19:14:53 by ngvo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 0 VARS
NAME = ft_display_file
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c\

# 1 SUBSTITUION
OBJS = $(SRCS:.c=.o)

# 2 PHONY
.PHONY: all clean fclean re

# 3 MAKE
all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
# static pattern rule -> how every object file is created
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

# 4 CLEANUP
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

# re: fclean
# 		$(MAKE) all