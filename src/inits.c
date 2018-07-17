/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:11:22 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/17 09:11:24 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static int	isduplicate(int num, t_stack *stack_x)
{
	t_list	*node;

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

int			make_stack(char **num_str, int num_nums, t_stack *stack_a)
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
	return (1);
}

void		init_nums(int *num_nums, char ***num_str, int argc, char **argv)
{
	if (argc == 2)
	{
		*num_str = ft_strsplit(argv[1], ' ');
		*num_nums = ft_strcount(*num_str);
	}
	else
	{
		*num_str = argv + 1;
		*num_nums = argc - 1;
	}
}
