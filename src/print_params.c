/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:45:57 by bbrandt           #+#    #+#             */
/*   Updated: 2017/07/27 17:52:43 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_print_modif1(t_ms *ms)
{
	char *str;

	str = " ] [";
	mlx_string_put(ms->mlx, ms->win, 190, 230, 0x0FFFFFF, str);
	str = "Hauteur =";
	mlx_string_put(ms->mlx, ms->win, 40, 260, 0x0FFFFFF, str);
	str = ft_itoa(ms->high);
	mlx_string_put(ms->mlx, ms->win, 200, 260, 0x0FFFFFF, str);
	str = "zoom =";
	mlx_string_put(ms->mlx, ms->win, 40, 290, 0x0FFFFFF, str);
	str = ft_itoa(ms->zoom);
	mlx_string_put(ms->mlx, ms->win, 200, 290, 0x0FFFFFF, str);
}

void		ft_print_modif(t_ms *ms)
{
	char	*str;

	str = "Modif colors : R G B";
	mlx_string_put(ms->mlx, ms->win, 40, 110, 0x0FFFFFF, str);
	str = "red = ";
	mlx_string_put(ms->mlx, ms->win, 100, 140, 0x0FFFFFF, str);
	str = ft_itoa(ms->r);
	mlx_string_put(ms->mlx, ms->win, 200, 140, 0x0FFFFFF, str);
	str = "green = ";
	mlx_string_put(ms->mlx, ms->win, 100, 170, 0x0FFFFFF, str);
	str = ft_itoa(ms->g);
	mlx_string_put(ms->mlx, ms->win, 200, 170, 0x0FFFFFF, str);
	str = "blue = ";
	mlx_string_put(ms->mlx, ms->win, 100, 200, 0x0FFFFFF, str);
	str = ft_itoa(ms->b);
	mlx_string_put(ms->mlx, ms->win, 200, 200, 0x0FFFFFF, str);
	str = "Modif height =";
	mlx_string_put(ms->mlx, ms->win, 40, 230, 0x0FFFFFF, str);
	ft_print_modif1(ms);
}
