/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:19:45 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/17 08:19:48 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ret_ko(void)
{
	ft_putendl("KO");
}

void	ret_ok(void)
{
	ft_putendl("OK");
}

int		ret_newl(void)
{
	ft_putendl("");
	return (0);
}

int		ret_error(void)
{
	ft_putendl("ERROR");
	return (1);
}
