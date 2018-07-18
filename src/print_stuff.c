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

static t_list	*print_it(t_list *lst_x)
{
	int		*num_x;

	num_x = (int *)(lst_x->content);
	ft_putnbr(*num_x);
	return (lst_x->next);
}

void			print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = stack_a->start;
	lst_b = stack_b->start;
	while (lst_a || lst_b)
	{
		if (lst_a)
			lst_a = print_it(lst_a);
		else
			ft_putstr(" ");
		ft_putstr(" ");
		if (lst_b)
			lst_b = print_it(lst_b);
		else
			ft_putstr("   ");
		ft_putstr("\n");
	}
	ft_putstr("-  -\na  b\n\n");
	return ;
}
