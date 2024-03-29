/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:02:49 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/03 10:25:16 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "./push_swap_struct.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

void	st_push(t_stack *stack_from, t_stack *stack_to);
void	st_revrotate(t_stack *stack_x);
void	st_rotate(t_stack *stack_x);
void	st_swap(t_stack *stack_x);
void	st_revrotate_two(t_stack *stack_x, t_stack *stack_y);
void	st_rotate_two(t_stack *stack_x, t_stack *stack_y);
void	st_swap_two(t_stack *stack_x, t_stack *stack_y);

int		make_stack(char **num_str, int num_nums, t_stack *stack_a);
void	init_nums(t_psinitvar *var, t_psflags *flags);

void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	compare(t_stack *stack_a, t_stack *stack_b);
int		instructions_loop(t_stack *stack_a, t_stack *stack_b, t_psflags *flags);
void	print_instructions(t_psflags *flags, t_list *instruction);

void	ret_ko(void);
void	ret_ok(void);
int		ret_error(void);
int		ret_newl(void);

int		instruct_len(char *str);
int		pushswap_loop(t_stack *stack_a, t_stack *stack_b, t_psflags *flags);

void	exec_instructions(char *str, t_stack *stack_a, t_stack *stack_b);
void	add_instruction(t_list *instruction, char *str);
void	do_instruction(t_list *instruction, char *str, t_stack *stack_a,
						t_stack *stack_b);

t_list	*rot_min(t_list *instruction, t_stack *stack_a, t_stack *stack_b);
t_list	*merge(t_stack *stack_a, t_stack *stack_b, t_list *instruction);

int		bubble_bool(t_stack *stack_x, int direction);
int		one_bubble(t_list *instruction, t_stack *stack_a, t_stack *stack_b,
					int direction);
t_list	*push_half(t_stack *stack_a, t_stack *stack_b);

t_list	*double_bubble(t_list *instruction, t_stack *stack_a, t_stack *stack_b);
t_list	*cocktail(t_list *instruction, t_stack *stack_a, t_stack *stack_b);
void	remove_rr(t_list *instruction, t_stack *stack_a, t_stack *stack_b);

t_list	*rot_min_a(t_list *instruction, t_stack *stack_a, t_stack *stack_b);


int	mini_insert(t_stack *stack_a, t_stack *stack_b, t_psflags *flags);
int		stack_sorted_anyorder(t_stack *stack_a);
int		insert(t_stack *stack_a, t_stack *stack_b, t_psflags *flags);
 t_list *rot_max_b(t_list *instruction, t_stack *stack_a, t_stack *stack_b);

#endif
