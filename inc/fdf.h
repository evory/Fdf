/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:27:20 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/29 04:07:36 by bryanbrandt      ###   ########.fr       */
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
# define WIDTH 1000
# define HEIGHT 800
# define KEYPRESS 2
# define KEYPRESSMASK 1

typedef struct		s_ms
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img2;
	char			*data;
	int				s_l;
	int				bpp;
	int				endian;
	char			*fd;
	int				map_height;
	int				map_width;
	int				**array;
	int				len_cmp;
	int				key;
	int				px_x;
	int				px_y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	int				zoom;
	char			r;
	char			g;
	char			b;
	char			z;
}					t_ms;

void				parser(t_ms *ms);
void				line_tab_x(t_ms ms);
void				line_tab_y(t_ms ms);
void				raster_h(t_ms ms);
void				raster_v(t_ms ms);
void				displine(t_ms *ms);
void				swap_coord(t_ms *ms);
void				converting_coord(t_ms *ms);
int					ft_init(t_ms *ms);

#endif
