/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 21:56:46 by acolas            #+#    #+#             */
/*   Updated: 2017/08/09 21:54:47 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_type	*ft_lstnew_gnl(int fd)
{
	t_type	*stock;

	stock = (t_type *)malloc(sizeof(*stock));
	stock->content = ft_strnew(1);
	stock->rd = 1;
	stock->fd = fd;
	stock->next = NULL;
	return (stock);
}

static t_type	*ft_find_fd(t_type *stat, int fd)
{
	t_type	*stock;

	while (stat)
	{
		if (stat->fd == fd)
			break ;
		if (stat->next == NULL)
		{
			stock = ft_lstnew_gnl(fd);
			stat->next = stock;
			return (stock);
		}
		stat = stat->next;
	}
	return (stat);
}

static int		ft_print_gnl(t_type **stock, char **line)
{
	char	*tmp1;
	char	*tmp2;

	if ((tmp1 = ft_strchr((*stock)->content, '\n')) != NULL)
	{
		*tmp1 = '\0';
		*line = ft_strdup((*stock)->content);
		tmp2 = (*stock)->content;
		(*stock)->content = ft_strdup(tmp1 + 1);
		ft_strdel(&tmp2);
		return (OK);
	}
	return (END);
}

static int		ft_read_gnl(t_type **stock, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	while (((*stock)->rd = read((*stock)->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[(*stock)->rd] = '\0';
		tmp = ft_strjoin((*stock)->content, buff);
		ft_strdel(&(*stock)->content);
		(*stock)->content = tmp;
		if (ft_print_gnl(stock, line) == 1)
			return (OK);
	}
	return (END);
}

int				get_next_line(const int fd, char **line)
{
	static t_type	*stat;
	t_type			*stock;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (ERROR);
	if (!stat)
		stat = ft_lstnew_gnl(fd);
	stock = ft_find_fd(stat, fd);
	if ((ft_read_gnl(&stock, line) == 1))
		return (OK);
	if (stock->rd == ERROR)
		return (ERROR);
	if (ft_strlen(stock->content) == 0)
		return (END);
	if (ft_print_gnl(&stock, line) == 1)
		return (OK);
	else
	{
		*line = ft_strdup(stock->content);
		ft_strclr(stock->content);
	}
	return (OK);
}
