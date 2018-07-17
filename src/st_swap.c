/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:37:25 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/13 09:38:22 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** swap first two on stack
*/

void	st_swap(t_stack *stack_x)
{
	t_list *node1;
	t_list *node2;

	if (stack_x->length >= 2)
	{
		node1 = ft_stackpop(stack_x);
		node2 = ft_stackpop(stack_x);
		ft_stackpush(stack_x, node1);
		ft_stackpush(stack_x, node2);
	}
}

void	st_swap_two(t_stack *stack_x, t_stack *stack_y)
{
	st_swap(stack_x);
	st_swap(stack_y);
}
