/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:02:20 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/17 14:02:24 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_insert_list(int length)
{
	int			i;
	t_stack		*ret;
	t_insert	*node;
	t_list		*list;

	ret = ft_stacknew();
	i = length - 1;

	while (i >= 0)
	{
		node = (t_insert *)ft_memalloc(sizeof(t_insert));
		node->ind_a = i;
		node->ra = i;
		node->rra = length - i;
		list = ft_lstnew(NULL, 0);
		list->content = node;
		list->content_size = i;
		ft_stackpush(ret, list);
		i--;
	}
	return(ret);
}

void	init_insert(t_psvar	*insert, t_stack *stack_a, t_stack *stack_b)	
{
	insert->instructions = ft_lstnew(NULL, 0);
	insert->stack_a = stack_a;
	insert->stack_b = stack_b;
	insert->inserts = init_insert_list(stack_a->length);
	insert->init = 0;
}

void	get_rb(int a_val, t_insert *insert_node, t_stack *stack_b)
{
	int		curr_num;
	int		ind_b;
	t_list	*node;

	ind_b = 0;
	if (!(stack_b->start))
		return ; //fix
	node = stack_b->start->next;

	while (node)
	{
		curr_num = *(int *)(node->content);
		if (a_val > curr_num)
			break ;
		node = node->next;
		ind_b++;
	}
	printf("\ngetting b stack val on val:%d\n", a_val);
	printf("ind_b: %d, rb:%d, rrb:%d\n", (int)ind_b, (int)ind_b, (int)(stack_b->length - ind_b));
	insert_node->ind_b = ind_b;
	insert_node->rb = ind_b;
	insert_node->rrb = stack_b->length - ind_b;
}

int	index_min_array(unsigned *int_arr, int length)
{
	int				i;
	int				min_index;
	unsigned int	min;

	i = 1;
	min_index = 0;
	min = int_arr[0];
	while (i < length)
	{
		if (int_arr[i] < min)
		{
			min = int_arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

/*
** Case details:
** 0. rr + ra
** 1. rr + rb
** 2. rrr + rra
** 3. rrr + rrb
** 4. ra + rrb
** 5. rra + rb
*/
void get_move_amt(t_insert *ins)
{
	int				case_num;
	unsigned int	case_moves[6];
	//unsigned for overflow?

	case_moves[0] = (ins->ra >= ins->rb) ? ins->ra : -1;
	case_moves[1] = (ins->rb >= ins->ra) ? ins->rb : -1;
	case_moves[2] = (ins->rra >= ins->rrb) ? ins->rra : -1;
	case_moves[3] = (ins->rb >= ins->rra) ? ins->rrb : -1;
	case_moves[4] = ins->ra + ins->rrb;
	case_moves[5] = ins->rra + ins->rb;

	for (int i=0;i < 6;i++) {
    	printf("%u ",case_moves[i]);
	}printf("\n");

	case_num = index_min_array(case_moves, 6);
	ins->case_num = case_num;
	ins->net_moves = case_moves[case_num];

}

void calc_insert_data(t_psvar *insert)
{
	t_insert	*insert_var;
	t_list		*stack_node;
	t_list		*insert_node;

	stack_node = insert->stack_a->start;
	insert_node = insert->inserts->start;

	while(stack_node)
	{
		insert_var = insert_node->content;
		get_rb(*((int *)stack_node->content), insert_node->content, insert->stack_b);
		get_move_amt(insert_node->content);

		printf("node a val:%d ind:%d case:%d net:%d\n", *((int *)stack_node->content), ((t_insert *)(insert_node->content))->ind_a, 
														((t_insert *)(insert_node->content))->case_num, ((t_insert *)(insert_node->content))->net_moves);

		stack_node = stack_node->next;
		insert_node = insert_node->next;
	}
}


t_insert *min_node(t_stack *insert_list)
{
	t_insert	*ret;
	t_list		*node;
	
	node = insert_list->start;
	ret = node->content;

	

	while(node)
	{
		printf("saved net moves %d - new netmoves %d\n", ((t_insert *)(node->content))->net_moves, ret->net_moves);
		if (((t_insert *)(node->content))->net_moves < ret->net_moves)
			ret = node->content;
		node = node->next;
	}
	node = ft_stackserve(insert_list);
	//printf("node to delete has inda: %d and ra %d\n", ((t_insert *)(node->content))->ind_a, ((t_insert *)(node->content))->ra);
	printf("return node has ind: %d  case: %d  and net moves %d\n", ret->ind_a, ret->case_num, ret->net_moves);
	//free(node);
	return (ret);
}

void perform_min_moves(t_psvar *insert)
{
	t_insert	*insert_node;
	int			i;

	insert_node = min_node(insert->inserts);
	i = 0;
	if (insert_node->case_num == 0)
	{
		while (i++ < insert_node->rb)
			do_instruction(insert->instructions, "rr\n", insert->stack_a, insert->stack_b);
		while (i++ < (insert_node->ra - insert_node->rb))
			do_instruction(insert->instructions, "ra\n", insert->stack_a, insert->stack_b);	
	}
	else if (insert_node->case_num == 1)
	{
		while (i++ < insert_node->ra)
			do_instruction(insert->instructions, "rr\n", insert->stack_a, insert->stack_b);
		while (i++ < (insert_node->rb - insert_node->ra))
			do_instruction(insert->instructions, "rb\n", insert->stack_a, insert->stack_b);	
	}
	else if (insert_node->case_num == 2)
	{
		while (i++ < insert_node->rrb)
			do_instruction(insert->instructions, "rrr\n", insert->stack_a, insert->stack_b);
		while (i++ < (insert_node->rra - insert_node->rrb))
			do_instruction(insert->instructions, "rra\n", insert->stack_a, insert->stack_b);	
	}
	else if (insert_node->case_num == 3)
	{
		while (i++ < insert_node->rra)
			do_instruction(insert->instructions, "rrr\n", insert->stack_a, insert->stack_b);
		while (i++ < (insert_node->rrb - insert_node->rra))
			do_instruction(insert->instructions, "rrb\n", insert->stack_a, insert->stack_b);		
	}
	else if (insert_node->case_num == 4)
	{
		while (i++ < insert_node->ra)
			do_instruction(insert->instructions, "ra\n", insert->stack_a, insert->stack_b);
		i = 0;
		while (i++ < insert_node->rrb)
		{
			printf("doing rrb\n");
			do_instruction(insert->instructions, "rrb\n", insert->stack_a, insert->stack_b);	
		}
	}
	else if (insert_node->case_num == 5)
	{
		while (i++ < insert_node->rb)
			do_instruction(insert->instructions, "rb\n", insert->stack_a, insert->stack_b);
		i = 0;
		while (i++ < insert_node->rra)
			do_instruction(insert->instructions, "rra\n", insert->stack_a, insert->stack_b);	
	}
	do_instruction(insert->instructions, "pb\n", insert->stack_a, insert->stack_b);
}

int		stack_sorted_anyorder(t_stack *stack_a)
{
	t_list	*lst_a;
	int		num;
	int		num_old;
	int		count;

	count = 0;
	lst_a = stack_a->start;
	num = INT_MIN;
	while (lst_a)
	{
		num_old = num;
		num = *(int *)(lst_a->content);
		if (num < num_old)
		{
			count++;
			if (count > 1)
				return (0);
		}
		lst_a = lst_a->next;
	}
	if (*(int *)(stack_a->start->content) < num)
	{
		count++;
		if (count > 1)
			return (0);
	}	
	return (1);
}

int		insert(t_stack *stack_a, t_stack *stack_b, t_psflags *flags)
{
	t_psvar	insert;

	init_insert(&insert, stack_a, stack_b);
	if (stack_a->length > 2 && !(stack_sorted_anyorder(stack_a)))
	{
		do_instruction(insert.instructions, "pb\n", insert.stack_a, insert.stack_b);
		do_instruction(insert.instructions, "pb\n", insert.stack_a, insert.stack_b);
		if (*(int *)stack_b->start->content < (*(int *)stack_b->start->next->content))
			do_instruction(insert.instructions, "sb\n", insert.stack_a, insert.stack_b);
		ft_stackserve(insert.inserts);
		ft_stackserve(insert.inserts);
	}
	print_stacks(stack_a, stack_b);
	while (stack_a->length != 0)
	{

		calc_insert_data(&insert);
		perform_min_moves(&insert);
		printf("\n---------\n");
		print_stacks(stack_a, stack_b);

	}
	printf("\nsorted\n");
	print_stacks(stack_a, stack_b);

	rot_max_b(insert.instructions, stack_a, stack_b);
	printf("rotated for max on b\n");
	print_stacks(stack_a, stack_b);

	while (stack_b->length != 0)
		do_instruction(insert.instructions, "pa\n", insert.stack_a, insert.stack_b);

	print_instructions(flags, insert.instructions);
	printf("\n");
	print_stacks(stack_a, stack_b);
	return (1);
}