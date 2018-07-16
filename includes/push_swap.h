/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:02:49 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/16 07:04:45 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define INT_MIN -2147483648

void    st_push(t_stack *stack_from, t_stack *stack_to);
void    st_revrotate(t_stack *stack_x);
void    st_rotate(t_stack *stack_x);
void    st_swap(t_stack *stack_x);

void    st_revrotate_two(t_stack *stack_x, t_stack *stack_y);
void    st_rotate_two(t_stack *stack_x, t_stack *stack_y);
void    st_swap_two(t_stack *stack_x, t_stack *stack_y);

void    print_stacks(t_stack *stack_a, t_stack *stack_b);
void	compare(t_stack *stack_a, t_stack *stack_b);

void    ret_ko(void);
void    ret_ok(void);
int		ret_error(void);

#endif