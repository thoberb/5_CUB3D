/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:36 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:22:37 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

//to find the char c in the string
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	lenth;

	lenth = ft_strlen(s);
	i = 0;
	while (i <= lenth)
	{
		if (s[i] == (unsigned char)c)
			return (((char *)s) + i);
		i++;
	}
	return (0);
}
