/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:09:27 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/11/07 16:09:31 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t		i;
	char		*cast_s;
	char		*dest;

	i = 0;
	cast_s = (char*)s;
	dest = (char*)malloc(sizeof(char) * ft_strlen(cast_s) + 1);
	if (dest == NULL)
		return (0);
	while (cast_s[i] && i < n)
	{
		dest[i] = cast_s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
