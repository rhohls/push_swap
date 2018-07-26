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

#include "../includes/push_swap.h"


/*
** push half, bubble sort both, merge
*/
t_list *double_bubble(t_list * instruction,t_stack *stack_a, t_stack *stack_b)
{
	printf("Im in double bubble\n");
	int i;
	int max_a_len;
	int odd;

	max_a_len = (int)(stack_a->length);
//	printf("wtf is wiht this odd shit how does it work ? ?!?\n");
	odd = (stack_a->length % 2 == 0) ? 0 : 1;  
//	max_a_len -= odd;

	printf("max a : %i  \n   odd? : %i  \n", max_a_len, odd);


//	printf("stacks after push:\n");
//	print_stacks(stack_a, stack_b);

	int bubble_loop;
	int num_correct = 1;

	bubble_loop = 0;
	
	while (1)
	{
		//check bubble swap
		one_bubble(instruction, stack_a, stack_b, 1);
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


