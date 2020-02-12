/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:31:49 by lvan-bei          #+#    #+#             */
/*   Updated: 2018/12/04 15:48:00 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readline(char **str, int fd, char *buff)
{
	int			ret;
	char		*tmp;

	ret = 1;
	while (!(ft_strchr(str[fd], '\n')) && ret)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret)
		{
			tmp = str[fd];
			buff[ret] = '\0';
			str[fd] = ft_strjoin(tmp, buff);
			free(tmp);
			if (str[fd] == NULL)
				return (NULL);
		}
	}
	return (str[fd]);
}

int		ft_next_point(int i, char **str, int fd)
{
	char	*tmp;

	tmp = NULL;
	if (str[fd][i] == '\n')
	{
		tmp = ft_strdup(&str[fd][i + 1]);
		ft_strdel(&(str[fd]));
		str[fd] = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
	{
		tmp = ft_strdup(&str[fd][i]);
		ft_strdel(&(str[fd]));
		str[fd] = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if (str[fd] == NULL)
		return (0);
	return (1);
}

int		ft_free(char **str, int fd)
{
	ft_strdel(&(str[fd]));
	return (-1);
}

int		ft_next_line(char **str, char **line, int fd)
{
	int		i;

	i = 0;
	if (*str[fd])
	{
		while (str[fd][i] && str[fd][i] != '\n')
			i++;
		if (i == 0)
			*line = ft_strnew(0);
		else
			*line = ft_strsub(str[fd], 0, i);
		if (!(ft_next_point(i, str, fd)))
			return (-1);
		return (*line ? 1 : ft_free(str, fd));
	}
	else
	{
		*line = ft_strnew(0);
		if (!(*line))
			return (-1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char static		*str[OPEN_MAX];
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, buff, 0) == -1
		|| (str[fd] == NULL && !(str[fd] = ft_strnew(0))))
		return (-1);
	if (!(str[fd] = ft_readline(str, fd, buff)))
		return (-1);
	return (ft_next_line(str, line, fd));
}
