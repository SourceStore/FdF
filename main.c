/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 23:15:07 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/22 19:14:48 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** minilibx/libmlx.a -o mlx -lmlx -framework OpenGl -framework AppKit
*/

void			loop_change_color(int k, t_data *m_node, char c)
{
	int			i;
	int			j;
	int			koef;

	i = -1;
	if (c == 'r')
		koef = 0;
	if (c == 'g')
		koef = 1;
	if (c == 'b')
		koef = 2;
	while (++i < m_node->sizey)
	{
		j = -1;
		while (++j < m_node->sizex)
		{
			if (m_node->data[i].rgb[j * 3 + koef] + k > 0
				&& m_node->data[i].rgb[j * 3 + koef] + k < 255)
				m_node->data[i].rgb[j * 3 + koef] += k;
		}
	}
}

int				main_2(t_data *m_node)
{
	axo_proj(m_node);
	center(&m_node);
	midp(&m_node, 1);
	draw_image(m_node);
	mlx_key_hook(m_node->win, close_window, &m_node);
	mlx_hook(m_node->win, 2, 5, f_move_figure, &m_node);
	mlx_hook(m_node->win, 17, 1L << 17, exit_x, &m_node);
	mlx_put_image_to_window(m_node->mlx, m_node->win, m_node->img, 0, 0);
	mlx_loop(m_node->mlx);
	return (0);
}

void			collect_data(t_data *m_node)
{
	(*m_node).sizex = (*m_node).data[0].sizex;
	(*m_node).axd->x0 = ((*m_node).sizex / 2) - 1;
	(*m_node).axd->y0 = ((*m_node).sizey / 2) - 1;
	(*m_node).w = 2200;
	(*m_node).h = 2200;
	(*m_node).k = ((*m_node).w) * 3 / ((*m_node).sizex * (*m_node).sizey);
	(*m_node).k = (*m_node).k < 1 ? 3 : (*m_node).k;
	(*m_node).k = (*m_node).k > 200 ? 75 : (*m_node).k;
	(*m_node).x_c = ((*m_node).w / (2 * (*m_node).k)) - 1;
	(*m_node).y_c = ((*m_node).w / (3 * (*m_node).k)) - 1;
	(*m_node).axd->xf = (*m_node).x_c;
	(*m_node).axd->yf = (*m_node).y_c;
	(*m_node).axd->zf = 1;
	(*m_node).mlx = mlx_init();
	(*m_node).win = mlx_new_window((*m_node).mlx, 2200, 2200, "FdF");
	(*m_node).img = mlx_new_image((*m_node).mlx, 2200, 2200);
	(*m_node).adr_img = mlx_get_data_addr((*m_node).img, &(*m_node).bpp,
			&(*m_node).sl, &(*m_node).endian);
	create_win_help(m_node);
}

int				main(int argc, char **argv)
{
	t_data		m_node;
	int			fd;

	if (argc != 2)
		return (write(1, "Uncorrect range of data\n", 24));
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd != -1)
	{
		m_node.sizey = check_arr(fd);
		if (m_node.sizey > 1)
		{
			close(fd);
			fd = open(argv[argc - 1], O_RDONLY);
			m_node.data = (t_cdata *)malloc(sizeof(t_cdata) * m_node.sizey);
			m_node.axd = (t_ad *)malloc(sizeof(t_ad));
			m_node.br = (t_br *)malloc(sizeof(t_br));
			m_node.data = create_mas(fd, m_node.sizey);
			collect_data(&m_node);
			main_2(&m_node);
		}
		return (write(1, "Invalid data\n", 13));
	}
	else
		write(1, "Invalid user\n", 13);
	return (0);
}
