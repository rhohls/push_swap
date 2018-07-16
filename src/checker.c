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

void gnl_loop(t_stack *stack_a, t_stack *stack_b)
{
	int fd;
	char *line;

	fd = 1;
	//printf("sa\n");
	while(get_next_line(fd, &line))
	{
		printf("\n");

		if (ft_strcmp(line, "sa") == 0)
			st_swap(stack_a);
		else if (ft_strcmp(line, "sa") == 0)
			st_swap(stack_a);

		print_stacks(stack_a, stack_b);
		printf("\n");
		free(line);
	}
}


int main(int argc, char **argv)
{
	int		i;
	int		*num;
	t_list	*node;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack_a->length = 0;
	stack_a->start = NULL;

	stack_b = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack_b->length = 0;
	stack_b->start = NULL;

	i = 1;
	while (i < argc)
	{
		//printf("at arg %i ");
		num = (int *)ft_memalloc(sizeof(int));
		*num = ft_atoi(argv[i]);
		node = ft_lstnew(num, sizeof(int));
		ft_stackqueue(stack_a, node);
		i++;
	}
	print_stacks(stack_a, stack_b);
	gnl_loop(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	return (0);
}

