# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 16:11:37 by ngvo              #+#    #+#              #
#    Updated: 2026/03/13 16:13:23 by ngvo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
INCLUDES    = -I. -I$(LIBFT_DIR)

# Directories
SRCS_DIR    = srcs
OBJS_DIR    = objs
LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

# Explicit Source Files
# Commands subfolder
CMDS_SRCS   = $(SRCS_DIR)/cmds/move.c \
              $(SRCS_DIR)/cmds/push.c \
              $(SRCS_DIR)/cmds/rev_rot.c \
              $(SRCS_DIR)/cmds/rotate.c \
              $(SRCS_DIR)/cmds/swap.c

# Main logic files
MAIN_SRCS   = $(SRCS_DIR)/error_handling.c \
              $(SRCS_DIR)/init_a2b.c \
              $(SRCS_DIR)/push_swap.c \
              $(SRCS_DIR)/sort_small.c \
              $(SRCS_DIR)/sort_three.c \
              $(SRCS_DIR)/stack_init.c \
              $(SRCS_DIR)/stack_utils.c \
              $(SRCS_DIR)/turk_alg.c

SRCS        = $(CMDS_SRCS) $(MAIN_SRCS)

# The Substitution Reference
# This converts srcs/cmds/push.c -> objs/cmds/push.o 
# and srcs/main.c -> objs/main.o
OBJS        = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

.PHONY: all clean fclean re libft

all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Rule for all .o files
# @mkdir -p $(dir $@) is critical here because it creates 
# the 'objs/' folder AND the 'objs/cmds/' subfolder automatically.
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all