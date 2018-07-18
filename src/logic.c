/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:51:48 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/18 10:51:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"
/*
void	duplicate(t_stack **stack_x, t_stack **stack_y, t_stack *stack_a, t_stack *stack_b)
{
	return ;
}
*/



void add_instruction(t_list *instruction, char *str)
{
	char *temp;

	temp = instruction->content;
	if (!temp)
		instruction->content = ft_strdup(str);
	else
		instruction->content = ft_strjoinfree(temp, str);
	instruction->content_size += 1;
}

void do_instruction(t_list *instruction, char *str, t_stack *stack_a, t_stack *stack_b)
{
	exec_instructions(str, stack_a, stack_b);
	add_instruction(instruction, str);
}

int bubble_bool(t_stack *stack_x, int direction)
{
	int num1;
	int num2;
	t_list *node;

	node = stack_x->start;
	if (node && node->next)
	{
		num1 = *(int *)node->content;
		num2 = *(int *)((node->next)->content);
	}
	else
		return (-1);
	if (direction == 1 && num1 > num2)
		return (1);
	else if (direction == -1 && num2 > num1)
		return (1);
	else
		return (0);
}

/*
** push half, bubble sort both, merge
*/
t_list *double_bubble(t_stack *stack_a, t_stack *stack_b)
{
	t_list *instruction;
	int i;
	int max_a_len;
	int odd;

	instruction = ft_lstnew(NULL, 0);
	max_a_len = (int)(stack_a->length) / 2;
	odd = (stack_a->length % 2 == 0) ? 0 : 1;

	i = 0;
	while (i < max_a_len)
	{
		do_instruction(instruction, "pb\n", stack_a, stack_b);
		i++;
	}

	printf("stacks after push:\n");
	print_stacks(stack_a, stack_b);

	int bubble_loop;
	int list_to_swap;
	//todo cocktail - direction for bubble
	bubble_loop = 0;
	list_to_swap = 0; //1 is a only		2 is b only		3 is both	 0 is nothing

	int num_correct = 1;
	
	while (1)
	{
		//check bubble swap
		list_to_swap = 0;
		if (bubble_bool(stack_b, 1) == 1)
			list_to_swap += 2;
		if (bubble_bool(stack_a, 1) == 1)
			list_to_swap++;
		//do bubble swap on each list
		if (list_to_swap == 1)
			do_instruction(instruction, "sa\n", stack_a, stack_b);
		else if (list_to_swap == 2)
			do_instruction(instruction, "sb\n", stack_a, stack_b);
		else if (list_to_swap == 3)
			do_instruction(instruction, "ss\n", stack_a, stack_b);
		
		//rotate list - 

		do_instruction(instruction, "rr\n", stack_a, stack_b);
		bubble_loop++;


		//rotate list to look like normal array -- find a better way to do this (maybe cocktail swap direction)
		if (bubble_loop == (max_a_len - num_correct))
		{
			if (odd)
			{
				if (bubble_bool(stack_a, 1) == 1)
					do_instruction(instruction, "sa\n", stack_a, stack_b);
				do_instruction(instruction, "ra\n", stack_a, stack_b);
			}
			i = 0;
			while (i < num_correct)
			{
				do_instruction(instruction, "rr\n", stack_a, stack_b);
				i++;
			}
			num_correct++;
			bubble_loop = 0;
		}
		if (num_correct == max_a_len)
			break ;
	}
	//remove rr from end
	return (instruction);
}

t_list *merge(t_stack *stack_a, t_stack *stack_b, t_list *instruction)
{
	//after removing rr from end, rotate both list until min at top
	// use bubble bool
	int num1;
	int num2;

	while (stack_b->start && stack_b->start->content)
	{
		num1 = *(int *)(stack_a->start->content);
		num2 = *(int *)(stack_b->start->content);

		if (num2 < num1)
			do_instruction(instruction, "pa\n", stack_a, stack_b);
		do_instruction(instruction, "ra\n", stack_a, stack_b);
	}
	do_instruction(instruction, "ra\n", stack_a, stack_b);
	return (instruction);
}


int	pushswap_loop(t_stack *stack_a, t_stack *stack_b)
{
	t_list *instruction;

	instruction = double_bubble(stack_a, stack_b);

	//printf("Final string of commands\n");
	//ft_putstr(a->content);
	printf("\nstacks after double bubble\n");
	print_stacks(stack_a, stack_b);

	instruction = merge(stack_a, stack_b, instruction);

	printf("\nstacks after merge\n");
	print_stacks(stack_a, stack_b);
	return (1);	
}