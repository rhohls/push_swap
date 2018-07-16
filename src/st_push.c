/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:39:51 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/13 09:40:13 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pop a push b

#include "../includes/push_swap.h"

void st_push(t_stack *stack_from, t_stack *stack_to)
{
    t_list *node;

    if (stack_from->length >= 1)
	{
    	node = ft_stackpop(stack_from);
    	ft_stackpush(stack_to, node);
	}
}