/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:22:49 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/08 17:42:45 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*cast_src;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cast_src = (char *)src;
	while (dest[i])
		i++;
	while (cast_src[j])
	{
		dest[i] = cast_src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
