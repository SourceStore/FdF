/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:05:42 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/20 23:05:22 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		axo_proj(t_data *m_node)
{
	int		i;
	int		j;
	double	bufx;
	double	bufy;
	double	bufz;

	i = -1;
	while (++i <= m_node->sizey - 1)
	{
		j = -1;
		while (++j <= m_node->sizex - 1)
		{
			bufx = m_node->data[i].x[j];
			bufy = m_node->data[i].y[j];
			bufz = m_node->data[i].z[j];
			m_node->data[i].x[j] = bufx * cos(-30 * VAL)
				+ bufy * sin(-30 * VAL);
			m_node->data[i].y[j] = -bufx * sin(-30 * VAL) * cos(-15 * VAL) +
				bufy * cos(-30 * VAL) * cos(-15 * VAL) +
				bufz * sin(-15 * VAL);
		}
	}
}

void		ort_proj(t_data *m_node)
{
	int		i;
	int		j;
	double	bufx;
	double	bufy;

	i = -1;
	while (++i < m_node->sizey)
	{
		j = -1;
		while (++j < m_node->sizex)
		{
			bufx = m_node->data[i].x[j];
			bufy = m_node->data[i].y[j];
			m_node->data[i].x[j] = bufx + m_node->data[i].z[j] * cos(OX);
			m_node->data[i].y[j] = bufy + m_node->data[i].z[j] * sin(OY);
			m_node->data[i].z[j] += m_node->data[i].z[j];
		}
	}
}

void		iso_proj(t_data *m_node)
{
	int		i;
	int		j;
	double	bufx;
	double	bufy;

	i = -1;
	while (++i < m_node->sizey)
	{
		j = -1;
		while (++j < m_node->sizex)
		{
			bufx = m_node->data[i].x[j];
			bufy = m_node->data[i].y[j];
			m_node->data[i].x[j] = bufx + m_node->data[i].z[j] * cos(BET);
			m_node->data[i].y[j] = bufy + m_node->data[i].z[j] * sin(ALP);
			m_node->data[i].z[j] += m_node->data[i].z[j];
		}
	}
}
