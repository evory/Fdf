/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:13:47 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/29 19:03:06 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		key_hook(int keycode, t_ms *ms)
{
	if (keycode == EXIT)
		exit(EXIT_SUCCESS);
	(keycode == LEFT) ? ms->x1 -= 25 : ms->x1;
	(keycode == DOWN) ? ms->y1 += 25 : ms->y1;
	(keycode == RIGHT) ? ms->x1 += 25 : ms->x1;
	(keycode == UP) ? ms->y1 -= 25 : ms->y1;
	(keycode == RED) ? ms->r += 5 : ms->r;
	(keycode == BLUE) ? ms->b += 5 : ms->b;
	(keycode == GREEN) ? ms->g += 5 : ms->g;
	(keycode == ZOOM) ? ms->zoom += 5 : ms->zoom;
	(keycode == DEZOOM) ? ms->zoom -= 5 : ms->zoom;
	(keycode == CLMB) ? ms->z += 1 : ms->z;
	(keycode == CLMBD) ? ms->z -= 1 : ms->z;
	mlx_destroy_image(ms->mlx, ms->img);
	ft_init_mlx(ms);
	printf("%d ", keycode);
	return (0);
}

void	ft_reset_px(t_ms *ms)
{
	ms->px_x = (WIDTH / 2) - (ms->map_width * ms->zoom / 2);
	ms->px_y = (HEIGHT / 2) - (ms->map_height * ms->zoom / 2);
}

int		ft_init_mlx(t_ms *ms)
{
	ft_reset_px(ms);
	ms->img = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	ms->data = mlx_get_data_addr(ms->img, &ms->bpp, &ms->s_l, &ms->endian);
	line_tab_x(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img, 0, 0);
	return (0);
}

void	ft_init_ms(t_ms *ms)
{
	ms->array = NULL;
	ms->zoom = 35;
	ms->b = 50;
	ms->g = 50;
	ms->r = 50;
	ms->z = 1;
}

int		main(int argc, char **argv)
{
	t_ms	ms;

	if (argc != 2)
	{
		ft_putstr("Invalid input !\n");
		return (0);
	}
	ft_init_ms(&ms);
	ms.fd = open(argv[1], O_RDONLY);
	ft_parser(&ms);
	close(ms.fd);
	ms.fd = open(argv[1], O_RDONLY);
	ft_parser(&ms);
	ms.mlx = mlx_init();
	ms.win = mlx_new_window(ms.mlx, WIDTH, HEIGHT, "fdf");
	ft_init_mlx(&ms);
	mlx_hook(ms.win, KEYPRESS, KEYPRESSMASK, key_hook, &ms);
	mlx_loop(ms.mlx);
	free(&ms);
	return (0);
}
