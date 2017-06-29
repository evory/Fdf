/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 00:49:09 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/29 04:07:30 by bryanbrandt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_abs(int val)
{
	if (val > 0)
		return (val);
	else
		return (-val);
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

void	displine(t_ms *ms, int z)
{
	if (ft_abs(ms->x2 - ms->x1) >= ft_abs(ms->y2 - ms->y1))
	{
		if (ms->x1 < ms->x2)
			raster_v(ms);
		else
		{
			swap_coord(ms));
			raster_v(ms);
		}
	}
	else
	{
		if (ms->y1 < ms->y2)
			raster_h(ms);
		else
		{
			swap_coord(ms));
			raster_h(ms);
		}
	}
}


void		line_tab_x(t_ms *ms)
{
	int x;
	int y;
	int z;

	x = 0;
	while (x < ms->map_height)
	{
		y = 0;
		while (y < ms->map_width)
		{
			ms.z1 = ms->array[x][y];
			ms.z2 = ((y + 1) < ms->map_width) ? ms->array[x][y + 1] : ms->z1;
			ms.x1 = x;
			ms.y1 = y;
			ms.x2 = x;
			ms.y2 = ((y + 1) < ms->map_width) ? y + 1 : y;
			converting_coord(ms);
			displine(ms);
			y++;
		}
		x++;
	}
	line_tab_y(ms);
}

void	line_tab_y(t_ms *ms)
{
	int x;
	int y;
	int z;

	y = 0;
	while (y < ms->map_width)
	{
		x = 0;
		while (x < ms->map_height)
		{
			ms.z1 = ms->array[x][y];
			ms.z2 = ((x + 1) < ms->map_height) ? ms->array[x + 1][y] : ms->z1;
			ms.x1 = x;
			ms.y1 = y;
			ms.x2 = ((x + 1) < ms->map_height) ? x + 1 : x;
			ms.y2 = y;
			converting_coord(ms);
			displine(ms);
			x++;
		}
		y++;
	}
}