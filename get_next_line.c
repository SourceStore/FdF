/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:01:12 by rishchen          #+#    #+#             */
/*   Updated: 2017/02/08 16:24:05 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int					ft_cc(char *str, int c)
{
	int				i;

	i = -1;
	if (*str)
	{
		while (str[++i])
		{
			if (str[i] == c)
				return (i);
		}
	}
	return (-1);
}

int					ft_read(int fd, t_llist *node, int readf)
{
	int				ret;
	char			*buff;
	char			*tmp;

	buff = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		readf = 1;
		tmp = node->buffer != NULL ? node->buffer : ft_strdup("");
		node->buffer = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
		if (ft_cc(buff, '\n') >= 0)
		{
			ft_strdel(&buff);
			return (readf);
		}
		ft_strdel(&buff);
		buff = ft_strnew(BUFF_SIZE);
	}
	ft_strdel(&buff);
	if (ret == 0 && (readf == 1 || ft_strlen(node->buffer) > 0))
		return (1);
	else if (ret == 0 && readf == 0)
		return (readf);
	return (-1);
}

t_llist				*create_node(int fd, t_llist *head)
{
	t_llist			*node;
	t_llist			*endnode;

	node = (t_llist *)malloc(sizeof(t_llist));
	node->next = NULL;
	node->filedis = fd;
	node->buffer = ft_strnew(BUFF_SIZE);
	node->ans = ft_strnew(0);
	if (head == NULL)
		return (head = node);
	endnode = head;
	while (endnode)
	{
		if (endnode->filedis == fd)
		{
			endnode->ans = ft_strnew(0);
			return (endnode);
		}
		else if (endnode->next == NULL)
			endnode->next = node;
		endnode = endnode->next;
	}
	return (endnode);
}

char				*ft_cut(t_llist *node)
{
	int				k;

	k = ft_cc(node->buffer, '\n');
	if (k >= 0)
	{
		ft_strdel(&node->ans);
		node->ans = ft_strsub(node->buffer, 0, k);
		node->buff = ft_strsub(node->buffer, k + 1, (ft_strlen(node->buffer)));
		ft_strdel(&node->buffer);
		node->buffer = ft_strsub(node->buff, 0, ft_strlen(node->buff));
		ft_strdel(&node->buff);
	}
	else
	{
		if (ft_strlen(node->buffer) > 0)
		{
			node->ans = ft_strsub(node->buffer, 0, (ft_strlen(node->buffer)));
			ft_strdel(&node->buffer);
		}
		else if (ft_strlen(node->buffer) == 0)
		{
			ft_strdel(&node->ans);
		}
	}
	return (node->ans);
}

int					get_next_line(const int fd, char **line)
{
	int				readf;
	static t_llist	*head;
	t_llist			*node;

	if (fd < 0 || BUFF_SIZE < 0 || !line || fd > 4096)
		return (-1);
	readf = 0;
	node = create_node(fd, head);
	if (head == NULL)
		head = node;
	readf = ft_read(fd, node, readf);
	if (readf != -1 && node->buffer != NULL)
		*line = ft_cut(node);
	return (readf);
}
