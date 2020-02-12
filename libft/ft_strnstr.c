/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:24:03 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/15 19:20:57 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	k;
	char	*j;

	i = 0;
	if (*to_find == '\0' || !to_find)
		return ((char*)str);
	while (str[i] && i < n)
	{
		if (to_find[0] == str[i])
		{
			j = (char*)str + i;
			k = 0;
			while (to_find[k] == str[i + k] && i + k < n)
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
