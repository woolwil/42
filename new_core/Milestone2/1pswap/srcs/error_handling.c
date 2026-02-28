/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:19:33 by ngvo              #+#    #+#             */
/*   Updated: 2026/02/27 23:19:33 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **args)
{
	int	i;

	i = 0;
	if (!args || !*args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
void	free_stack(t_stack **stack)
{
	t_stack *current;
	t_stack *tmp;

	if (!stack || (!*stack))
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack **stack, char **argv, int is_split)
{
	free_stack(stack);
	if (is_split)
		free_split(argv);
	write(2, "Error\n", 6);
	exit(1);
}

bool is_syntax_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
		i++;
	if (!str[i])
		return (true);
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (true);
		i++;
	}
	return (false);
}
