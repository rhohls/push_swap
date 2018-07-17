/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:39:21 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/16 11:39:23 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void compare(t_stack *stack_a, t_stack *stack_b)
{
    
    t_list *lst_a;
	int		num;
    int     num_old;
    
    if (stack_b->start != NULL)
        return (ret_ko());
	lst_a = stack_a->start;
    num = INT_MIN;

	while (lst_a)
	{
        num_old = num;
        num = *(int *)(lst_a->content);
        if (num < num_old)
            return (ret_ko());
        lst_a = lst_a->next;
    } 
    return (ret_ok());
}