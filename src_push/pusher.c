/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:57:13 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/17 10:57:17 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

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

		// instruction = double_bubble(instruction, stack_a, stack_b);
		// printf("String of commands after bubble\n");
		// ft_putstr(instruction->content);
		// printf("\nstacks after double bubble\n");
		// print_stacks(stack_a, stack_b);
		
		instruction = cocktail(instruction, stack_a, stack_b);
		printf("String of commands after cocktail\n");
		ft_putstr(instruction->content);
		printf("\nstacks after double cocktail\n");
		print_stacks(stack_a, stack_b);

		// remove_rr(instruction, stack_a, stack_b);
		// printf("Commands after remove RR\n");
		// ft_putstr(instruction->content);
		// printf("\nstacks after remove rr\n");
		// print_stacks(stack_a, stack_b);

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
		instruction = cocktail(instruction, stack_a, stack_b);
		// remove_rr(instruction, stack_a, stack_b);
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_psinitvar inits;
	t_psflags	flags;

	if (argc == 1)
		return (ret_newl());

	inits.argc = argc;
	inits.argv = argv;
	init_nums(&inits, &flags);

	stack_a = ft_stacknew();
	stack_b = ft_stacknew();
	if (make_stack(inits.num_str, inits.num_nums, stack_a) == -1)
		return (ret_error());
	
	if (flags.debug == 1)
	{
		printf("\n Starting stacks\n");
		print_stacks(stack_a, stack_b);
	}
	
	if (cocktail_sort(stack_a, stack_b, &flags) == -1)
		return (ret_error());
	if (flags.debug == 1)
	{
		printf("\nfinal stacks\n");
		print_stacks(stack_a, stack_b);
	}
	return (0);
}
