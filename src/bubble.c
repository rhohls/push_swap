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


void one_bubble(t_list * instruction, t_stack *stack_a, t_stack *stack_b)
{
	int list_to_swap;
	//1 is a only		2 is b only		3 is both	 0 is nothing

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

//	printf("stacks after push:\n");
//	print_stacks(stack_a, stack_b);

	int bubble_loop;

	//todo cocktail - direction for bubble
	bubble_loop = 0;


	int num_correct = 1;
	
	while (1)
	{
		//check bubble swap
		one_bubble(instruction, stack_a, stack_b);
		//rotate list - 

		do_instruction(instruction, "rr\n", stack_a, stack_b);
		bubble_loop++;


		//rotate list to look like normal array -- find a better way to do this (maybe cocktail swap direction)
		//technically okay cuase remove rr at end
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

void remove_rr(t_list * instruction, t_stack *stack_a, t_stack *stack_b)
{
	char *str;
	char *temp;
	int i;
	
	str = (char *)(instruction->content);
	i = 0;
	while(str[i])
		i++;
	i -= 2;
	while (i > 0)
	{
		if (str[i] == 'r' && str[i - 1] == '\n')
		{
			temp = ft_strjoin("r", &str[i]);
	//		ft_putstr(temp);
			exec_instructions(temp, stack_a, stack_b);
			free(temp);
			str[i] = '\0';
			instruction->content_size -= 1;
		}
		if (str[i] == 's' || str[i] == 'p')
			break ;
		i--;
	}
}


int	pushswap_loop(t_stack *stack_a, t_stack *stack_b, t_psflags *flags)
{
	t_list	*instruction;
	int		fd;

	if (flags->debug == 1)
	{
		instruction = double_bubble(stack_a, stack_b);
		printf("String of commands after bubble\n");
		ft_putstr(instruction->content);
		printf("\nstacks after double bubble\n");
		print_stacks(stack_a, stack_b);

		remove_rr(instruction, stack_a, stack_b);
		printf("Commands after remove RR\n");
		ft_putstr(instruction->content);
		printf("\nstacks after remove rr\n");
		print_stacks(stack_a, stack_b);

		rot_min(instruction, stack_a, stack_b);
		printf("Commands after rotate for min\n");
		ft_putstr(instruction->content);
		printf("\nstacks after minrot\n");
		print_stacks(stack_a, stack_b);


		instruction = merge(stack_a, stack_b, instruction);
		printf("\nstacks after merge\n");
		print_stacks(stack_a, stack_b);
	}
	else
	{
		instruction = double_bubble(stack_a, stack_b);
		remove_rr(instruction, stack_a, stack_b);
		rot_min(instruction, stack_a, stack_b);
		instruction = merge(stack_a, stack_b, instruction);
	}
//	printf("Final Instructions\n");
	if (flags->file == 1)
	{
		fd = open(flags->file_loc, O_RDWR | O_CLOEXEC | O_CREAT,S_IRWXU);
		if (fd < 0)
		{
			printf("There was an error writing to file with name \"%s\" fd = %i\n", flags->file_loc, fd);
			exit(0);
		}
	}
	else
		fd = 1;

	ft_putstr_fd(instruction->content, fd);
	
	return (1);	
}