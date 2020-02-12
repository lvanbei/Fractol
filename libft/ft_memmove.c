/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:21:52 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/16 15:10:56 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src_cast;
	char		*dest_cast;

	i = 0;
	dest_cast = (char *)dest;
	src_cast = (const char *)src;
	if (n == 0)
		return (dest_cast);
	if (dest_cast <= src_cast)
		ft_memcpy(dest, src, n);
	else
		while (n-- > 0)
			dest_cast[n] = src_cast[n];
	return (dest_cast);
}
