/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:18:26 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:18:28 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

//the fonction for white space and space
static int	ft_is_white_space(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == ' ')
		return (1);
	return (0);
}

//ascii to ssize_t, we need to take a string
//he can have the white space and one - or +
//and we need to multiply by ten because it's ten base
ssize_t	ft_atoi_long(const char *nptr)
{
	int			i;
	ssize_t		n;
	int			signe;

	i = 0;
	n = 0;
	signe = 1;
	while (ft_is_white_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = (n * 10) + nptr[i] - 48;
		i++;
	}
	return (signe * n);
}
