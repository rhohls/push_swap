/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:32:18 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/31 07:33:38 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	instruct_len(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return (i);
}
