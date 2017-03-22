/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:21:29 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/20 22:29:07 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		center(t_data **m_node)
{
	double	x0;
	double	y0;
	double	z0;
	int		i;
	int		j;

	i = -1;
	x0 = (*m_node)->data[(*m_node)->axd->y0].x[(*m_node)->axd->x0];
	y0 = (*m_node)->data[(*m_node)->axd->y0].y[(*m_node)->axd->x0];
	z0 = (*m_node)->data[(*m_node)->axd->y0].z[(*m_node)->axd->x0];
	while (++i < (*m_node)->sizey)
	{
		j = -1;
		while (++j < (*m_node)->sizex)
		{
			(*m_node)->data[i].x[j] = (*m_node)->data[i].x[j] - x0;
			(*m_node)->data[i].y[j] = (*m_node)->data[i].y[j] - y0;
			(*m_node)->data[i].z[j] = (*m_node)->data[i].z[j] - z0;
		}
	}
}

void		midp(t_data **m_node, int c)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (*m_node)->sizey)
	{
		j = -1;
		while (++j < (*m_node)->sizex)
		{
			(*m_node)->data[i].x[j] += (*m_node)->axd->xf * c;
			(*m_node)->data[i].y[j] += (*m_node)->axd->yf * c;
			(*m_node)->data[i].z[j] += (*m_node)->axd->zf * c;
		}
	}
}

void		change_proj(t_data *m_node, int keykode)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m_node->sizey)
	{
		j = -1;
		while (++j < m_node->sizex)
		{
			m_node->data[i].x[j] = m_node->data[i].x_s[j];
			m_node->data[i].y[j] = m_node->data[i].y_s[j];
			m_node->data[i].z[j] = m_node->data[i].z_s[j];
		}
	}
	m_node->axd->xf = m_node->x_c;
	m_node->axd->yf = m_node->y_c;
	if (keykode == 0)
		axo_proj(m_node);
	if (keykode == 34)
		iso_proj(m_node);
	else
		ort_proj(m_node);
	center(&m_node);
	midp(&m_node, 1);
}

void		change_color(int keykode, t_data *m_node)
{
	int		k;

	if (keykode == 15 || keykode == 18)
	{
		k = (keykode == 15 ? -1 : 1);
		loop_change_color(k, m_node, 'r');
	}
	else if (keykode == 5 || keykode == 19)
	{
		k = (keykode == 5 ? -1 : 1);
		loop_change_color(k, m_node, 'g');
	}
	else if (keykode == 11 || keykode == 20)
	{
		k = (keykode == 11 ? -1 : 1);
		loop_change_color(k, m_node, 'b');
	}
}

int			f_move_figure(int keykode, t_data **m_node)
{
	if (keykode == 125 || keykode == 126 || keykode == 123 || keykode == 124)
		move_figure((*m_node), keykode);
	else if (keykode == 69 || keykode == 78 || keykode == 24 || keykode == 27)
		rise_figure((*m_node), keykode);
	else if (keykode == 12 || keykode == 14)
		rotate_figure((*m_node), keykode);
	else if (keykode >= 83 && keykode <= 88)
		rotate_xyz_f(*m_node, keykode);
	else if (keykode == 0 || keykode == 34 || keykode == 31)
		change_proj((*m_node), keykode);
	else if (keykode == 15 || keykode == 5 || keykode == 11
		|| (keykode >= 18 && keykode <= 20))
		change_color(keykode, *m_node);
	mlx_destroy_image((*m_node)->mlx, (*m_node)->img);
	mlx_clear_window((*m_node)->mlx, (*m_node)->win);
	(*m_node)->img = mlx_new_image((*m_node)->mlx, 2200, 2200);
	draw_image((*m_node));
	mlx_put_image_to_window((*m_node)->mlx,
							(*m_node)->win, (*m_node)->img, 0, 0);
	return (0);
}
