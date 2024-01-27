/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:19:54 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:19:56 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmpptr;
	t_list	*newlist;

	newlist = malloc(sizeof(*newlist));
	if (!lst || !newlist || !del || !(*f))
		return (NULL);
	tmpptr = newlist;
	while (lst)
	{
		tmpptr->content = (*f)(lst->content);
		if (lst->next)
		{
			tmpptr->next = malloc(sizeof(*tmpptr));
			if (tmpptr->next == NULL)
			{
				ft_lstdelone(newlist, (*del));
				return (NULL);
			}
		}
		lst = lst->next;
		if (lst)
			tmpptr = tmpptr ->next;
	}
	tmpptr->next = NULL;
	return (newlist);
}

/*int main()
{
	t_list *newlist;

	newlist->content = ft_lstnew("ceci est un test\n");
	newlist->content = ft_lstnew("ceci est un test\n");
	newlist->content = ft_lstnew("ceci est un test\n");
	newlist->content = ft_lstnew("ceci est un test\n");
	newlist->content = ft_lstnew("ceci est un test\n");

	while (newlist)
	{
		printf(newlist->content);
		newlist = newlist->next;
	}
}*/
