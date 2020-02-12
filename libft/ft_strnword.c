/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:34:04 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/20 18:34:06 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnword(char const *s, char c)
{
	int i;
	int voyant;

	i = 0;
	voyant = 0;
	while (*s)
	{
		if (*s != c && voyant == 0)
		{
			i++;
			voyant = 1;
		}
		if (*s == c && voyant == 1)
			voyant = 0;
		s++;
	}
	return (i);
}
