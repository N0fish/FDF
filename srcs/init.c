/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:42:57 by algultse          #+#    #+#             */
/*   Updated: 2024/02/22 13:34:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(char *file_fdf, t_maps *map)
{
	int	fd;

	if (!file_fdf || !map)
		ft_error(ERROR_MAP);
	fd = open(file_fdf, O_RDONLY);
	if (fd < 0)
		ft_error(LIRE_FICHIER_IMPOSSIBLE);
	fill_numbers(fd, map);
	fill_zmap(map);
}

int	init_mlx(t_data *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == 0)
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, mlx->x_width, mlx->y_height, "FDF");
	if (mlx->win == 0)
		return (1);
	mlx->img = mlx_new_image(mlx->mlx, mlx->x_width, mlx->y_height);
	if (mlx->img == 0)
		return (1);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	return (0);
}

void	reset_camera_center(t_data *mlx)
{
	t_point2d	p_left;
	t_point2d	p_right;
	t_point2d	p_bot;

	ft_memset(&p_left, 0, sizeof(t_point2d));
	ft_memset(&p_right, 0, sizeof(t_point2d));
	ft_memset(&p_bot, 0, sizeof(t_point2d));
	iso_proj((t_point3d){0, mlx->map->height, 0}, \
		&p_left, mlx);
	iso_proj((t_point3d){mlx->map->width, 0, 0}, \
		&p_right, mlx);
	iso_proj((t_point3d){mlx->map->width, mlx->map->height, 0}, \
		&p_bot, mlx);
	mlx->x_offset = (mlx->x_width / 2) - p_left.x - (p_right.x - p_left.x) / 2;
	mlx->y_offset = (mlx->y_height / 2) - (p_bot.y / 2);
}

void	init_camera(t_data *mlx)
{
	mlx->c_scale = CELL_SIZE;
	mlx->z_scale = Z_DOWN_SCALE;
	mlx->x_width = WIN_W;
	mlx->y_height = WIN_H;
	mlx->angle = (t_angle3d){0, 0, 0};
	reset_camera_center(mlx);
}
