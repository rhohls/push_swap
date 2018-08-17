/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:51:48 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/18 10:51:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*merge(t_stack *stack_a, t_stack *stack_b, t_list *instruction)
{
	int numa;
	int numa2;
	int numb;

	while (stack_b->start && stack_b->start->content)// && stack_b->length > 1)
	{
		// print_stacks(stack_a, stack_b);
		numa = *(int *)(stack_a->start->content);
		numa2 = *(int *)(stack_a->start->next->content);
		numb = *(int *)(stack_b->start->content);
		if (numb < numa)
			do_instruction(instruction, "pa\n", stack_a, stack_b);
		else if (numa2 < numa)
		{
			do_instruction(instruction, "ra\n", stack_a, stack_b);			
			do_instruction(instruction, "pa\n", stack_a, stack_b);
		}
		else
			do_instruction(instruction, "ra\n", stack_a, stack_b);
	}
	rot_min_a(instruction, stack_a, stack_b);
	return (instruction);	
}
