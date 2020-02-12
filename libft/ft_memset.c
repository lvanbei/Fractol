/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:22:01 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/18 15:51:13 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t		i;
	char		*result;

	i = 0;
	result = (char*)s;
	while (i < len)
	{
		result[i] = c;
		i++;
	}
	return (result);
}
