/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:13:47 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/29 07:30:46 by bryanbrandt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		key_hook(int key, t_ms *ms)
{
	if (key == 53)
	exit(EXIT_SUCCESS);
	(key == 0) ? ms->px_x -= 25 : ms->px_x;
	(key == 1) ? ms->px_y += 25 : ms->px_y;
	(key == 2) ? ms->px_x += 25 : ms->px_x;
	(key == 5) ? ms->g += 5 : ms->g;
	(key == 11) ? ms->b += 5 : ms->b;
	(key == 13) ? ms->px_y -= 25 : ms->px_y;
	(key == 15) ? ms->r += 5 : ms->r;
	(key == 69) ? ms->zoom += 5 : ms->zoom;
	(key == 78) ? ms->zoom -= 5 : ms->zoom;
	(key == 116) ? ms->z += 1 : ms->z;
	(key == 121) ? ms->z -= 1 : ms->z;
	mlx_destroy_image(ms->mlx, ms->img);
	ft_init_mlx(ms);
	return (0);
}

int		ft_init_mlx(t_ms *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WIDTH, HEIGHT, "fdf");
	ms->img = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	ms->data = mlx_get_data_addr(ms->img, ms->bpp, ms->s_l, &ms->endian);
	mlx_hook(ms->win, KEYPRESS, KEYPRESSMASK, key_hook, ms);
	mlx_loop(ms->mlx);
	line_tab_x(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img, 0, 0);
	return (0);
}

void	ft_init_ms(t_ms *ms)
{
	ms->array = NULL;
	ms->zoom = 35;
	ms->px_x = (WIDTH / 2);
	ms->px_y = (HEIGHT / 2);
	ms->b = 50;
	ms->g = 50;
	ms->r = 50;
	ms->z = 0;
}

int		main(int argc, char **argv)
{
	t_ms	*ms;

	if (argc != 2)
	{
		ft_putstr("Invalid input !\n");
		return (0);
	}
	ft_init_ms(ms);
	ms->fd = open(argv[1], O_RDONLY);
	ft_parser(ms);
	close(ms->fd);
	ms->fd = open(argv[1], O_RDONLY);
	ft_parser(ms);
	ft_init_mlx(ms);
	free(ms);
	return (0);
}
