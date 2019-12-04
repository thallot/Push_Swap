/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:42:19 by thallot           #+#    #+#             */
/*   Updated: 2019/07/17 13:54:54 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_read_line(int fd, char *str)
{
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	int			cursor;

	while ((cursor = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (cursor == -1)
		{
			free(str);
			return (NULL);
		}
		buffer[cursor] = '\0';
		tmp = str;
		str = ft_strjoin(str, buffer);
		ft_memdel((void **)&tmp);
		if ((cursor == 0 && ft_strlen(buffer) == 0) || ft_strchr(buffer, '\n'))
			break ;
	}
	return (str);
}

static void		ft_cut_line(char **str, char **line)
{
	char		*ptr;
	size_t		size;

	size = 0;
	while ((*str)[size] != '\n' && (*str)[size] != '\0')
		size++;
	if ((*str)[size] == '\n')
	{
		*line = ft_strsub(*str, 0, size);
		ptr = ft_strdup(&((*str)[size + 1]));
		free(*str);
		*str = ptr;
	}
	else
	{
		*line = ft_strdup(*str);
		ft_memdel((void**)str);
	}
}

static int		ft_create_save(t_file **file, int index)
{
	if (!file[index])
	{
		if (!(file[index] = (t_file *)malloc(sizeof(t_file))))
			return (-1);
		file[index]->str = ft_strnew(0);
		file[index]->fd = index;
	}
	return (1);
}

static int		debug(int fd, t_file **file, char **line)
{
	if (fd < 0 || line == NULL || fd > OPEN_MAX || read(fd, 0, 0) == -1)
	{
		if (file[0])
		{
			free(file[0]->str);
			free(file[0]);
		}
		return (-1);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file[OPEN_MAX];
	size_t			size;

	size = 0;
	if (debug(fd, file, line) == -1)
		return (-1);
	if (ft_create_save(file, fd) == -1)
		return (-1);
	if (!file[fd]->str)
		file[fd]->str = ft_strnew(0);
	if ((file[fd]->str = ft_read_line(fd, file[fd]->str)) == NULL)
		return (-1);
	ft_cut_line(&(file[fd]->str), line);
	if (!file[fd]->str && *line[0] == '\0')
	{
		free(*line);
		free(file[fd]);
		*line = NULL;
		return (0);
	}
	return (1);
}
