/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:23:47 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/15 19:05:25 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char		*cast_s1;
	unsigned char		*cast_s2;
	size_t				i;

	cast_s1 = (unsigned char*)s1;
	cast_s2 = (unsigned char*)s2;
	i = 0;
	while ((cast_s1[i] || cast_s2[i]) && i < n)
	{
		if (cast_s1[i] != cast_s2[i])
			return (cast_s1[i] - cast_s2[i]);
		i++;
	}
	return (0);
}
