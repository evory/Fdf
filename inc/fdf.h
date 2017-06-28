/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:27:20 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/23 16:58:08 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# define WIDTH 2550
# define HEIGHT 1350
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ZOOM 69
# define DEZOOM 78
# define CLMB 33
# define CLMBD 30

typedef	struct			s_ms
{
	void				*ptr_mlx;
	void				*ptr_win;
	void				*ptr_img;
	char				*img;
	int					s_l;
	int					bpp;
	int					fd;
	int					i;
	int					j;
	int					k;
	int					l;
	int					move;
	int					move2;
	int					**array;
	int					endian;
	int					zoom;
	int					map_width;
	int					map_height;
	int					px_x;
	int					px_y;
	int					px_xf;
	int					px_yf;
	int					px_z1;
	int					px_z2;
	int					h;
	int					r;
	int					g;
	int					b;
}						t_ms;

void					ft_parser(t_ms *ms);
int						ft_build(t_ms *ms);
int						ft_key_hook(int keycode, t_ms *ms);
int						ft_mouse_hook(int mousecode, t_ms *ms);
int						ft_wire(t_ms *ms);
void					ft_pixel_put(t_ms *ms, int z);
void					ft_raster(t_ms *ms, int z);
void					ft_raster_bis(t_ms *ms, int z);
int						ft_use_z(t_ms *ms);
int						ft_isometric(t_ms *ms);
void					displine(t_ms *ms, int z);
int						ft_draw_points_bis(t_ms *ms);
#endif
