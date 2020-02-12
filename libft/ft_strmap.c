/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:03:37 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/26 15:37:10 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	int		i;
	char	*dest;

	i = 0;
	if (!s || !f)
		return (0);
	dest = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1);
	if (dest == 0)
		return (0);
	while (s[i])
	{
		dest[i] = (*f)(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
