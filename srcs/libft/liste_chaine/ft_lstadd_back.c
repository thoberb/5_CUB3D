/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:18:59 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:19:02 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*in;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			in = ft_lstlast(*lst);
			in->next = new;
		}
		else
			*lst = new;
	}
}
