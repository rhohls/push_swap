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
	int		num;
	int		i;
	t_list	*node;

	i = 0;
	while (i < num_nums)
	{
		num = ft_atoi_long(num_str[i]);
		if ((num == 0 && ft_strcmp(num_str[i], "0") != 0)
					|| isduplicate(num, stack_a))
			return (-1);
		node = ft_lstnew(&num, sizeof(int));
		ft_stackqueue(stack_a, node);
		i++;
	}
	return (1);
}

void		adj_intflags(char **flag_str, t_psflags *flags, t_psinitvar *var)
{
	while (1)
	{
		if (var->num_str[0][0] == '-')
		{
			flag_str = var->num_str;
			if (flag_str[0][1] == 'v')
				flags->debug = 1;
			else if (flag_str[0][1] == 'c')
				flags->colour = 1;
			else if (flag_str[0][1] == 'f')
			{
				flags->file = 1;
				flags->file_loc = flag_str[1];
				var->num_nums--;
				var->num_str++;
			}
			else
				continue ;
			var->num_nums--;
			var->num_str++;
		}
		else
			break ;
	}
}

void		init_flags(t_psinitvar *var, t_psflags *flags)
{
	int		i;

	i = 0;
	flags->debug = 0;
	flags->file = 0;
	flags->colour = 0;
	flags->file_loc = NULL;
	if (var->num_str[i][0] == '-')
	{
		adj_intflags(var->num_str, flags, var);
	}
}

void		init_nums(t_psinitvar *var, t_psflags *flags)
{
	if (var->argc == 2)
	{
		var->num_str = ft_strsplit(var->argv[1], ' ');
		var->num_nums = ft_strcount(var->num_str);
	}
	else
	{
		var->num_str = var->argv + 1;
		var->num_nums = var->argc - 1;
	}
	init_flags(var, flags);
}
