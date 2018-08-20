/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:03:53 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/19 08:04:05 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int min_stack (t_stack *stack_x, int *ind_min_x)
{
	int min;
	int i;
	t_list *node;
	int curr_num;

	i = 0;
	min = INT_MAX;
	node = stack_x->start;
	while (node)
	{
		curr_num = *(int *)node->content;
		if (curr_num < min)
		{
			min = curr_num;
			*ind_min_x = i;
		}
		i++;
		node = node->next;
	}
	return (min);
}

 t_list *rot_min_a( t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
	int min_a;
	int ind_min_a;
	int min_direction_a; 

	min_a = min_stack(stack_a, &ind_min_a);
	min_direction_a = (ind_min_a > (int)stack_a->length / 2) ? 0 : 1;

	// printf("direction a: %d  ind_a %d\n", min_direction_a, ind_min_a);

	if (min_direction_a)
	{
		while (ind_min_a != 0)
		{
			do_instruction(instruction, "ra\n", stack_a, stack_b);
			// printf("doing - ra\n");
			ind_min_a--;
		}
	}
	else 
	{
		while (ind_min_a != (int)stack_a->length)
		{
			do_instruction(instruction, "rra\n", stack_a, stack_b);
			// printf("doing - rra\n");
			ind_min_a++;
		}
	}
	return (instruction);
}
 
t_list *rot_min(t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
	int min_a;
	int ind_min_b;
	int min_direction_b; 

	min_a = min_stack(stack_a, &ind_min_b);
	min_stack(stack_b, &ind_min_b);
	min_direction_b = (ind_min_b > (int)stack_b->length / 2) ? 0 : 1;
	// printf("min a %i\n",min_a);
	// printf("ind min b %i   length/2 b  %i\n", ind_min_b, (int)stack_b->length / 2);
	// printf("min direction --%i-- \n", min_direction_b);

	if (min_direction_b)
	{
		while (ind_min_b != 0)
		{
			do_instruction(instruction, "rr\n", stack_a, stack_b);
			ind_min_b--;
		}
	}
	else 
	{
		while (ind_min_b != (int)stack_b->length)
		{
			do_instruction(instruction, "rrr\n", stack_a, stack_b);
			ind_min_b++;
		}
	}
	// printf("\nStacks before min a\n");
	// print_stacks(stack_a, stack_b);

	rot_min_a(instruction, stack_a, stack_b);

	// printf("\nStacks before after a\n");
	// print_stacks(stack_a, stack_b);
	return (instruction);
}


 t_list *rot_max_b(t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
	int min_b;
	int ind_min_b;
	int min_direction_b; 

	min_b = min_stack(stack_b, &ind_min_b);
	min_direction_b = (ind_min_b > (int)stack_b->length / 2) ? 0 : 1;

	printf("direction b: %d  ind_b %d\n", min_direction_b, ind_min_b);

	if (min_direction_b)
	{
		while (ind_min_b != 0)
		{
			do_instruction(instruction, "rrb\n", stack_a, stack_b);
			printf("doing - rb\n");
			ind_min_b--;
		}
	}
	else 
	{
		while (ind_min_b != (int)stack_b->length)
		{
			do_instruction(instruction, "rb\n", stack_a, stack_b);
			printf("doing - rra\n");
			ind_min_b++;
		}
	}
	return (instruction);
}