/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:35:53 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/18 12:36:04 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	loop_1(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(line, "sa") == 10)
		st_swap(stack_a);
	else if (ft_strcmp(line, "sb") == 10)
		st_swap(stack_b);
	else if (ft_strcmp(line, "ss") == 10)
		st_swap_two(stack_a, stack_b);
	else if (ft_strcmp(line, "pa") == 10)
		st_push(stack_b, stack_a);
	else if (ft_strcmp(line, "pb") == 10)
		st_push(stack_a, stack_b);
	else if (ft_strcmp(line, "ra") == 10)
		st_rotate(stack_a);
	else
		return (0);
	return (1);
}

static int	loop_2(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(line, "rb") == 10)
		st_rotate(stack_b);
	else if (ft_strcmp(line, "rr") == 10)
		st_rotate_two(stack_a, stack_b);
	else if (ft_strcmp(line, "rra") == 10)
		st_revrotate(stack_a);
	else if (ft_strcmp(line, "rrb") == 10)
		st_revrotate(stack_b);
	else if (ft_strcmp(line, "rrr") == 10)
		st_revrotate_two(stack_b, stack_a);
	else if (ft_strcmp(line, "quit") == 10)
		return (-1);
	else
		return (0);
	return (1);
}

void		exec_instructions(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (loop_1(str, stack_a, stack_b) != 1)
		if (loop_2(str, stack_a, stack_b) != 1)
			printf("Error: bad instruction!!!!\ngot instruction |%s|\n", str);
}

void		add_instruction(t_list *instruction, char *str)
{
	char *temp;

	temp = instruction->content;
	if (!temp)
		instruction->content = ft_strdup(str);
	else
		instruction->content = ft_strjoinfree(temp, str);
	instruction->content_size += 1;
}

void		do_instruction(t_list *instruction, char *str,
							t_stack *stack_a, t_stack *stack_b)
{
	exec_instructions(str, stack_a, stack_b);
	add_instruction(instruction, str);
}
