/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:21:22 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/09 15:28:10 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src_cast;
	unsigned char		*dest_cast;
	unsigned char		ch;

	i = 0;
	dest_cast = (unsigned char *)dest;
	src_cast = (const unsigned char *)src;
	ch = (unsigned char)c;
	while (i < n)
	{
		dest_cast[i] = src_cast[i];
		if (src_cast[i] == ch)
			return (dest_cast + i + 1);
		i++;
	}
	return (0);
}
