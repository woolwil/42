# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 16:11:37 by ngvo              #+#    #+#              #
#    Updated: 2026/03/13 16:14:15 by ngvo             ###   ########.fr        #
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
# (Split into two variables just to stay organized)
CMDS_SRCS   = $(SRCS_DIR)/cmds/move.c \
              $(SRCS_DIR)/cmds/push.c \
              $(SRCS_DIR)/cmds/rev_rot.c \
              $(SRCS_DIR)/cmds/rotate.c \
              $(SRCS_DIR)/cmds/swap.c

MAIN_SRCS   = $(SRCS_DIR)/error_handling.c \
              $(SRCS_DIR)/init_a2b.c \
              $(SRCS_DIR)/push_swap.c \
              $(SRCS_DIR)/sort_small.c \
              $(SRCS_DIR)/sort_three.c \
              $(SRCS_DIR)/stack_init.c \
              $(SRCS_DIR)/stack_utils.c \
              $(SRCS_DIR)/turk_alg.c

SRCS        = $(CMDS_SRCS) $(MAIN_SRCS)

# The Substitution Reference:
# Pattern is $(VARIABLE:OLD=NEW)
# We are saying: Look at SRCS, find the pattern 'srcs/%.c' 
# and replace it with 'objs/%.o'
OBJS        = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

.PHONY: all clean fclean re libft

all: libft $(NAME)

# Build libft by calling its own Makefile
libft:
	@$(MAKE) -C $(LIBFT_DIR)

# Link everything together
$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile .c to .o
# mkdir -p $(dir $@) ensures objs/cmds/ exists before push.o is created
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