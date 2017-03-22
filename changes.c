/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:13:33 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/20 23:00:59 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_figure(t_data *m_node, int keykode)
{
	int		k;
	int		j;
	int		i;

	i = -1;
	j = -1;
	if (keykode == 125 || keykode == 126)
	{
		k = keykode == 125 ? 7 : -7;
		kostil_move(m_node, i, j, k);
	}
	else if (keykode == 123 || keykode == 124)
	{
		k = keykode == 124 ? 7 : -7;
		{
			while (++i < m_node->sizey)
			{
				while (++j < m_node->sizex)
					m_node->data[i].x[j] += k;
				j = -1;
			}
		}
	}
}

void		rise_figure(t_data *m_node, int keykode)
{
	double	k;
	int		j;
	int		i;

	i = -1;
	j = -1;
	if (keykode == 69 || keykode == 24)
		k = 1.2;
	else
		k = 0.8;
	m_node->axd->xf = m_node->data[m_node->axd->y0].x[m_node->axd->x0];
	m_node->axd->yf = m_node->data[m_node->axd->y0].y[m_node->axd->x0];
	m_node->axd->zf = m_node->data[m_node->axd->y0].z[m_node->axd->x0];
	center(&m_node);
	while (++i < m_node->sizey)
	{
		while (++j < m_node->sizex)
		{
			m_node->data[i].x[j] = m_node->data[i].x[j] * k;
			m_node->data[i].y[j] = m_node->data[i].y[j] * k;
			m_node->data[i].z[j] = m_node->data[i].z[j] * k;
		}
		j = -1;
	}
	midp(&m_node, 1);
}

void		rotate_figure(t_data *m_node, int keykode)
{
	double	x_buf;
	double	y_buf;
	double	k;
	int		j;
	int		i;

	i = -1;
	k = keykode == 14 ? 30 : -30;
	m_node->axd->xf = (int)m_node->data[m_node->axd->y0].x[m_node->axd->x0];
	m_node->axd->yf = (int)m_node->data[m_node->axd->y0].y[m_node->axd->x0];
	center(&m_node);
	while (++i < m_node->sizey)
	{
		j = -1;
		while (++j < m_node->sizex)
		{
			x_buf = m_node->data[i].x[j];
			y_buf = m_node->data[i].y[j];
			m_node->data[i].x[j] = x_buf * cos(k / 2 * VAL)
				- y_buf * sin(k / 2 * VAL);
			m_node->data[i].y[j] = y_buf * cos(k / 2 * VAL)
				+ x_buf * sin(k / 2 * VAL);
		}
	}
	midp(&m_node, 1);
}

void		yoba_kostil_hide(t_data *m_node, int i, int j)
{
	m_node->br->x1 = m_node->data[i].x[j];
	m_node->br->y1 = m_node->data[i].y[j];
	m_node->br->x2 = m_node->data[i + 1].x[j];
	m_node->br->y2 = m_node->data[i + 1].y[j];
}
