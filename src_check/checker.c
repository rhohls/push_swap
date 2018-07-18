/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:39:18 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/16 08:39:21 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		num_nums;
	char	**num_str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (ret_newl());
	num_nums = 0;
	num_str = NULL;
	init_nums(&num_nums, &num_str, argc, argv);
	stack_a = ft_stacknew();
	stack_b = ft_stacknew();
	if (make_stack(num_str, num_nums, stack_a) == -1)
		return (ret_error());
	print_stacks(stack_a, stack_b);
	if (instructions_loop(stack_a, stack_b) == -1)
		return (ret_error());
	return (0);
}
