# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 16:11:37 by ngvo              #+#    #+#              #
#    Updated: 2026/03/14 18:53:26 by ngvo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CHECKER     = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
INCLUDES    = -I. -I$(LIBFT_DIR)

# Directories
SRCS_DIR    = srcs
OBJS_DIR    = objs
LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

CMDS_SRCS   = $(SRCS_DIR)/cmds/move.c \
              $(SRCS_DIR)/cmds/push.c \
              $(SRCS_DIR)/cmds/rev_rot.c \
              $(SRCS_DIR)/cmds/rotate.c \
              $(SRCS_DIR)/cmds/swap.c

COMMON_SRCS = $(SRCS_DIR)/error_handling.c \
              $(SRCS_DIR)/init_a2b.c \
			  $(SRCS_DIR)/init_b2a.c \
              $(SRCS_DIR)/sort_small.c \
              $(SRCS_DIR)/sort_three.c \
              $(SRCS_DIR)/stack_init.c \
              $(SRCS_DIR)/stack_utils.c \
              $(SRCS_DIR)/stack_utils2.c \
              $(SRCS_DIR)/turk_alg.c

PUSH_SWAP_SRCS = $(SRCS_DIR)/push_swap.c
CHECKER_SRCS   = $(SRCS_DIR)/checker_bonus.c

PUSH_SWAP_ALL_SRCS = $(CMDS_SRCS) $(COMMON_SRCS) $(PUSH_SWAP_SRCS)
CHECKER_ALL_SRCS   = $(CMDS_SRCS) $(COMMON_SRCS) $(CHECKER_SRCS)

PUSH_SWAP_OBJS = $(PUSH_SWAP_ALL_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
CHECKER_OBJS   = $(CHECKER_ALL_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

.PHONY: all bonus clean fclean re libft

all: libft $(NAME)

bonus: libft $(CHECKER)

# Build libft by calling its own Makefile
libft:
	@$(MAKE) -C $(LIBFT_DIR)

# Link everything together
$(NAME): $(PUSH_SWAP_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(CHECKER): $(CHECKER_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -L$(LIBFT_DIR) -lft -o $(CHECKER)

# Compile .c to .o
# mkdir -p $(dir $@) ensures objs/cmds/ exists before push.o is created
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all