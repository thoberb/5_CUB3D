/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:20:11 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:20:13 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static char	*ft_print_type(int type)
{
	if (type == CMD)
		return ("CMD");
	else if (type == ARG)
		return ("ARG");
	else if (type == REDIR)
		return ("REDIR");
	else if (type == FILES)
		return ("FILES");
	else if (type == PIPE)
		return ("PIPE");
	else
		return ("UNKNOWN");
}

void	ft_lst_print_type(t_list *lst)
{
	if (lst == NULL)
		ft_putendl_fd("(null)", 1);
	while (lst)
	{
		printf("%s | %s | not_expend = %d\n", lst->content, \
				ft_print_type(lst->type), lst->not_expend);
		lst = lst->next;
	}
}
