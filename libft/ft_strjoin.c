/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 18:23:11 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/16 16:46:58 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dest;

	if (!s1 || !s2)
		return (0);
	dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (dest == 0)
		return (0);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
