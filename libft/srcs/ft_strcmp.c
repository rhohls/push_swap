/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:28:13 by rhohls            #+#    #+#             */
/*   Updated: 2018/05/25 10:20:38 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (!(*str2))
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
