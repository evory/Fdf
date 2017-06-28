/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:13:47 by bbrandt           #+#    #+#             */
/*   Updated: 2017/06/23 16:51:58 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_ms	*ft_init_ms(void)
{
	t_ms	*ms;

	ms = malloc(sizeof(t_ms));
	ms->ptr_mlx = NULL;
	ms->ptr_win = NULL;
	ms->ptr_img = NULL;
	ms->fd = 0;
	ms->map_width = 0;
	ms->map_height = 0;
	ms->array = NULL;
	ms->px_x = WIDTH / 2;
	ms->px_y = HEIGHT / 3;
	ms->zoom = 25;
	ms->move = 0;
	ms->move2 = 0;
	ms->j = 0;
	ms->h = 0;
	ms->k = 0;
	ms->l = 0;
	ms->r = 182;
	ms->g = 200;
	ms->b = 86;
	return (ms);
}

int		main(int argc, char **argv)
{
	t_ms	*ms;

	ms = ft_init_ms();
	if (argc != 2)
	{
		ft_putstr("invalid argument\n");
		return (0);
	}
	ms->fd = open(argv[1], O_RDONLY);
	ft_parser(ms);
	close(ms->fd);
	ms->fd = open(argv[1], O_RDONLY);
	ft_parser(ms);
	ft_build(ms);
	free(ms);
	return (0);
}
