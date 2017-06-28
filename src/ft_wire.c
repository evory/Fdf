/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:52:02 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/28 17:36:08 by bbrandt          ###   ########.fr       */
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


void	displine(t_ms *ms, int z)
{
	if (ft_abs(ms->px_yf - ms->px_y) >= ft_abs(ms->px_xf - ms->px_x))
	{
		if (ms->px_y < ms->px_yf)
			ft_raster_bis(ms, z);
		else
		{
			swap_coord(ms);
			ft_raster_bis(ms, z);
		}
	}
	else
	{
		if (ms->px_x < ms->px_xf)
			ft_raster(ms, z);
		else
		{
			swap_coord(ms);
			ft_raster(ms, z);
		}
	}
}
void		ft_raster_bis(t_ms *ms, int z)
{
	int dx;
	int dy;
	int x;
	int y;

	x = ms->px_y;
	dx = ms->px_yf - ms->px_y;
	dy = ms->px_xf - ms->px_x;
	while (x <= ms->px_yf && dx > 0)
	{
		y = ms->px_x + dy * (x - ms->px_y) / dx;
		ft_pixel_put(ms, z);
		x++;
	}
}

void		ft_raster(t_ms *ms, int z)
{
	int dx;
	int dy;
	int x;
	int y;

	y = ms->px_x;
	dx = ms->px_yf - ms->px_y;
	dy = ms->px_xf - ms->px_x;
	while (y <= ms->px_xf && dy > 0)
	{
		x = ms->px_y + dx * (y - ms->px_x) / dy;
		ft_pixel_put(ms, z);
		y++;
	}
}
