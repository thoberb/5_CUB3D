/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:55 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:22:56 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

//the strlcat need to give lenth ant cat two string, if the size are not correct
//we send the source lenth, if the size is more we can cat if it's not we send
//the lenth of the source and the size
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	len_d;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	len_d = ft_strlen(dst);
	if (size > len_d)
	{
		len += len_d;
		if (size > len)
			size = len + 1;
		i = 0;
		while (i < size - len_d - 1)
		{
			dst[i + len_d] = src[i];
			i++;
		}
		dst[i + len_d] = 0;
	}
	else
		len += size;
	return (len);
}
