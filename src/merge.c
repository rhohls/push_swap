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

t_list *rot_min_a( t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
//	printf("hello?\n");
	int min;
	int ind_min_a;
	int i;
	t_list *node;
	int curr_num;

	i = 0;
	min = INT_MAX;
	node = stack_a->start;
	while (node)
	{
		curr_num = *(int *)node->content;
		if (curr_num < min)
		{
			min = curr_num;
			ind_min_a = i;
		}
		i++;
		node = node->next;
	}
	node = stack_a->start;

	int min_direction_a; 
	min_direction_a = (ind_min_a > (int)stack_a->length / 2) ? 0 : 1;
//	printf("ind min b %i   length/2 b  %i\n", ind_min_b, (int)stack_a->length / 2);
//	printf("min direction --%i-- \n", min_direction_b);

	if (min_direction_a)
	{
		while (ind_min_a != 0)
		{
			do_instruction(instruction, "rr\n", stack_a, stack_b);
			ind_min_a--;
		}
	}
	else 
	{
		while (ind_min_a != (int)stack_a->length)
		{
			do_instruction(instruction, "rrr\n", stack_a, stack_b);
			ind_min_a++;
		}
	}

	return (instruction);
}

t_list *merge(t_stack *stack_a, t_stack *stack_b, t_list *instruction)
{
	char str[] = "~~~\nmerging now\n~~~\n";
	char *temp;

	temp = instruction->content;
	if (!temp)
		instruction->content = ft_strdup(str);
	else
		instruction->content = ft_strjoinfree(temp, str);

	int numa;
	int numb;

	while (stack_b->start && stack_b->start->content)// && stack_b->length > 1)
	{
		numa = *(int *)(stack_a->start->content);
		numb = *(int *)(stack_b->start->content);

		if (numb < numa)
			do_instruction(instruction, "pa\n", stack_a, stack_b);
		else
			do_instruction(instruction, "ra\n", stack_a, stack_b);
	}
	//printf("123\n");
	rot_min_a(instruction, stack_a, stack_b);
	return (instruction);	
}



/*
t_list *merge(t_stack *stack_a, t_stack *stack_b, t_list *instruction)
{
	//after removing rr from end, rotate both list until min at top
	// use bubble bool
	int num1;
	int num2;
	int numb;

	while (stack_b->start && stack_b->start->content && stack_b->length > 1)
	{
		num1 = *(int *)(stack_a->start->content);
		num2 = *(int *)(stack_b->start->content);

		if (num2 < num1)
			do_instruction(instruction, "pa\n", stack_a, stack_b);
	//	print_stacks(stack_a, stack_b);
		do_instruction(instruction, "ra\n", stack_a, stack_b);
	}


	//if curr num < b num   and next num > b num
	// rotate and push
	//else retotate
	numb = *(int *)(stack_b->start->content);
	if (stack_b->length == 1)
	{
		while (stack_b->length)
		{
			num1 = *(int *)(stack_a->start->content);
			num2 = *(int *)(stack_a->start->next->content);

			if (num1 < numb && num2 > numb )
				break ;
			do_instruction(instruction, "ra\n", stack_a, stack_b);
		//	print_stacks(stack_a, stack_b);
		}
		do_instruction(instruction, "ra\n", stack_a, stack_b);
		do_instruction(instruction, "pa\n", stack_a, stack_b);
	}
//	rot_min(instruction, stack_a, stack_b);


	while (!bubble_bool(stack_a, 1))
	{
	//	print_stacks(stack_a, stack_b);
		do_instruction(instruction, "ra\n", stack_a, stack_b);
	}
	do_instruction(instruction, "ra\n", stack_a, stack_b);
	
	return (instruction);
}
*/