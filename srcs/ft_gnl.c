/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:57:08 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 12:46:33 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		get_line(int ret, char **join, char **line)
{
	int		i;
	char	*tmp;

	if (ret < 0)
		return (-1);
	if (!*join)
	{
		*line = ft_strdup("");
		return (0);
	}
	i = 0;
	while ((*join)[i] != '\n' && (*join)[i] != '\0')
		i++;
	*line = ft_substr(*join, 0, i);
	if ((*join)[i] == '\n')
		tmp = ft_strdup(&(*join)[i + 1]);
	else
		tmp = NULL;
	free(*join);
	*join = tmp;
	if (!*join)
		return (0);
	return (1);
}

static int		ft_check_read(int fd, char **buf)
{
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (0);
	if (read(fd, *buf, 0) < 0)
	{
		free(*buf);
		return (0);
	}
	return (1);
}

int				ft_gnl(int fd, char **line)
{
	char		*buf;
	static char	*join;
	char		*tmp;
	int			ret;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || !ft_check_read(fd, &buf))
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (!join)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(join, buf);
		free(join);
		join = tmp;
		if (ft_strchr(join, '\n'))
			break ;
	}
	free(buf);
	return (get_line(ret, &join, line));
}
