/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:11 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:22:13 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		if (ft_putchar_fd('-', fd))
			return (EXIT_FAILURE);
	}
	if (nb >= 10)
	{
		if (ft_putnbr_fd(nb / 10, fd))
			return (EXIT_FAILURE);
		if (ft_putnbr_fd(nb % 10, fd))
			return (EXIT_FAILURE);
	}
	else
	{
		if (ft_putchar_fd((nb + 48), fd))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
