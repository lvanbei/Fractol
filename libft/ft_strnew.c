/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:06:50 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/15 19:06:56 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *dest_alloc;

	dest_alloc = (char*)malloc((size * sizeof(char) + 1));
	if (dest_alloc == NULL)
		return (NULL);
	ft_memset(dest_alloc, '\0', size);
	dest_alloc[size] = '\0';
	return (dest_alloc);
}
