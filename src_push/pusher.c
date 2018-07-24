/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:57:13 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/17 10:57:17 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
//	int		num_nums;
//	char	**num_str;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_psinitvar inits;
	t_psflags	flags;

	if (argc == 1)
		return (ret_newl());

	inits.argc = argc;
	inits.argv = argv;
	init_nums(&inits, &flags);

	stack_a = ft_stacknew();
	stack_b = ft_stacknew();
	if (make_stack(inits.num_str, inits.num_nums, stack_a) == -1)
		return (ret_error());

	//print_stacks(stack_a, stack_b);

	if (pushswap_loop(stack_a, stack_b, &flags) == -1)
		return (ret_error());
	if (flags.debug == 1)
	{
		printf("\nfinal stacks\n");
		print_stacks(stack_a, stack_b);
	}
	return (0);
}
