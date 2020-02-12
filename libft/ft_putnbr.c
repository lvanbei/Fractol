/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:22:30 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/08 17:22:31 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long	number;
	int		size;
	long	troll;

	troll = (long)nb;
	size = 1;
	if (troll < 0)
	{
		ft_putchar('-');
		troll = -troll;
	}
	number = troll;
	while ((number /= 10) > 0)
	{
		size *= 10;
	}
	number = troll;
	while (size != 0)
	{
		ft_putchar((char)((number / size)) + '0');
		number %= size;
		size /= 10;
	}
}
