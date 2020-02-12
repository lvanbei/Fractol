/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:21:40 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/15 18:50:29 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	i = 0;
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cast_s1[i] != cast_s2[i])
			return (cast_s1[i] - cast_s2[i]);
		else
			i++;
	}
	return (0);
}
