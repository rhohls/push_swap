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

void	ft_lstfreeone(t_list **alst)
{
	if ((*alst)->content)
	{
		free((*alst)->content);
		(*alst)->content = NULL;
	}
	free(*alst);
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

void ft_stackdel(t_stack **stack)
{
	printf("add %p\n", (*stack)->start);
	if (stack && *stack && (*stack)->start)
		ft_lstfree(&((*stack)->start));	
	free(*stack);
	stack = NULL;
}

void    ft_del_chararr(char **array, int amt)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (i < amt)
	{
		if (array[i])
		{
			printf("arr i:%d  string: %s\n", i, array[i]);
			printf("arr adress %p\n", array[i]);
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	// free(array);
	// array = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_psinitvar inits;
	t_psflags	flags;
	char *line;
	if (argc == 1)
		return (ret_newl());
		
	get_next_line(0,&line);
	free(line);


	inits.argc = argc;
	inits.argv = argv;

	get_next_line(0,&line);
	free(line);

	init_nums(&inits, &flags);

	get_next_line(0,&line);
	free(line);

	stack_a = ft_stacknew();
	stack_b = ft_stacknew();

	get_next_line(0,&line);
	free(line);

	if (make_stack(inits.num_str, inits.num_nums, stack_a) == -1)
		return (ret_error());
	
	if (flags.debug == 1)
	{
		printf("\n Starting stacks\n");
		print_stacks(stack_a, stack_b);
	}

	get_next_line(0,&line);
	free(line);
	if (mini_insert(stack_a, stack_b, &flags) == -1)
		return (ret_error());
	// get_next_line(0,&line);
	// free(line);
	// printf("6\n");
	if (flags.debug == 1)
	{
		printf("\nfinal stacks\n");
		print_stacks(stack_a, stack_b);
	}

	get_next_line(0,&line);
	free(line);

	ft_stackdel(&stack_a);
	ft_stackdel(&stack_b);

	// inits.num_str, inits.num_nums
	// ft_del_chararr(inits.num_str, inits.num_nums);

	printf("last gnl\n");
	get_next_line(0,&line);
	free(line);
	return (0);
}
