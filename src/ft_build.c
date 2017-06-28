/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 00:49:09 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/28 17:28:59 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_pixel_put(t_ms *ms, int z)
{

	if (ms->px_x < 0 || ms->px_y < 0 || ms->px_x > WIDTH || ms->px_y > HEIGHT)
		return ;
		ms->img[ms->px_y * ms->s_l + (ms->px_x * ms->bpp / 8) + 0] = (z > 0) ? -ms->r : ms->r;
		ms->img[ms->px_y * ms->s_l + (ms->px_x * ms->bpp / 8) + 1] = (z > 0) ? -ms->g : ms->g;
		ms->img[ms->px_y * ms->s_l + (ms->px_x * ms->bpp / 8) + 2] = (z > 0) ? -ms->b : ms->b;
}

void	converting_coord(t_ms *ms, int z1, int z2)
{
	ms->px_x *= ms->zoom;
	ms->px_y *= ms->zoom;
	ms->px_xf *= ms->zoom;
	ms->px_yf *= ms->zoom;
	ms->px_x += z1;
	ms->px_y += z1;
	ms->px_xf += z2;
	ms->px_yf += z2;
}

int		ft_draw_points_bis(t_ms *ms)
{
	int x;
	int y;

	x = 0;
	while (x < ms->map_width)
	{
		y = 0;
		while (y < ms->map_height)
		{
			ms->px_z1 = ms->array[y][x];
			ms->px_z2 = ((y + 1) < ms->map_height) ? ms->array[y + 1][x] : ms->px_z1;
			ms->px_x = x;
			ms->px_y = y;
			ms->px_xf = x;
			ms->px_yf = ((y + 1) < ms->map_height) ? y + 1 : y;
			converting_coord(ms, ms->px_z1, ms->px_z2);
			displine(ms, ms->px_z2);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(ms->ptr_mlx, ms->ptr_win, ms->ptr_img, 0, 0);
	return (0);
}

int		ft_draw_points(t_ms *ms)
{
	int x;
	int y;

	y = 0;
	while (y < ms->map_height)
	{
		x = 0;
		while (x < ms->map_width)
		{
			ms->px_z1 = ms->array[y][x];
			ms->px_z2 = ((x + 1) < ms->map_width) ? ms->array[y][x + 1] : ms->px_z1;
			ms->px_x = x;
			ms->px_y = y;
			ms->px_xf = ((x + 1) < ms->map_width) ? x + 1 : x;
			ms->px_yf = y;
			converting_coord(ms, ms->px_z1, ms->px_z2);
			displine(ms, ms->px_z2);
			x++;
		}
		y++;
	}
		ft_draw_points_bis(ms);
		return (0);
}

int		ft_build(t_ms *ms)
{
	ms->ptr_mlx = mlx_init();
	ms->ptr_win = mlx_new_window(ms->ptr_mlx, WIDTH, HEIGHT, "Fdf");
	ms->ptr_img = mlx_new_image(ms->ptr_mlx, WIDTH, HEIGHT);
	ms->img = mlx_get_data_addr(ms->ptr_img, &ms->bpp, &ms->s_l, &ms->endian);
	mlx_key_hook(ms->ptr_win, &ft_key_hook, ms);
	// mlx_mouse_hook(ms->ptr_win, &ft_mouse_hook, ms);
	mlx_loop_hook(ms->ptr_mlx, &ft_draw_points, ms);
	mlx_loop(ms->ptr_mlx);
	return (0);
}
