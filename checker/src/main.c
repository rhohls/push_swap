/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:32:18 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/12 07:32:21 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

#include <stdio.h>
#include <stdlib.h>

void init_stacks(int argc, char **argv, int *stack_a, int *stack_b)
{
    int i;
    int num_nums;

    num_nums = argc - 1;
    i = 0;
    while (i < num_nums)
    {
        stack_a[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    i = 0;
    while (i < num_nums)
    {
        stack_b[i] = 0;
        i++;
    }       
}

int main(int argc, char **argv)
{
    int         i;
    int         num_nums;
    t_checker   vm_var;
    num_nums = argc - 1;

    init_stacks(argc, argv, stack_a, stack_b);
    
    printf("num of num %i\n", num_nums);
    i = 0;
    while (i < num_nums)
    {
        printf("int in index %i of stack a is :%i\n", i, stack_a[i]);
        i++;
    }
    i = 0;
    while (i < num_nums)
    {
        printf("int in index %i of stack b is :%i\n", i, stack_b[i]);
        i++;
    }
    return 1;
}