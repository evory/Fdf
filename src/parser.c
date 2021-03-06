/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:30:12 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/10 15:11:53 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
		if ((ft_isdigit(line[i]) == 0 && line[i] != ' ' && line[i] != '-') ||
		(line[i] == '-' && ft_isdigit(line[i + 1]) == 0))
		{
			ft_putstr("Wrong map !\n");
			exit(0);
		}
		i++;
	}
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
