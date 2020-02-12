/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:21:46 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/08 17:38:02 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src_cast;
	char		*dest_cast;

	i = 0;
	dest_cast = (char *)dest;
	src_cast = (const char *)src;
	while (i < n)
	{
		dest_cast[i] = src_cast[i];
		i++;
	}
	return (dest_cast);
}
