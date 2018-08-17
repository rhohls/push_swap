/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:02:20 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/17 14:02:24 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
	
int		stack_sorted_anyorder(t_stack *stack_a)
{
	t_list	*lst_a;
	int		num;
	int		num_old;
	int		count;

	count = 0;
	lst_a = stack_a->start;
	num = INT_MIN;
	while (lst_a)
	{
		num_old = num;
		num = *(int *)(lst_a->content);
		if (num < num_old)
		{
			count++;
			if (count > 1)
				return (0);
		}
		lst_a = lst_a->next;
	}
	if (*(int *)(stack_a->start->content) < num)
	{
		count++;
		if (count > 1)
			return (0);
	}	
	return (1);
}


t_list	*insert_loop(t_stack *stack_a, t_stack *stack_b, t_list *instruction)
{

	printf("sort res A: %d\n", stack_sorted_anyorder(stack_a));
	rot_min_a(instruction, stack_a, stack_b);
	while (!stack_sorted_anyorder(stack_a))
	{
		
	}
	do_instruction(instruction, "pa\n", stack_a, stack_b);
	return (instruction);
}



int	mini_insert(t_stack *stack_a, t_stack *stack_b, t_psflags *flags)
{
	t_list	*instruction;
	// int		fd;

	instruction = ft_lstnew(NULL, 0);
	printf("here\n");
	if (flags->debug == 1)
	{
		instruction = insert_loop(stack_a, stack_b, instruction);
		printf("\nstacks after insert\n");
		print_stacks(stack_a, stack_b);

		instruction = merge(stack_a, stack_b, instruction);
		printf("\nstacks after merge\n");
		print_stacks(stack_a, stack_b);
	}
	else
	{

		instruction = insert_loop(stack_a, stack_b, instruction);
		instruction = merge(stack_a, stack_b, instruction);
	}

	print_instructions(flags, instruction);
	return (1);	
}