/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:24:22 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/16 15:27:35 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cast_s;
	int		i;
	int		j;
	int		voyant;

	cast_s = (char*)s;
	i = 0;
	j = 0;
	voyant = 0;
	while (cast_s[i])
	{
		if (cast_s[i] == c)
		{
			voyant = 1;
			j = i;
		}
		i++;
	}
	if (voyant == 1)
		return (cast_s + j);
	if (!c && cast_s[i] == '\0')
		return (cast_s + i);
	return (0);
}
