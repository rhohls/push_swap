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

int		shake()
{
	return (1);
}
// t_cocktail *cocktail,
int	mix( t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
	t_cocktail cocktail1;

	cocktail1.max_a = (int)(stack_a->length) - 1;
	// odd = (stack_a->length % 2 == 0) ? 0 : 1;
	
	cocktail1.direction_a = 1;
	cocktail1.min_a = 0;
	cocktail1.ind_a = 0;
	
	cocktail1.bubble_count = 0;
	cocktail1.a_exit = 0;

	t_cocktail *cocktail = &cocktail1;


	int bubble_count = 1;
	//swap and counter
	if (bubble_bool(stack_a, cocktail->direction_a) == 1)
	{
		bubble_count = 1;
		do_instruction(instruction, "sa\n", stack_a, stack_b);
	}
	else 
		bubble_count++;

	// incr depend direction
	// adj min as needed
	if (cocktail->direction_a == 1)
	{
		cocktail->ind_a++;
		if (cocktail->ind_a == cocktail->max_a)
		{
			cocktail->max_a--;
			cocktail->direction_a *= -1;
		}
	}
	else
	{
		cocktail->ind_a--;
		if (cocktail->ind_a == cocktail->min_a)
		{
			cocktail->ind_a++;
			cocktail->min_a += bubble_count;
			cocktail->direction_a *= -1;
		}
	}
	// exit loop
	if (cocktail->max_a <= cocktail->min_a)
	{
		printf("exit2\n");
		cocktail->a_exit = 1;
	}
	// rotate for direction_a
	if (cocktail->direction_a == 1)
		do_instruction(instruction, "ra\n", stack_a, stack_b);
	else
		do_instruction(instruction, "rra\n", stack_a, stack_b);

	return(cocktail->a_exit);
}

//-------------------------------- //

t_list *cocktail(t_list * instruction,t_stack *stack_a, t_stack *stack_b)
{
	do_instruction(instruction, "pb\n", stack_a, stack_b);
	do_instruction(instruction, "pb\n", stack_a, stack_b);	
	
	int exit1 = 1;

	while(!exit1)
	{
		exit1 = mix(instruction, stack_a, stack_b);
	}

	return(instruction);
}

/*
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
	
	int bubble_ret_a;	//1 is a only		2 is b only		3 is both		0 is nothing


	// printf("stacks for starting\n");
	// print_stacks(stack_a, stack_b);

	int first = 1;

	while(1)
	{
		// ft_putstr("Stacks before swap:\n");
		// print_stacks(stack_a, stack_b);

		bubble_ret_a = bubble_bool(stack_a, direction);
		if (bubble_ret_a == 1)
			do_instruction(instruction, "sa\n", stack_a, stack_b);

		printf("bubble return == %i \n",bubble_ret_a);
		printf("min %i | max %i | current %i  -- direction %i\n", min_a,max_a, ind_a, direction);
		ft_putstr("and stacks:\n");
		print_stacks(stack_a, stack_b);

		if (direction == 1)
		{
			// do_instruction(instruction, "ra\n", stack_a, stack_b);
			if (bubble_ret_a == 0)
			{
				// if (!first && ind_a == min_a)
				// 	min_a++;
				ind_a++;
			}
			else if (bubble_ret_a == 1)
			{
				ind_a++;		
			}
			
			if (ind_a == max_a)
			{
				max_a--;
				direction *= -1;
				first = 0;
			}
		}
		if (direction == -1)
		{
			// do_instruction(instruction, "rra\n", stack_a, stack_b);
			if (bubble_ret_a == 0)
			{	
				// if (ind_a == max_a)	
				// 	max_a--;
				ind_a--;			
			}
			else if (bubble_ret_a == 1)
			{
				ind_a--;		
			}

			if (ind_a == min_a)
			{
				ind_a++;
				min_a++;
				direction *= -1;
			}
		}
		// printf("min %i | max %i | current %i  -- direction %i\n", min_a,max_a, ind_a, direction);
		//break checks
		if (ind_a > max_a || ind_a < min_a)
		{
			printf("exit 1  \ncondition 1: %i | condition 2: %i\n",ind_a > max_a,ind_a < min_a);
			break ; 
		}
		else if (max_a == min_a)
		{
			printf("exit2\n");
			break;
		}
		//swap direction
		// if (ind_a == max_a || ind_a == min_a)
		// {
		// 	printf("min %i | max %i | current %i  -- direction %i\n", min_a,max_a, ind_a, direction);
		// 	if (direction == -1)
		// 		ind_a--;
		// //	do_instruction(instruction, "rra\n", stack_a, stack_b);
		// 	direction *= -1;
		// }
		if (direction == 1)
		{
			do_instruction(instruction, "ra\n", stack_a, stack_b);
		}
		else
		{
			do_instruction(instruction, "rra\n", stack_a, stack_b);
		}
	}

	return(instruction);
}*/