/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:52:02 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/29 04:07:31 by bryanbrandt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_pixel_put(t_ms ms, int x, int y)
{
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if ((ms.z1 > 0 && ms.z1 <= 10) || (ms.z2 > 0 && ms.z2 <= 10))
		{
			ms.data[(y * ms.s_l) + (x * (ms.bpp / 8))] = -ms.b;
			ms.data[(y * ms.s_l) + (x * (ms.bpp / 8)) + 1] = -ms.g;
			ms.data[(y * ms.s_l) + (x * (ms.bpp / 8)) + 2] = -ms.r;
		}
		else
		{
			ms.data[(y * ms.s_l) + (x * (ms.bpp / 8))] = ms.b;
			ms.data[(y * ms.s_l) + (x * (ms.bpp / 8)) + 1] = ms.g;
			ms.data[(y * ms.s_l) + (x * (ms.bpp / 8)) + 2] = ms.r;
		}
	}
}

void	swap_coord(t_ms *ms)
{
	int tmp;

	tmp = ms->px_x;
	ms->px_x = ms->px_xf;
	ms->px_xf = tmp;
	tmp = ms->px_y;
	ms->px_y = ms->px_yf;
	ms->px_yf = tmp;

}

void	converting_coord(t_ms *ms)
{
	ms->x1 *= ms->zoom;
	ms->y1 *= ms->zoom;
	ms->x2 *= ms->zoom;
	ms->y2 *= ms->zoom;
	ms->x1 += ms->z1;
	ms->y1 += ms->z1;
	ms->x2 += ms->z2;
	ms->y2 += ms->z2;
	ms->x2 += ms->z;
	ms->y2 += ms->z;
}

void	raster_v(t_ms *ms)
{
	int dx;
	int dy;
	int x;
	int y;

	x = ms->x1;
	dx = ms->x2 - ms->x1;
	dy = ms->y2 - ms->y1;
	while (x <= ms->x2 && dx > 0)
	{
		y = ms->y1 + dy * (x - ms->x1) / dx;
		ft_pixel_put(ms, y + ms->px_x, x + ms->px_y);
		x++;
	}
}

void		raster_h(t_ms *ms)
{
	int dx;
	int dy;
	int x;
	int y;

	y = ms->y1;
	dx = ms->x2 - ms->x1;
	dy = ms->y2 - ms->y1;
	while (y <= ms->y2 && dy > 0)
	{
		x = ms->x1 + dx * (y - ms->y1) / dy;
		ft_pixel_put(ms, y + ms->px_x, x + ms->px_y);
		y++;
	}
}
