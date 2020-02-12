/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:22:55 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/08 17:45:44 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cast_s;
	int		i;

	cast_s = (char*)s;
	i = 0;
	while (cast_s[i])
	{
		if (cast_s[i] == c)
			return (cast_s + i);
		i++;
	}
	if (!c && cast_s[i] == '\0')
		return (cast_s + i);
	return (0);
}
