/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:20:26 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:20:28 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

//the first if it's for to check the overflow
//and we malloc the space
//and we set all byte a zero
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb && size)
		if (nmemb * size / size != nmemb)
			return (NULL);
	s = (void *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, (nmemb * size));
	return (s);
}
