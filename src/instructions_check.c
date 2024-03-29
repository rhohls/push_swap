/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 07:49:49 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/17 07:49:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	loop_1(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(line, "sa") == 0)
		st_swap(stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		st_swap(stack_b);
	else if (ft_strcmp(line, "ss") == 0)
		st_swap_two(stack_a, stack_b);
	else if (ft_strcmp(line, "pa") == 0)
		st_push(stack_b, stack_a);
	else if (ft_strcmp(line, "pb") == 0)
		st_push(stack_a, stack_b);
	else if (ft_strcmp(line, "ra") == 0)
		st_rotate(stack_a);
	else
		return (0);
	return (1);
}

static int	loop_2(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(line, "rb") == 0)
		st_rotate(stack_b);
	else if (ft_strcmp(line, "rr") == 0)
		st_rotate_two(stack_a, stack_b);
	else if (ft_strcmp(line, "rra") == 0)
		st_revrotate(stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		st_revrotate(stack_b);
	else if (ft_strcmp(line, "rrr") == 0)
		st_revrotate_two(stack_b, stack_a);
	else if (ft_strcmp(line, "quit") == 0)
		return (-1);
	else
		return (0);
	return (1);
}

static int	get_fd(t_psflags *flags)
{
	int fd;

	if (flags->file == 1)
	{
		fd = open(flags->file_loc, O_RDONLY);
		if (fd < 0)
		{
			printf("There was an error opening file\n");
			exit(0);
		}
	}
	else
		fd = 0;
	return (fd);
}

int			instructions_loop(t_stack *stack_a, t_stack *stack_b,
								t_psflags *flags)
{
	int		fd;
	char	*line;
	int		loop;

	fd = get_fd(flags);
	while (get_next_line(fd, &line))
	{
		if (loop_1(line, stack_a, stack_b) == 0)
		{
			loop = loop_2(line, stack_a, stack_b);
			if (loop == -1)
				break ;
			else if (loop == 0)
				return (-1);
		}
		if (flags->debug == 1)
			print_stacks(stack_a, stack_b);
		free(line);
	}
	compare(stack_a, stack_b);
	return (1);
}
