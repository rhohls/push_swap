/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 11:46:09 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/12 11:46:10 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void st_swap(t_stack *stack)
{
    int temp;
    if (stack->length > 2)
    {
        temp = stack->nums[0];
        stack->nums[0] = stack->nums[1];
        stack->nums[1] = temp;       
    }
}

void st_pop