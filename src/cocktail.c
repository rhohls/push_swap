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


// return is direction to rotate
int	shake(t_cocktail *cocktail, t_stack *stack_x)
{
	int bubble_count = 1;

	cocktail->bubble_ret = bubble_bool(stack_x, cocktail->direction);
	// printf("bubble return == %i \n",bubble_ret_a);
	// printf("min %i | max %i | current %i  -- direction_a %i\n", min_a,max_a, ind_a, direction);
	// ft_putstr("and stacks:\n");
	// print_stacks(stack_a, stack_b);

	//swap and incr counter
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
		//printf("exit2\n");
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

/*
** 0 - rra
** 1 - ra
** 2 - rrb
** 3 - rb
*/
static void cocktail_rotate(int cocktail_and_dir, t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (cocktail_and_dir == 1)
		do_instruction(instruction, "ra\n", stack_a, stack_b);
	else if (cocktail_and_dir == 0)
		do_instruction(instruction, "rra\n", stack_a, stack_b);

	else if (cocktail_and_dir == 3)
		do_instruction(instruction, "rb\n", stack_a, stack_b);
	else if (cocktail_and_dir == 2)
		do_instruction(instruction, "rrb\n", stack_a, stack_b);
}

int		mix(t_list *instruction, t_stack *stack_a, t_stack *stack_b)
{
	t_cocktail cocktail_a;
	t_cocktail cocktail_b;
	int shake_ret_a; 
	int shake_ret_b;

	init_cocktail(&cocktail_a, stack_a);
	init_cocktail(&cocktail_b, stack_b);

	printf("max a %u   -  len a %lu   -   \n", cocktail_a.max, stack_a->length);
	printf("max b %u   -  len b %lu   -   \n\n", cocktail_b.max, stack_b->length);


	while(!cocktail_a.exit && !cocktail_b.exit)
	{
		shake_ret_a = shake(&cocktail_a, stack_a);
		shake_ret_b = shake(&cocktail_b, stack_b);
		
		printf("bubble return a == %i \n",cocktail_a.bubble_ret);
		printf("min %i | max %i | current %i  -- direction %i\n", cocktail_a.min, cocktail_a.max, cocktail_a.ind, cocktail_a.direction);
		// ft_putstr("and stacks:\n");
		// print_stacks(stack_a, stack_b);

		printf("bubble return b == %i \n",cocktail_b.bubble_ret);
		printf("min %i | max %i | current %i  -- direction %i\n", cocktail_b.min, cocktail_b.max, cocktail_b.ind, cocktail_b.direction);
		// ft_putstr("and stacks:\n");
		// print_stacks(stack_a, stack_b);

		one_bubble(instruction, stack_a, stack_b, 1);

		// dprintf(2, "shake a %i, shake b %i \n", shake_ret_a, shake_ret_b);
		if (shake_ret_a != shake_ret_b)
		{
			// dprintf(2, "single shake\n");
			if ((cocktail_a.max - cocktail_a.min) > (cocktail_b.max - cocktail_b.min))
			{
				cocktail_rotate(shake_ret_a, instruction, stack_a, stack_b);
				while (shake_ret_a != shake_ret_b)
				{
					shake_ret_a = shake(&cocktail_a, stack_a);
					if (shake_ret_a == shake_ret_b)
						break ;
					cocktail_rotate(shake_ret_a, instruction, stack_a, stack_b);
				}
			}
			else 
			{
				cocktail_rotate(shake_ret_b + 2, instruction, stack_a, stack_b);
				while (shake_ret_a != shake_ret_b)
				{
					shake_ret_b = shake(&cocktail_b, stack_b);
					if (shake_ret_a == shake_ret_b)
						break ;
					cocktail_rotate(shake_ret_b + 2, instruction, stack_a, stack_b);
				}
			}
		}

		if (shake_ret_a && shake_ret_b)
			do_instruction(instruction, "rr\n", stack_a, stack_b);
		else if (!shake_ret_a && !shake_ret_b)
			do_instruction(instruction, "rrr\n", stack_a, stack_b);
		
	}
	//print_stacks(stack_a, stack_b);
	return (1);
}


//-------------------------------- //

t_list *cocktail(t_list * instruction,t_stack *stack_a, t_stack *stack_b)
{
	// do_instruction(instruction, "pb\n", stack_a, stack_b);
	// do_instruction(instruction, "pb\n", stack_a, stack_b);	
	// odd = (stack_a->length % 2 == 0) ? 0 : 1;

	mix(instruction, stack_a, stack_b);


	return(instruction);
}

int	cocktail_sort(t_stack *stack_a, t_stack *stack_b, t_psflags *flags)
{
	t_list	*instruction;
	int		fd;

	instruction = ft_lstnew(NULL, 0);

	if (flags->debug == 1)
	{
		instruction = push_half(stack_a, stack_b);
		printf("String of commands push half\n");
		ft_putstr(instruction->content);
		printf("\nstacks after push half\n");
		print_stacks(stack_a, stack_b);

		// instruction = cocktail(instruction, stack_a, stack_b);
		// printf("String of commands after cocktail\n");
		// ft_putstr(instruction->content);
		// printf("\nstacks after double cocktail\n");
		// print_stacks(stack_a, stack_b);

		instruction = double_bubble(instruction, stack_a, stack_b);
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
		instruction = push_half(stack_a, stack_b);
		// instruction = cocktail(instruction, stack_a, stack_b);
		instruction = double_bubble(instruction, stack_a, stack_b);
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
	if (flags->debug == 1)
		printf("\nLength of instructions = %i", instruct_len(instruction->content));
	
	return (1);	
}