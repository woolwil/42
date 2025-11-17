# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 16:43:06 by codespace         #+#    #+#              #
#    Updated: 2025/11/08 20:09:58 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC_FLAG = -I includes/

SRCS_DIR = srcs/
SRCS = 	$(SRCS_DIR)ft_putchar.c\
		$(SRCS_DIR)ft_putstr.c\
		$(SRCS_DIR)ft_strcmp.c\
		$(SRCS_DIR)ft_strlen.c\
		$(SRCS_DIR)ft_swap.c\

# 1
# Strips directory (no 'srcs/'), leaving only .c files
SRCS_NAMES = $(notdir $(SRCS))

# Substitutes '.c' with '.o', working with stripped names
OBJS = $(SRCS_NAMES:.c=.o)

# 2
# PHONY TARGET - ACTIONS FOR THE PROGRAM TO EXECUTE 
.PHONY: all clean fclean re

# 3
# MAIN TARGET: LIBRARY BUILDING
all: $(NAME)

# NAME = ARCHIVE NAME, OBJS = COMPILED .O BUNDLED IN ARCHIVE
$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
# AR = ARCHIVER, RCS = REPLACE/INSERT, CREATE, S(INDEX)

# .c to .o
# static pattern rule -> how every object file is created, $@ puts it in default (this case stripped dir -> root)
%.o: $(SRCS_DIR)%.c
		$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

# 4
# CLEANUP TARGETS
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean
		$(MAKE) all