/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:36:22 by ngvo              #+#    #+#             */
/*   Updated: 2026/02/13 16:25:58 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					idx;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}	t_stack_node;

// Error Handling

// Stack Init

// Nodes Init

// Stack Utils

// Cmds

// Algorithms

#endif