/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:13:04 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/21 21:54:55 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		data_for_draw(t_data *m_node, int i, int j)
{
	m_node->br->step = fabs(m_node->br->y2 - m_node->br->y1) >
		fabs(m_node->br->x2 - m_node->br->x1) ? 1 : 0;
	if (m_node->br->step)
	{
		ft_swap(&m_node->br->x1, &m_node->br->y1);
		ft_swap(&m_node->br->x2, &m_node->br->y2);
	}
	if (m_node->br->x1 > m_node->br->x2)
	{
		ft_swap(&m_node->br->x1, &m_node->br->x2);
		ft_swap(&m_node->br->y1, &m_node->br->y2);
	}
	m_node->br->dx = (m_node->br->x2 * m_node->k - m_node->br->x1 * m_node->k);
	m_node->br->dy = fabs(m_node->br->y2 *
			m_node->k - m_node->br->y1 * m_node->k);
	m_node->br->err = (m_node->br->dx / 2);
	m_node->br->ystep = (m_node->br->y1 < m_node->br->y2) ? 1 : -1;
	m_node->br->y = m_node->br->y1 * m_node->k;
	m_node->br->x = m_node->br->x1 * m_node->k;
	m_node->br->r1 = (int)m_node->data[i].rgb[j * 3];
	m_node->br->g1 = (int)m_node->data[i].rgb[j * 3 + 1];
	m_node->br->b1 = (int)m_node->data[i].rgb[j * 3 + 2];
}

void		br(char *line, t_data *m_node)
{
	while (m_node->br->x <= m_node->br->x2 * m_node->k)
	{
		ft_put_pixel(line, m_node->br->step ?
				m_node->br->y : m_node->br->x,
				m_node->br->step ? m_node->br->x : m_node->br->y, m_node);
		m_node->br->err -= m_node->br->dy;
		if (m_node->br->err < 0)
		{
			m_node->br->y += m_node->br->ystep;
			m_node->br->err += m_node->br->dx;
		}
		m_node->br->x++;
	}
}

void		ft_put_pixel(char *line, double x, double y, t_data *m_node)
{
	int		sl;

	sl = m_node->sl;
	if ((int)x * 4 + 3 + (int)y * sl >= 0 &&
			(int)(x * 4) + 3 < sl && y < 2200 && x >= 0 && y >= 0)
	{
		line[(int)fabs(x) * 4 + (int)fabs(y) * sl] = m_node->br->b1;
		line[(int)fabs(x) * 4 + 1 + (int)fabs(y) * sl] = m_node->br->g1;
		line[(int)fabs(x) * 4 + 2 + (int)fabs(y) * sl] = m_node->br->r1;
	}
}

void		yoba_kostil(t_data *m_node, int i, int j)
{
	m_node->br->x1 = m_node->data[i].x[j];
	m_node->br->y1 = m_node->data[i].y[j];
	m_node->br->x2 = m_node->data[i].x[j + 1];
	m_node->br->y2 = m_node->data[i].y[j + 1];
}

void		draw_image(t_data *m_node)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m_node->sizey)
	{
		j = -1;
		while (++j < m_node->sizex)
		{
			if (j + 1 < m_node->sizex)
			{
				yoba_kostil(m_node, i, j);
				data_for_draw(m_node, i, j);
				br(m_node->adr_img, m_node);
			}
			if (i + 1 < m_node->sizey ||
					(j == m_node->sizex - 1 && i != m_node->sizey - 1))
			{
				yoba_kostil_hide(m_node, i, j);
				data_for_draw(m_node, i, j);
				br(m_node->adr_img, m_node);
			}
		}
	}
}
