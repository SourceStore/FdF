/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuct_win_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:53:23 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/21 20:54:50 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_win_help(t_data *m_node)
{
	(*m_node).win_h = mlx_new_window((*m_node).mlx, 320, 140, "HELP");
	mlx_string_put((*m_node).mlx, (*m_node).win_h,
			10, 0, 0x810202, "Move: <- -> | (arrows)");
	mlx_string_put((*m_node).mlx, (*m_node).win_h,
			10, 16, 0x810202, "Resize figure: +/-");
	mlx_string_put((*m_node).mlx, (*m_node).win_h,
			10, 32, 0x810202, "Rotate around angle x: r1 r3");
	mlx_string_put((*m_node).mlx, (*m_node).win_h,
			10, 48, 0x810202, "Rotate around angle y: r2 r5");
	mlx_string_put((*m_node).mlx, (*m_node).win_h,
			10, 64, 0x810202, "Rotate around angle z: r4 r6");
	mlx_string_put((*m_node).mlx, (*m_node).win_h,
			10, 80, 0x810202, "Change color by channel r: R 1");
	mlx_string_put((*m_node).mlx, (*m_node).win_h,
			10, 96, 0x810202, "Change color by channel g: G 2");
	mlx_string_put((*m_node).mlx, (*m_node).win_h,
			10, 112, 0x810202, "Change color by channel b: B 3");
}
