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

//swap first two on stack

#include "../includes/push_swap.h"

void st_swap(t_stack *stack_x)
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
