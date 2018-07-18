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
		printf("num1:%i num2:%i \n",num1, num2);
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
	int length;

	instruction = ft_lstnew(NULL, 0);
	length = (int)(stack_a->length / 2);
	i = 0;
	while (i < length)
	{
		//st_push(stack_a, stack_b);
		do_instruction(instruction, "pb\n", stack_a, stack_b);
		i++;
	}

//	printf("instructions so far:\n%s\n", instruction->content);


	printf("stacks after push:\n");
	print_stacks(stack_a, stack_b);

	int bubble_loop;
	int list_to_swap;
	//todo cocktail - direction for bubble
	bubble_loop = 0;
	list_to_swap = 0; //1 is a only		2 is b only		3 is both
	
	while (bubble_loop < length) //go through list completely looking for changes (cocktail edit)
	{
		//printf("looop count :%zu\n",bubble_loop);
		list_to_swap = 0;
		if (bubble_bool(stack_b, 1))
			list_to_swap += 2;
		if (bubble_bool(stack_a, 1))
			list_to_swap++;

		//no need to swap inc bubble loop count;
	/*	if (list_to_swap == 0)
			bubble_loop++; 
		else
			bubble_loop = 0;
		*/	
	
		if (list_to_swap == 1)
			do_instruction(instruction, "sa\n", stack_a, stack_b);
		else if (list_to_swap == 2)
			do_instruction(instruction, "sb\n", stack_a, stack_b);
		else if (list_to_swap == 3)
			do_instruction(instruction, "ss\n", stack_a, stack_b);

		printf("stack with instruction: %i\n", list_to_swap);
		print_stacks(stack_a, stack_b);
		
		
		do_instruction(instruction, "rr\n", stack_a, stack_b);
		bubble_loop++;
	}
	//remove rr from end

	return (instruction);

}



int	pushswap_loop(t_stack *stack_a, t_stack *stack_b)
{
	//int pushbublemerge;
	t_list *a;

	a = double_bubble(stack_a, stack_b);

	//printf("Final string of commands\n");
	//ft_putstr(a->content);
	return (1);	
}