/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 23:09:38 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/08/17 23:09:38 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int result;

	result = 1;
	if (nb < 0)
		return (0);
	while (result * result < nb && result <= 46340)
	{
		result++;
	}
	if (result * result != nb)
		return (0);
	else
		return (result);
}
