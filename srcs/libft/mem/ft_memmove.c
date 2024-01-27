/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:21:48 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:21:49 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

//to copy the source in the dest
//but if you have the dest more big than the source
//we need to cpy at the last
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n)
		{
			n--;
			((char *)dest)[n] = ((const char *)src)[n];
		}
	}
	return (dest);
}
