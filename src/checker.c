/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:39:18 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/16 08:39:21 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>



int isduplicate(int num, t_stack *stack_x)
{
	t_list *node;

	if (stack_x && stack_x->start)
	{
		node = stack_x->start;
		while (node)
		{
			if (num == *(int *)(node->content))
				return (1);
			node = node->next;
		}
	}
	return (0);
}

int make_stack(char **num_str, int num_nums, t_stack *stack_a)
{
	int		*num;
	int		i;
	t_list	*node;

	i = 0;
	while (i < num_nums)
	{
		num = (int *)ft_memalloc(sizeof(int));
		*num = ft_atoi_long(num_str[i]);
		if ((*num == 0 && ft_strcmp(num_str[i], "0") != 0) 
					|| isduplicate(*num, stack_a))
			return (-1);
		node = ft_lstnew(num, sizeof(int));
		ft_stackqueue(stack_a, node);
		i++;
	}
	return(1);
}

int ft_countstr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);	
}

int main(int argc, char **argv)
{
	int		num_nums;
	char	**num_str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack_a->length = 0;
	stack_a->start = NULL;
	stack_b = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack_b->length = 0;
	stack_b->start = NULL;

	if (argc == 1) 
	{
		//actually dont, do a gnl loop to wait for input. Actually idk
		return(ret_newl());
	}
	else if (argc == 2)
	{
		num_str = ft_strsplit(argv[1], ' ');
		num_nums = ft_countstr(num_str);
	}
	else
	{
		num_str = argv + 1;
		num_nums = argc - 1;
	}

	printf("num of nums %i\n", num_nums);
	if (make_stack(num_str, num_nums, stack_a) == -1)
		return(ret_error());
	printf("stack length: %zu\n", stack_a->length);
	print_stacks(stack_a, stack_b);
	if (instructions_loop(stack_a, stack_b) == -1)
		return(ret_error());
	return (0);
}

