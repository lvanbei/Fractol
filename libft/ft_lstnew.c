/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:35:49 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/16 16:46:47 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	if (content == NULL)
	{
		(*new).content = NULL;
		(*new).content_size = 0;
	}
	else
	{
		(*new).content = (t_list*)malloc(content_size * sizeof(t_list));
		if ((*new).content == 0)
			return (0);
		ft_memcpy((*new).content, content, content_size);
		(*new).content_size = content_size;
	}
	(*new).next = 0;
	return (new);
}
