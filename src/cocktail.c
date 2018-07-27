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



int	shake(t_cocktail *cocktail, t_stack *stack_x)
{
	int bubble_count = 1;

	cocktail->bubble_ret = bubble_bool(stack_x, cocktail->direction);
	// printf("bubble return == %i \n",bubble_ret_a);
	// printf("min %i | max %i | current %i  -- direction_a %i\n", min_a,max_a, ind_a, direction);
	// ft_putstr("and stacks:\n");
	// print_stacks(stack_a, stack_b);

	//swap and counter
	if (cocktail->bubble_ret == 1)
		bubble_count = 1;
	else 
		bubble_count++;

	// incr depend direction
	// adj min as needed
	if (cocktail->direction == 1)
	{
		cocktail->ind++;
		if (cocktail->ind == cocktail->max)
		{
			cocktail->max -= bubble_count;
			cocktail->ind--;
			cocktail->direction *= -1;
		}
	}
	else
	{
		cocktail->ind--;
		if (cocktail->ind == cocktail->min)
		{
			cocktail->ind++;
			cocktail->min += bubble_count;
			cocktail->direction *= -1;
		}
	}
	// exit loop
	if (cocktail->max <= cocktail->min)
	{
		printf("exit2\n");
		cocktail->exit = 1;
	}
	// rotate for direction
	if (cocktail->direction == 1)
		return(1);
	else
		return(0);	
}

void init_cocktail(t_cocktail *cocktail, t_stack *stack_x)
{
	cocktail->max = (int)(stack_x->length) - 1;
	cocktail->direction = 1;
	cocktail->min = 0;
	cocktail->ind = 0;
	cocktail->bubble_count = 0;
	cocktail->exit = 0;
}

int		mix(t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
	t_cocktail cocktail_a;
	t_cocktail cocktail_b;
	int shake_ret_a; 
	int shake_ret_b;

	init_cocktail(&cocktail_a, stack_a);
	init_cocktail(&cocktail_b, stack_b);


	while(!cocktail_a.exit && !cocktail_b.exit)
	{
		shake_ret_a = shake(&cocktail_a, stack_a);
		shake_ret_b = shake(&cocktail_b, stack_b);
		
		// printf("bubble return == %i \n",cocktail_a.bubble_ret);
		// printf("min %i | max %i | current %i  -- direction %i\n", cocktail_a.min, cocktail_a.max, cocktail_a.ind, cocktail_a.direction);
		// ft_putstr("and stacks:\n");
		// print_stacks(stack_a, stack_b);

		if (cocktail_a.bubble_ret && cocktail_b.bubble_ret)
			do_instruction(instruction, "ss\n", stack_a, stack_b);
		else
		{
			if (cocktail_a.bubble_ret)
				do_instruction(instruction, "sa\n", stack_a, stack_b);
			if (cocktail_b.bubble_ret)
				do_instruction(instruction, "sb\n", stack_a, stack_b);		
		}


		if (shake_ret_a && shake_ret_b)
			do_instruction(instruction, "rr\n", stack_a, stack_b);
		else if (!shake_ret_a && !shake_ret_b)
			do_instruction(instruction, "rrr\n", stack_a, stack_b);
		else
		{
			//this is bad and we should run till they both the same direction !!
			if (shake_ret_a)
				do_instruction(instruction, "ra\n", stack_a, stack_b);
			else
				do_instruction(instruction, "rra\n", stack_a, stack_b);

			if (shake_ret_b)
				do_instruction(instruction, "rb\n", stack_a, stack_b);
			else
				do_instruction(instruction, "rrb\n", stack_a, stack_b);
		}
		
	}
	print_stacks(stack_a, stack_b);
	return (1);
}


//-------------------------------- //

t_list *cocktail(t_list * instruction,t_stack *stack_a, t_stack *stack_b)
{
	// do_instruction(instruction, "pb\n", stack_a, stack_b);
	// do_instruction(instruction, "pb\n", stack_a, stack_b);	
	// odd = (stack_a->length % 2 == 0) ? 0 : 1;


	t_cocktail cocktail;

	cocktail.max = (int)(stack_a->length) - 1;
	cocktail.direction = 1;
	cocktail.min = 0;
	cocktail.ind = 0;
	cocktail.bubble_count = 0;
	cocktail.exit = 0;


	mix(instruction, stack_a, stack_b);


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