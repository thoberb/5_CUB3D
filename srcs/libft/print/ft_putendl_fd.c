/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:05 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:22:06 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (ft_putstr_fd(s, fd))
		return (EXIT_FAILURE);
	if (ft_putchar_fd('\n', fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
