/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:20:43 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:20:44 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strjoin_all(char **strs, char c)
{
	char	*str;
	int		i;
	size_t	j;
	size_t	k;
	size_t	len;

	i = 0;
	len = 0;
	while (strs[i])
		len += ft_strlen(strs[i++]) + 1;
	str = malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	i = -1;
	k = 0;
	while (strs[++i])
	{
		j = 0;
		while (strs[i][j])
			str[k++] = strs[i][j++];
		if (strs[i + 1])
			str[k++] = c;
	}
	str[k] = '\0';
	return (str);
}
