/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:12:59 by algultse          #+#    #+#             */
/*   Updated: 2024/02/20 01:43:37 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *line)
{
	int		i;
	char	**lines;

	i = 0;
	if (!line)
		ft_error(EMPTY_FILE);
	lines = ft_split(line, ' ');
	free(line);
	if (!lines)
		ft_error(SPLIT_ERROR);
	while (lines[i] != NULL && ft_strncmp(lines[i], "\n", 1))
	{
		free(lines[i]);
		i++;
	}
	free(lines[i]);
	free(lines);
	return (i);
}

int	ft_line(int fd, char **line)
{
	*line = get_next_line(fd);
	if (!*line)
		return (0);
	return (1);
}

void	check_file(int fd, t_maps *map)
{
	int		y;
	char	*line;

	if (!ft_line(fd, &line))
		ft_error(LIRE_FICHIER_IMPOSSIBLE);
	y = 1;
	map->width = get_width(line);
	while (ft_line(fd, &line))
	{
		free(line);
		y++;
	}
	map->height = y;
}

void	read_file(char *file_fdf, t_maps *map)
{
	int		fd;

	fd = open(file_fdf, O_RDONLY);
	if (fd < 0)
		ft_error(LIRE_FICHIER_IMPOSSIBLE);
	check_file(fd, map);
	if (close(fd) == -1)
		ft_error(ERROR_CLOSING);
}
