/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:21:05 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/14 10:21:06 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	findbeg(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && is_set(set, s1[i]) == 1)
		i++;
	return (i);
}

int	returnindex(char const *s1, char const *set, int index)
{
	int	i;

	i = index;
	while (s1[i])
		i++;
	i--;
	while (i >= 0 && is_set(set, s1[i]) == 1 && i >= index)
		i--;
	if (i == index)
		return (ft_strlen(s1) - index);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*newstr;
	int		a;
	int		j;

	a = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = findbeg(s1, set);
	j = returnindex(s1, set, i);
	if (j < i)
		return (NULL);
	newstr = ft_calloc((j - i) + 2, sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s1[i] && i <= j)
	{
		newstr[a] = s1[i];
		i++;
		a++;
	}
	newstr[a] = '\0';
	return (newstr);
}
