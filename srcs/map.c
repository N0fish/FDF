/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:09:13 by algultse          #+#    #+#             */
/*   Updated: 2024/02/23 19:14:42 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_row(t_maps *map, int y, int x, char *line)
{
	char	**rows;

	rows = ft_split(line, ' ');
	free (line);
	if (!rows)
		ft_error(SPLIT_ERROR);
	map->map[y] = malloc(sizeof(int) * map->width);
	if (!map->map[y])
	{
		free(rows);
		free_map_error(map->map, y - 1);
	}
	while (x < map->width)
	{
		map->map[y][x] = ft_atoi(rows[x]);
		free(rows[x]);
		x++;
	}
	free(rows[x]);
	free(rows);
}

void	fill_numbers(int fd, t_maps *map)
{
	char	*line;
	int		y;
	int		x;

	y = 0;
	map->map = (int **)malloc(sizeof(int *) * map->height);
	if (!map->map)
		ft_error(MALLOC_NULL);
	while (ft_line(fd, &line) && y < map->height)
	{
		x = 0;
		fill_row(map, y, x, line);
		y++;
	}
	if (close(fd) == -1)
		ft_error(ERROR_CLOSING);
}

void	fill_zmap(t_maps *map)
{
	int	y;
	int	x;

	y = 0;
	map->zmax = map->map[0][0];
	map->zmin = map->map[0][0];
	while (y < map->height)
	{
		x = map->width;
		while (x--)
		{
			if (map->map[y][x] > map->zmax)
				map->zmax = map->map[y][x];
			if (map->map[y][x] < map->zmin)
				map->zmin = map->map[y][x];
		}
		y++;
	}
}

void	free_map(int **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}
