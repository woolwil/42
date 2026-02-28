/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:36:22 by ngvo              #+#    #+#             */
/*   Updated: 2026/02/24 21:39:53 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					idx;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack;

// Error Handling
bool	is_syntax_error(char *str);
void	free_stack(t_stack **stack);
void	error_free(t_stack **stack, char **argv, int is_split);

// Stack Init
void	init_stack_a(t_stack **a, char **argv, int is_split);

// Nodes Init
void	init_node_a(t_stack *a, t_stack *b);
void	init_node_b(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	prep_4_push(t_stack **stack, t_stack *top_node, char stack_name);

// Stack Utils
bool	stack_sorted(t_stack *stack);
void	sort_stacks(t_stack **a, t_stack **b);
int		stack_len(t_stack *stack);
t_stack	*find_last(t_stack*stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
bool	is_duplicate(t_stack *a, int n);


// Cmds
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

// Algorithms
void	sort_3(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);

#endif