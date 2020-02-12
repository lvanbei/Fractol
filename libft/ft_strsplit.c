/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:35:34 by lvan-bei          #+#    #+#             */
/*   Updated: 2019/01/22 15:38:31 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		count;
	char	**tab;

	if (!s)
		return (NULL);
	count = ft_strnword((char*)s, c);
	tab = (char**)malloc(sizeof(char*) * count + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (count--)
	{
		while (*s == c && *s)
			s++;
		tab[i] = ft_strsub((char*)s, 0, ft_strlenword(s, c));
		if (tab[i] == NULL)
			return (ft_freentab(tab));
		s = s + ft_strlenword((char*)s, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
