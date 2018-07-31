/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 06:54:55 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/26 06:55:05 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list *push_half(t_stack *stack_a, t_stack *stack_b)
{
	t_list *instruction;
	int i;
	int max_a_len;

	instruction = ft_lstnew(NULL, 0);
	max_a_len = (int)(stack_a->length) / 2;
	i = 0;
	while (i < max_a_len)
	{
		do_instruction(instruction, "pb\n", stack_a, stack_b);
		i++;
	}
	return(instruction);
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
		//printf("comparing numbers |%i - %i|\n",num1,num2);
		// printf("direction %i | 1>2? :%i: ~~ 1<2? :%i:\n ", direction, num1 > num2, num1 < num2);
		}

	else
		return (-1);
	if (direction == 1 && num1 > num2)
		return (1);
	else if (direction == -1 && num1 >num2)
		return (1);
	else
		return (0);
}


int one_bubble(t_list * instruction, t_stack *stack_a, t_stack *stack_b, int direction)
{
	int list_to_swap;
	//1 is a only		2 is b only		3 is both	 0 is nothing

	list_to_swap = 0;
	if (bubble_bool(stack_b, direction) == 1)
		list_to_swap += 2;
	if (bubble_bool(stack_a, direction) == 1)
		list_to_swap++;
	//do bubble swap on each list
	if (list_to_swap == 1)
		do_instruction(instruction, "sa\n", stack_a, stack_b);
	else if (list_to_swap == 2)
		do_instruction(instruction, "sb\n", stack_a, stack_b);
	else if (list_to_swap == 3)
		do_instruction(instruction, "ss\n", stack_a, stack_b);
	
	return (list_to_swap);
}
