/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:23:16 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/15 18:59:17 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int			i;
	char		*cast_src;

	cast_src = (char*)src;
	i = 0;
	while (cast_src[i])
	{
		dest[i] = cast_src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
