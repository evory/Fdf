/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:30:12 by bbrandt           #+#    #+#             */
/*   Updated: 2017/07/27 17:42:01 by bbrandt          ###   ########.fr       */
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

int		**ft_fill_array(int x, int y, char **splitstr, int **tab)
{
	while (splitstr[x])
	{
		tab[y][x] = ft_atoi(splitstr[x]);
		x++;
	}
	return (tab);
}

int		**ft_malloc_array(int x, int y, t_ms *ms)
{
	int **tab;

	tab = NULL;
	ms->map_height = y;
	ms->map_width = x;
	tab = malloc(sizeof(int*) * y--);
	while (y >= 0)
	{
		tab[y] = malloc(sizeof(int) * x);
		y--;
	}
	return (tab);
}

void	check_map(char *line)
{
	int i;

	i = 0;
	if (ft_strlen(line) < 1)
	{
		ft_putstr("Wrong map ! Remove empty line\n");
		exit(0);
	}
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0 && line[i] != ' ')
		{
			ft_putstr("Wrong map !\n");
			exit(0);
		}
		i++;
	}
}

void	ft_parser(t_ms *ms)
{
	char	*line;
	char	**splitstr;
	int		x;
	int		y;

	y = 0;
	while (get_next_line(ms->fd, &line) != 0)
	{
		check_map(line);
		x = 0;
		splitstr = ft_strsplit(line, ' ');
		if (ms->array == NULL)
		{
			while (splitstr[x])
				x++;
		}
		else
			ms->array = ft_fill_array(x, y, splitstr, ms->array);
		y++;
	}
	if (ms->array == NULL)
		ms->array = ft_malloc_array(x, y, ms);
}
