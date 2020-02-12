/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:34:27 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/28 18:48:34 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *dest_alloc;

	dest_alloc = (void*)malloc(size);
	if (dest_alloc == 0)
		return (0);
	ft_memset(dest_alloc, '\0', size);
	return (dest_alloc);
}
