/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:25:23 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/15 21:34:02 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < len)
		return (src_len + size);
	dst_len = len;
	while (src[i] && (size - 1) > len)
		dest[len++] = src[i++];
	dest[len] = '\0';
	len = dst_len + src_len;
	return (len);
}
