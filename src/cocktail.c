/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocktail.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 07:22:59 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/26 07:23:06 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list *cocktail(t_list * instruction,t_stack *stack_a, t_stack *stack_b)
{
	do_instruction(instruction, "pb\n", stack_a, stack_b);
	do_instruction(instruction, "pb\n", stack_a, stack_b);	
	int ind_a;
	int ind_b;
	int max_a;
	int max_b;
	int odd;

	int min_a;
//	int min_b;

	max_a = (int)(stack_a->length) - 1;
	max_b = (int)(stack_b->length);
	odd = (stack_a->length % 2 == 0) ? 0 : 1;

//	int swap_a;
//	int swap_b;
	int direction;
	
	direction = 1;
	min_a = 0;
	min_a = 0;
	ind_a = 0;
	ind_b = 0;
	
	int bubble_ret;	//1 is a only		2 is b only		3 is both		0 is nothing


	// printf("stacks for starting\n");
	// print_stacks(stack_a, stack_b);


	while(1)
	{
		// ft_putstr("Stacks before swap:\n");
		// print_stacks(stack_a, stack_b);

		bubble_ret = bubble_bool(stack_a, direction);
		if (bubble_ret == 1)
			do_instruction(instruction, "sa\n", stack_a, stack_b);

		// printf("bubble return == %i \n",bubble_ret);
		// printf("min %i | max %i | current %i  -- direction %i\n", min_a,max_a, ind_a, direction);
		// ft_putstr("and stacks:\n");
		// print_stacks(stack_a, stack_b);

		if (direction == 1)
		{
			// do_instruction(instruction, "ra\n", stack_a, stack_b);
			if (bubble_ret == 0)
			{
				ind_a++;
				min_a++;			
			}
			else if (bubble_ret == 1)
			{
				ind_a++;		
			}
		}
		if (direction == -1)
		{
			// do_instruction(instruction, "rra\n", stack_a, stack_b);
			if (bubble_ret == 0)
			{
				ind_a--;
				max_a--;			
			}
			else if (bubble_ret == 1)
			{
				ind_a--;		
			}
		}

		//break checks
		if (ind_a > max_a || ind_a < min_a)
		{
			// printf("condition 1: %i | condition 2: %i\n",ind_a > max_a,ind_a < min_a);
			break ; 
		}
		else if (max_a == min_a)
		{
			// printf("exit2\n");
			break;
		}
		//swap direction
		if (ind_a == max_a || ind_a == min_a)
			{
				ind_a--;
			//	do_instruction(instruction, "rra\n", stack_a, stack_b);
				direction *= -1;
			}
		if (direction == 1)
			do_instruction(instruction, "ra\n", stack_a, stack_b);
		else
			do_instruction(instruction, "rra\n", stack_a, stack_b);

	}






	return(instruction);
}