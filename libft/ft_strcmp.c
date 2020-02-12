/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:23:07 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/15 18:59:56 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;
	int				i;

	cast_s1 = (unsigned char*)s1;
	cast_s2 = (unsigned char*)s2;
	i = 0;
	while (cast_s1[i] || cast_s2[i])
	{
		if (cast_s1[i] != cast_s2[i])
			return (cast_s1[i] - cast_s2[i]);
		i++;
	}
	return (0);
}
