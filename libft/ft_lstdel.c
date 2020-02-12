/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:27:21 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/28 15:07:38 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_one;

	if (!alst || !del || !*alst)
		return ;
	while (*alst)
	{
		next_one = (**alst).next;
		ft_lstdelone(alst, del);
		*alst = next_one;
	}
}
