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

#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

typedef struct	s_psflags
{
	int			debug;
	int			colour;
	int			file;
	char		*file_loc;
}				t_psflags;

typedef struct	s_psinitvar
{
	int			num_nums;
	char		**num_str;
	int			argc;
	char		**argv;
}				t_psinitvar;

typedef struct	s_cocktail
{
	int			min;
	int			bubble_ret;
	int			direction;
	int			exit;
	int			max;
	int			ind;
	int			bubble_count;
}				t_cocktail;

#endif
