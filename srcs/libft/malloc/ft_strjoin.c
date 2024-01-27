/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:20:49 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:20:50 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

//to joint two string
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = (char *)ft_calloc((len1 + len2 + 1), sizeof(char));
	if (!s)
		return (NULL);
	(void)ft_strlcat(s, s1, (len1 + 1));
	(void)ft_strlcat(s, s2, (len1 + len2 + 1));
	return (s);
}
