/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:31:47 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/16 08:31:49 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
//--- print stacks ----//
	t_list *lst_a;
	t_list *lst_b;
	int		*num_a;
	int		*num_b;
	lst_a = stack_a->start;
	lst_b = stack_b->start;

	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			num_a = (int *)(lst_a->content);
			printf("%i", *num_a);
			lst_a = lst_a->next;
		}
		else
			printf(" ");
		
		printf(" ");

		if (lst_b)
		{
			num_b = (int *)(lst_b->content);
			printf("%i", *num_b);
			lst_b = lst_b->next;
		}
		else
			printf("   ");		
		printf("\n");
	}
	printf("-  -\n");
	printf("a  b\n");
	return ;
}