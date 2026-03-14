/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:37:01 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/14 16:41:56 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_error(t_stack **a, t_stack **b, char **args, int is_split)
{
	free_stack(a);
	free_stack(b);
	if (is_split)
		free_split(args);
	write(2, "Error\n", 6);
	exit(1);
}

static void	apply_instruction(char *line, t_stack **a, t_stack **b,
		char **args, int is_split)
{
	if (!ft_strncmp(line, "sa\n", 4))
		sa(a, false);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(b, false);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(a, b, false);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(a, b, false);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(b, a, false);
	else if (!ft_strncmp(line, "ra\n", 4))
		ra(a, false);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(b, false);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(a, b, false);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(a, false);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(b, false);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(a, b, false);
	else
	{
		free(line);
		free_error(a, b, args, is_split);
	}
}

static char	*get_next_line_lite(int fd)
{
	char	*buf;
	char	c;
	int		i;
	int		rd;

	i = 0;
	buf = malloc(5);
	if (!buf)
		return (NULL);
	while (i < 4)
	{
		rd = read(fd, &c, 1);
		if (rd <= 0)
			break ;
		buf[i++] = c;
		if (c == '\n')
			break ;
	}
	if (rd <= 0 && i == 0)
	{
		free(buf);
		return (NULL);
	}
	if (i == 4 && buf[3] != '\n')
	{
		free(buf);
		return (ft_strdup("INVALID"));
	}
	buf[i] = '\0';
	return (buf);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	init_stack_a(&a, args, (argc == 2));
	if (argc == 2 && !args)
		free_error(&a, &b, args, (argc == 2));
	while (1)
	{
		line = get_next_line_lite(0);
		if (!line)
			break ;
		if (!ft_strncmp(line, "INVALID", 8))
		{
			free(line);
			free_error(&a, &b, args, (argc == 2));
		}
		apply_instruction(line, &a, &b, args, (argc == 2));
		free(line);
	}
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	if (argc == 2)
		free_split(args);
	return (0);
}