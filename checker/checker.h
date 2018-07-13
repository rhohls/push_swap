/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:33:00 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/12 07:34:47 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../libft/includes/libft.h"

typedef struct	s_stack
{
    int			*nums;
    int			length;
}				t_stack;

typedef struct	s_checker
{
	t_stack		stack_a;
	t_stack		stack_b;
}				t_checker;

#endif
