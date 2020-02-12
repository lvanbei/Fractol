/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:50:41 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/10/16 16:48:02 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_intlen(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static	char	ft_voyant(char *result, int voyant)
{
	if (voyant == 1)
		result[0] = '-';
	return (result[0]);
}

static void		*ft_malloc(int len)
{
	char	*result;

	result = (char*)malloc(sizeof(char) * len + 1);
	return (result);
}

char			*ft_itoa(int n)
{
	char	*result;
	long	number;
	int		len;
	int		voyant;

	voyant = 0;
	number = n;
	len = ft_intlen(number);
	result = ft_malloc(len);
	if (!result)
		return (0);
	result[len] = '\0';
	if (number < 0)
	{
		number = -number;
		voyant = 1;
	}
	len--;
	while (len >= 0)
	{
		result[len--] = (number % 10) + '0';
		number /= 10;
	}
	ft_voyant(result, voyant);
	return (result);
}
