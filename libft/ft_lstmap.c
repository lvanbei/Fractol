/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 18:00:53 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/18 17:22:13 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = (*lst).next;
		ft_memdel((void**)&lst);
		lst = tmp;
	}
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*first;
	t_list		*new;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew((*lst).content, (*lst).content_size);
	if (new == NULL)
		return (NULL);
	new = (*f)(new);
	first = new;
	while ((*lst).next)
	{
		lst = (*lst).next;
		(*new).next = ft_lstnew((*lst).content, (*lst).content_size);
		if (!new)
			return (ft_free(first));
		(*new).next = (*f)((*new).next);
		new = (*new).next;
	}
	return (first);
}
