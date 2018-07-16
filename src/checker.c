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

void instructions_loop(t_stack *stack_a, t_stack *stack_b)
{
	int fd;
	char *line;

	fd = 1;
	while(get_next_line(fd, &line))
	{
		printf("\n");

		if (ft_strcmp(line, "sa") == 0)
			st_swap(stack_a);
		else if (ft_strcmp(line, "sb") == 0)
			st_swap(stack_b);
		else if (ft_strcmp(line, "ss") == 0)
			st_swap_two(stack_a, stack_b);
		else if (ft_strcmp(line, "pa") == 0)
			st_push(stack_b, stack_a);
		else if (ft_strcmp(line, "pb") == 0)
			st_push(stack_a, stack_b);
		else if (ft_strcmp(line, "ra") == 0)
			st_rotate(stack_a);
		else if (ft_strcmp(line, "rb") == 0)
			st_rotate(stack_b);
		else if (ft_strcmp(line, "rr") == 0)
			st_rotate_two(stack_a, stack_b);
		else if (ft_strcmp(line, "rra") == 0)
			st_revrotate(stack_a);
		else if (ft_strcmp(line, "rrb") == 0)
			st_revrotate(stack_b);
		else if (ft_strcmp(line, "rrr") == 0)
			st_revrotate_two(stack_b, stack_a);
		else if (ft_strcmp(line, "quit") == 0)
			break ;
		print_stacks(stack_a, stack_b);
		printf("\n");
		free(line);
	}
	compare(stack_a, stack_b);
}

int make_stack(char **num_str, int num_nums, t_stack *stack_a, t_stack *stack_b)
{
	int		*num;
	int		i;
	t_list	*node;

	i = 0;
	while (i < num_nums)
	{
		num = (int *)ft_memalloc(sizeof(int));
		*num = ft_atoi_long(num_str[i]);
		if (*num == 0 && ft_strcmp(num_str[i], "0") != 0)
		{
			//printf("bad input\n");
			return (-1);
		}
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

//int ft_isnum

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
		return(ret_error());
	else if (argc == 2)
	{
		num_str = ft_strsplit(argv[1], ' ');
		num_nums = ft_countstr(num_str);
	}
	else if (argc > 2)
	{
		num_str = argv + 1;
		num_nums = argc - 1;
	}

	printf("num of nums %i\n", num_nums);
	if (make_stack(num_str, num_nums, stack_a, stack_b) == -1)
		return(ret_error());
	print_stacks(stack_a, stack_b);
//	instructions_loop(stack_a, stack_b);
	return (0);
}

