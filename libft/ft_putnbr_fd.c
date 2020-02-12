/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:17:39 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/15 18:58:09 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	nombre;
	int		size;
	long	troll;

	troll = nb;
	size = 1;
	if (troll < 0)
	{
		ft_putchar_fd('-', fd);
		troll = -troll;
	}
	nombre = troll;
	while ((nombre /= 10) > 0)
	{
		size *= 10;
	}
	nombre = troll;
	while (size != 0)
	{
		ft_putchar_fd((char)((nombre / size)) + '0', fd);
		nombre %= size;
		size /= 10;
	}
}
