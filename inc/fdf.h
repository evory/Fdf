/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:27:20 by bbrandt           #+#    #+#             */
/*   Updated: 2017/07/22 18:08:50 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"
# include <mlx.h>
# define WIDTH 2500
# define HEIGHT 1300
# define KEYPRESS 2
# define KEYPRESSMASK 1
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ZOOM 69
# define DEZOOM 78
# define RED 15
# define BLUE 11
# define GREEN 5
# define CLMB 30
# define CLMBD 33
# define EXIT 53

typedef struct		s_ms
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				s_l;
	int				bpp;
	int				endian;
	int				fd;
	int				map_height;
	int				map_width;
	int				**array;
	int				px_x;
	int				px_y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z;
	int				z1;
	int				z2;
	int				zoom;
	char			r;
	char			g;
	char			b;

	int				a;
	int				a1;
}					t_ms;

void				ft_parser(t_ms *ms);
void				line_tab_x(t_ms *ms);
void				line_tab_y(t_ms *ms);
void				raster_h(t_ms *ms);
void				raster_v(t_ms *ms);
void				displine(t_ms *ms);
void				swap_coord(t_ms *ms);
void				converting_coord(t_ms *ms, int y, int x);
int					ft_init(t_ms *ms);
int					ft_init_mlx(t_ms *ms);

#endif
