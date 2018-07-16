/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackserve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:46:00 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/13 09:52:21 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#include <stdio.h>

t_list *ft_stackserve(t_stack *stack)
{
    t_list *node;
	t_list *previous;

	previous = NULL;
	if (stack && stack->start)
	{
		node = stack->start;
		while (node->next)
		{
			previous = node;
			node = node->next;
		}
		if (previous)
			previous->next = NULL;
		stack->length--;
		if (stack->length == 0)
			stack->start = NULL;	
	}
	else 
		return (NULL);
	return (node);
}

/*
t_list *ft_stackserve(t_stack *stack)
{
    t_list *node;
	t_list *previous;
	
	previous = NULL;
	node = stack->start;
	if (stack && stack->length > 0)
	{
		while (node && node->next)
		{
			node = node->next;
			if (node->next)
				previous = node;
		}
		if (previous)
			previous->next = NULL;
		node->next = NULL;
		stack->length--;
		if (stack->length == 0)
			stack->start = NULL;
	}
	else
		node = NULL;
	return (node);
}
*/