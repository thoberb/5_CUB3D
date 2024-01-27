/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:20:38 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/29 14:24:59 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

//to duplicate the string
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	lenth;
	size_t	i;

	lenth = ft_strlen(s);
	dup = (char *)malloc((lenth + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (i < lenth)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
