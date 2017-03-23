/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createbd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:34:47 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/21 21:51:47 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_parse_color(t_cdata *n, int c, char *line, int j)
{
	int		k;
	int		i;
	int		count;
	char	*buff;

	i = -1;
	buff = ft_strnew(6);
	if (c != -1)
	{
		k = c + 2;
		count = (int)ft_strlen(line + c + 3);
		while (++count <= 6)
			buff[++i] = (char)48;
		i = (int)ft_strlen(buff) - 1;
		while (++i < 6)
			buff[i] = line[++k];
	}
	else
		while (++i < 6)
			*(buff + i) = (char)70;
	n->rgb[j * 3] = (int)ft_atoi_base(buff, 1, 0);
	n->rgb[j * 3 + 1] = (int)ft_atoi_base(buff, 1, 1);
	n->rgb[j * 3 + 2] = (int)ft_atoi_base(buff, 1, 2);
}

t_cdata		init_coor(int range_mas_xyz)
{
	t_cdata	n;

	n.x_s = (double *)malloc(sizeof(double) * range_mas_xyz);
	n.y_s = (double *)malloc(sizeof(double) * range_mas_xyz);
	n.z_s = (double *)malloc(sizeof(double) * range_mas_xyz);
	n.x = (double *)malloc(sizeof(double) * range_mas_xyz);
	n.y = (double *)malloc(sizeof(double) * range_mas_xyz);
	n.z = (double *)malloc(sizeof(double) * range_mas_xyz);
	n.rgb = (double *)malloc(sizeof(double) * range_mas_xyz * 3);
	return (n);
}

t_cdata		allocate_coor(int i, char **line2)
{
	t_cdata	n;
	int		c;
	int		range_mas_xyz;
	int		j;

	j = -1;
	range_mas_xyz = count_range_mas(line2, -1);
	n = init_coor(range_mas_xyz);
	while (line2[++j])
	{
		c = ft_cc(line2[j], ',');
		n.x_s[j] = (double)j;
		n.x[j] = (double)j;
		n.y_s[j] = (double)i;
		n.y[j] = (double)i;
		n.z_s[j] = ft_atoi_base(line2[j], 0, i);
		n.z[j] = ft_atoi_base(line2[j], 0, i);
		ft_parse_color(&n, c, line2[j], j);
	}
	return (n);
}

t_cdata		*create_mas(int fd, int size)
{
	char	*line;
	char	**line2;
	t_cdata	*ans;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = NULL;
	ans = (t_cdata *)malloc(sizeof(t_cdata) * size);
	while (get_next_line(fd, &line) > 0)
	{
		line2 = ft_strsplit(line, ' ');
		if (j == 0)
			j = range_x(line2);
		if (*line2 != '\0' && **line2 != (char)32)
		{
			(*(ans + i)) = allocate_coor(i, line2);
			free(line);
			ft_strdel(line2);
			i++;
		}
	}
	ans->sizex = j;
	return (ans);
}

void		kostil_move(t_data *m_node, int i, int j, int k)
{
	while (++i < m_node->sizey)
	{
		while (++j < m_node->sizex)
			m_node->data[i].y[j] += k;
		j = -1;
	}
}
