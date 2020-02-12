/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:27:32 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/16 16:40:55 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (0);
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > i)
		j--;
	dest = ft_strsub(s, i, (j - i + 1));
	return (dest);
}
