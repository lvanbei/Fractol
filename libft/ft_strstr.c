/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:24:29 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/15 19:26:50 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	char	*j;
	int		k;

	i = 0;
	j = 0;
	if (*to_find == '\0' || !to_find)
		return ((char*)str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = (char*)str + i;
			k = 0;
			while (str[i + k] == to_find[k])
			{
				if (to_find[k + 1] == '\0')
					return (j);
				k++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
