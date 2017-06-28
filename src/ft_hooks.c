/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:48:06 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/21 15:20:06 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_reset(t_ms *ms)
{
	ms->i = 0;
	ms->j = 0;
	ms->px_x = WIDTH / 3 + ms->move;
	ms->px_y = HEIGHT / 3 + ms->move2;
}

int		ft_reboot_img(t_ms *ms)
{
	mlx_destroy_image(ms->ptr_mlx, ms->ptr_img);
	ms->ptr_img = mlx_new_image(ms->ptr_mlx, WIDTH, HEIGHT);
	ms->img = mlx_get_data_addr(ms->ptr_img, &ms->bpp, &ms->s_l, &ms->endian);
	mlx_put_image_to_window(ms->ptr_mlx, ms->ptr_win, ms->ptr_img, 0, 0);
	return (0);
}

void	ft_key_hook3(int keycode, t_ms *ms)
{
	if (keycode == CLMB)
	{
		ms->h += 1;
		ft_reset(ms);
	}
	if (keycode == CLMBD)
	{
		ms->h -= 1;
		ft_reset(ms);
	}
}

void	ft_key_hook2(int keycode, t_ms *ms)
{
	if (keycode == LEFT)
	{
		ms->move -= 30;
		ft_reset(ms);
	}
	if (keycode == ZOOM)
	{
		ms->zoom += 2;
		ft_reset(ms);
	}
	if (keycode == DEZOOM)
	{
		ms->zoom -= 2;
		ft_reset(ms);
	}
	if (keycode == CLMB || keycode == CLMBD)
		ft_key_hook3(keycode, ms);
}

int		ft_key_hook(int keycode, t_ms *ms)
{
	ft_reboot_img(ms);
	if (keycode == ESC)
	{
		free(ms);
		exit(1);
	}
	if (keycode == UP)
	{
		ms->move2 -= 30;
		ft_reset(ms);
	}
	if (keycode == DOWN)
	{
		ms->move2 += 30;
		ft_reset(ms);
	}
	if (keycode == RIGHT)
	{
		ms->move += 30;
		ft_reset(ms);
	}
	else
		ft_key_hook2(keycode, ms);
	return (0);
}
