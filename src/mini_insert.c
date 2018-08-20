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
	
// int		stack_sorted_anyorder(t_stack *stack_a)
// {
// 	t_list	*lst_a;
// 	int		num;
// 	int		num_old;
// 	int		count;

// 	count = 0;
// 	lst_a = stack_a->start;
// 	num = INT_MIN;
// 	while (lst_a)
// 	{
// 		num_old = num;
// 		num = *(int *)(lst_a->content);
// 		if (num < num_old)
// 		{
// 			count++;
// 			if (count > 1)
// 				return (0);
// 		}
// 		lst_a = lst_a->next;
// 	}
// 	if (*(int *)(stack_a->start->content) < num)
// 	{
// 		count++;
// 		if (count > 1)
// 			return (0);
// 	}	
// 	return (1);
// }

t_list *insert_loop(t_stack *stack_a, t_stack *stack_b, t_list *instruction)
{
	while (!stack_sorted_anyorder(stack_a))
	{
		rot_min_a(instruction, stack_a, stack_b);
		do_instruction(instruction, "pb\n", stack_a, stack_b);
	}
	return (instruction);
}

void	ft_lstfreeone(t_list **alst)
{
	// if ((*alst)->content)
	// 	free((*alst)->content);
	free((void **)alst);
}

void	ft_lstfree(t_list **alst)
{
	if (alst)
	{
		if ((*alst)->next != NULL)
			ft_lstfree(&((*alst)->next));
		ft_lstfreeone(alst);
	}
}

int	mini_insert(t_stack *stack_a, t_stack *stack_b, t_psflags *flags)
{
	t_list	*instruction;
	// int		fd;
	char *line;

	instruction = ft_lstnew(NULL, 0);
	// printf("here\n");
	if (flags->debug == 1)
	{
		

		instruction = insert_loop(stack_a, stack_b, instruction);
		printf("\nstacks after insert\n");
		print_stacks(stack_a, stack_b);

		rot_min_a(instruction, stack_a, stack_b);

		instruction = merge(stack_a, stack_b, instruction);
		printf("\nstacks after merge\n");
		print_stacks(stack_a, stack_b);


	}
	else
	{

		
		get_next_line(0,&line);
		free(line);
		printf("1\n");

		instruction = insert_loop(stack_a, stack_b, instruction);

		get_next_line(0,&line);
		free(line);
		printf("2\n");

		rot_min_a(instruction, stack_a, stack_b);

		get_next_line(0,&line);
		free(line);
		printf("3\n");

		instruction = merge(stack_a, stack_b, instruction);
		get_next_line(0,&line);
		free(line);
		printf("4\n");
	}

	print_instructions(flags, instruction);
	get_next_line(0,&line);
	free(line);
	printf("5\n");

	// ft_lstfree(&instruction);
	free(instruction->content);
	free(instruction);

	get_next_line(0,&line);
	free(line);
	printf("5.5\n");	
	return (1);	
}