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
	rot_min_a(instruction, stack_a, stack_b);
	return (instruction);
}

/*
t_list *rot_min( t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
	int ind_min_a;
	int min;
	int ind_min_b;
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
	i = 0;
	min = INT_MAX;
	node = stack_b->start;
	while (node)
	{
		curr_num = *(int *)node->content;
		if (curr_num < min)
		{
			min = curr_num;
			ind_min_b = i;
		}
		i++;
		node = node->next;
	}
	
	printf("INDEX MIN A %i\n", ind_min_a);
	printf("INDEX MIN B %i\n", ind_min_b);

	
	int min_direction_a; 
	min_direction_a = (ind_min_a < (int)stack_a->length / 2) ? 1 : 0;
	
	int min_direction_b; 
	min_direction_b = (ind_min_b < (int)stack_b->length / 2) ? 1 : 0;	
	printf(" MIN dir A %i\n", min_direction_a);
	printf(" MIN dir B %i\n", min_direction_b);	
	//int net_ind_b;
	//net_ind_b = (ind_min_b - (ind_min_a * min_direction_a));


	
	if (min_direction_a && min_direction_b)
	{
		while (ind_min_a != 0 && ind_min_b != 0)
		{
			do_instruction(instruction, "rr", stack_a, stack_b);
			ind_min_a--;
			ind_min_b--;
		}

	}
	if (min_direction_a)
	{
		while (ind_min_a != 0)
		{
			do_instruction(instruction, "ra", stack_a, stack_b);
			ind_min_a--;
		}
	}
	if (min_direction_b)
	{	
		while (ind_min_b != 0)
		{
			do_instruction(instruction, "rb", stack_a, stack_b);
			ind_min_b--;
		}
	}

	//------------
	if (!min_direction_a || !min_direction_b)
	{
		if (ind_min_a > 0)
			ind_min_a *= -1;
		if (ind_min_b > 0)
			ind_min_b *= -1;
	}
	if (!min_direction_a && !min_direction_b)
	{
		while (ind_min_a != 0 && ind_min_b != 0)
		{
			do_instruction(instruction, "rrr", stack_a, stack_b);
			ind_min_a++;
			ind_min_b++;
		}
	}
	if (min_direction_a)
	{
		while (ind_min_a != 0)
		{
			do_instruction(instruction, "ra", stack_a, stack_b);
			ind_min_a--;
		}
	}
	if (min_direction_b)
	{	
		while (ind_min_b != 0)
		{
			do_instruction(instruction, "rb", stack_a, stack_b);
			ind_min_b--;
		}
	}	


	//work out new number of moves needed -- 
//	if ind_min_b > len_b /2
//		res = len_b - ind_min_b
//	else
//		res = ind_min_b
	return (instruction);
} */
/*
t_list *rot_min( t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
	int list_to_swap = 0;
	//int max;

	int ind_min_a;
	int min;
	//int ind_min_b;
	int i;
	t_list *node;
	int curr_num;
	
	i = 1;
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

	printf("min of A: %i\n", min);
	while (1)
	{
		printf("current start %i \n", *(int *)stack_a->start->content);
		if (*(int *)stack_a->start->content == min)
			break ;
		//check bubble swap
		list_to_swap = 0;
		if (bubble_bool(stack_b, 1) == 1)
			list_to_swap += 2;
		if (bubble_bool(stack_a, 1) == 1)
			list_to_swap++;

		//do bubble swap on each list
		if (list_to_swap == 1)
			do_instruction(instruction, "ra\n", stack_a, stack_b);
		else if (list_to_swap == 2)
			do_instruction(instruction, "rb\n", stack_a, stack_b);
		else if (list_to_swap == 0)
			do_instruction(instruction, "rr\n", stack_a, stack_b);	
	}
	return (instruction);
}
*/
