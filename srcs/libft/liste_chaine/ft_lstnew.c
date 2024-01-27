/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:20:03 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:20:05 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_list	*ft_lstnew(char *content, int type)
{
	t_list	*contenu;

	contenu = ft_calloc(sizeof(*contenu), 1);
	if (!contenu)
		return (NULL);
	contenu->content = content;
	contenu->type = type;
	contenu->next = NULL;
	return (contenu);
}

t_list	*ft_lstnew_spe(char *content, int type, bool expend, bool inquote)
{
	t_list	*contenu;

	contenu = ft_calloc(sizeof(*contenu), 1);
	if (!contenu)
		return (NULL);
	contenu->not_expend = expend;
	contenu->content = content;
	contenu->type = type;
	if (inquote == true)
		contenu->type = ARG;
	contenu->next = NULL;
	return (contenu);
}

/*int main()
{
	t_list *newlist = NULL;

	ft_lstadd_front(&newlist, ft_lstnew((void*)"180\n"));
	printf("%s", newlist->content);
	ft_lstadd_front(&newlist, ft_lstnew((void*)8));
	printf("%d", newlist->next = newlist->content);
	ft_lstadd_front(&newlist, ft_lstnew((void*)"180\n"));
	printf("%s", newlist->next = newlist->content);
}*/
