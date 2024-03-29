/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:40:27 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/13 09:40:38 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** pop a queue a
*/

void	st_rotate(t_stack *stack_x)
{
	t_list *node;

	if (stack_x->length > 0)
	{
		node = ft_stackpop(stack_x);
		ft_stackqueue(stack_x, node);
	}
}

void	st_rotate_two(t_stack *stack_x, t_stack *stack_y)
{
	st_rotate(stack_x);
	st_rotate(stack_y);
}
