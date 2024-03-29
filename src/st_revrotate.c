/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:53:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/13 09:53:34 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** serve a push a
*/

void	st_revrotate(t_stack *stack_x)
{
	t_list *node;

	if (stack_x->length > 0)
	{
		node = ft_stackserve(stack_x);
		ft_stackpush(stack_x, node);
	}
}

void	st_revrotate_two(t_stack *stack_x, t_stack *stack_y)
{
	st_revrotate(stack_x);
	st_revrotate(stack_y);
}
