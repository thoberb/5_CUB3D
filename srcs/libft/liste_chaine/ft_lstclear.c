/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:19:15 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:19:16 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*in;

	if (!del || !*lst || !del)
		return ;
	while (*lst)
	{
		in = (*lst)->next;
		ft_lstdelone(*lst, (del));
		*lst = in;
	}
	free(*lst);
	*lst = NULL;
}

/*int main()
{
	t_list *newlist;

	newlist->content = ft_lstnew("ceci est un test\n");
	newlist->content = ft_lstnew("ceci est un test\n");
	newlist->content = ft_lstnew("ceci est un test\n");
	newlist->content = ft_lstnew("ceci est un test\n");
	newlist->content = ft_lstnew("ceci est un test\n");
	ft_lstclear()

	while (newlist)
	{
		printf(newlist->content);
		newlist = newlist->next;
	}
}*/
