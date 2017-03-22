/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:18:00 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/20 23:02:48 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_z_f(t_data *m_node, double k)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = -1;
	center(&m_node);
	while (++i < m_node->sizey)
	{
		j = -1;
		while (++j < m_node->sizex)
		{
			x = m_node->data[i].x[j];
			y = m_node->data[i].y[j];
			m_node->data[i].x[j] = x * cos(k * 2 * VAL) + y * sin(k * 2 * VAL);
			m_node->data[i].y[j] = -x * sin(k * 2 * VAL) + y * cos(k * 2 * VAL);
		}
	}
	midp(&m_node, 1);
}

void		rotate_y_f(t_data *m_node, double k)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = -1;
	center(&m_node);
	while (++i < m_node->sizey)
	{
		j = -1;
		while (++j < m_node->sizex)
		{
			x = m_node->data[i].x[j];
			z = m_node->data[i].z[j];
			m_node->data[i].x[j] = x * cos(k * 2 * VAL) + z * sin(k * 2 * VAL);
			m_node->data[i].z[j] = -x * sin(k * 2 * VAL) + z * cos(k * 2 * VAL);
		}
	}
	midp(&m_node, 1);
}

void		rotate_x_f(t_data *m_node, double k)
{
	int		i;
	int		j;
	double	y;
	double	z;

	i = -1;
	center(&m_node);
	while (++i < m_node->sizey)
	{
		j = -1;
		while (++j < m_node->sizex)
		{
			y = m_node->data[i].y[j];
			z = m_node->data[i].z[j];
			m_node->data[i].y[j] = y * cos(k * 2 * VAL) + z * sin(k * 2 * VAL);
			m_node->data[i].z[j] = y * (-sin(k * 2 * VAL))
				+ z * cos(k * 2 * VAL);
		}
	}
	midp(&m_node, 1);
}

void		rotate_xyz_f(t_data *m_node, int keykode)
{
	double	k;

	m_node->axd->xf = m_node->data[m_node->axd->y0].x[m_node->axd->x0];
	m_node->axd->yf = m_node->data[m_node->axd->y0].y[m_node->axd->x0];
	m_node->axd->zf = m_node->data[m_node->axd->y0].z[m_node->axd->x0];
	center(&m_node);
	if (keykode == 83 || keykode == 85)
	{
		k = (keykode == 83 ? 30 * VAL : -30 * VAL);
		rotate_x_f(m_node, k);
	}
	if (keykode == 86 || keykode == 88)
	{
		k = (keykode == 86 ? (30 * VAL) : (-30 * VAL));
		rotate_z_f(m_node, k);
	}
	if (keykode == 84 || keykode == 87)
	{
		k = (keykode == 84 ? 30 * VAL : -30 * VAL);
		rotate_y_f(m_node, k);
	}
}
