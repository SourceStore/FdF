/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:51:29 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/21 21:53:00 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FDF_FDF_H
# define TEST_FDF_FDF_H

# include "get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define VAL (M_PI / 180)
# define ALP (-10 * VAL)
# define BET (90 * VAL)
# define OX (270 * VAL)
# define OY (0 * VAL)

typedef struct	s_br_data
{
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		step;
	double		dx;
	double		dy;
	double		err;
	double		ystep;
	double		y;
	double		x;
	int			r1;
	int			g1;
	int			b1;
}				t_br;

typedef struct	s_auxiliary_data
{
	int			x0;
	int			y0;
	double		xf;
	double		yf;
	double		zf;
}				t_ad;

typedef struct	s_second
{
	int			sizex;
	double		*x_s;
	double		*y_s;
	double		*z_s;
	double		*x;
	double		*y;
	double		*z;
	double		*rgb;
}				t_cdata;

typedef struct	s_first
{
	void		*mlx;
	void		*mlx_h;
	void		*win;
	void		*win_h;
	char		*adr_img_h;
	void		*img_h;
	char		*adr_img;
	void		*img;
	int			bpp;
	int			sl;
	int			endian;
	int			sizex;
	int			sizey;
	int			w;
	int			h;
	int			k;
	int			x_c;
	int			y_c;
	t_cdata		*data;
	t_ad		*axd;
	t_br		*br;
}				t_data;

int				check_arr(int fd);
int				count_range_mas(char **line2, int cline);
int				ft_in(char *found, char *str, int j);
void			draw_image(t_data *m_node);
void			ft_put_pixel(char *line, double x, double y, t_data *m_node);
void			br(char *line, t_data *m_node);
void			data_for_draw(t_data *m_node, int i, int j);
void			center(t_data **m_node);
void			midp(t_data **m_node, int c);
void			axo_proj(t_data *m_node);
void			iso_proj(t_data *m_node);
void			ort_proj(t_data *m_node);
void			change_color(int keykode, t_data *m_node);
int				close_window(int keykode);
int				exit_x(void *param);
void			move_figure(t_data *m_node, int keykode);
void			rotate_figure(t_data *m_node, int keykode);
void			rotate_z_f(t_data *m_node, double k);
void			rotate_y_f(t_data *m_node, double k);
void			rotate_x_f(t_data *m_node, double k);
void			rotate_xyz_f(t_data *m_node, int keykode);
void			rise_figure(t_data *m_node, int keykode);
void			change_proj(t_data *m_node, int keykode);
void			loop_change_color(int k, t_data *m_node, char c);
void			change_color(int keykode, t_data *m_node);
int				f_move_figure(int keykode, t_data **m_node);
double			ft_atoi_base(char *s, int flag, int i);
void			ft_parse_color(t_cdata *n, int c, char *line, int j);
t_cdata			allocate_coor(int i, char **line2);
int				range_x(char **line);
t_cdata			*create_mas(int fd, int size);
void			ft_put_pixel(char *line, double x, double y, t_data *m_node);
void			midp(t_data **m_node, int c);
void			center(t_data **m_node);
void			ft_swap(double *par1, double *par2);
void			axo_proj(t_data *m_node);
void			ort_proj(t_data *m_node);
void			iso_proj(t_data *m_node);
int				main_2(t_data *m_node);
void			create_win_help(t_data *m_node);
void			yoba_kostil(t_data *m_node, int i, int j);
void			yoba_kostil_hide(t_data *m_node, int i, int j);
void			kostil_move(t_data *m_node, int i, int j, int k);

#endif
