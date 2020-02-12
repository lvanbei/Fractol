/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:23:25 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/09 16:11:49 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*cast_s;
	char		*dest;

	i = 0;
	cast_s = (char*)s;
	dest = (char*)malloc(sizeof(char) * ft_strlen(cast_s) + 1);
	if (dest == NULL)
		return (0);
	while (cast_s[i])
	{
		dest[i] = cast_s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
