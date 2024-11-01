/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:08:59 by algultse          #+#    #+#             */
/*   Updated: 2024/02/25 14:18:36 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_rotation(int key, t_data *mlx)
{
	if (key == S)
		mlx->angle = (t_angle3d){\
			.x = ternary(mlx->angle.x <= 0, 359, mlx->angle.x - ANGLE_CHANGE), \
			.y = mlx->angle.y, \
			.z = mlx->angle.z \
		};
	else if (key == W)
		mlx->angle = (t_angle3d){\
			.x = ternary(mlx->angle.x >= 358, 0, mlx->angle.x + ANGLE_CHANGE), \
			.y = mlx->angle.y, \
			.z = mlx->angle.z \
		};
	else if (key == A)
		mlx->angle = (t_angle3d){\
			.x = mlx->angle.x, \
			.y = ternary(mlx->angle.y <= 0, 359, mlx->angle.y - ANGLE_CHANGE), \
			.z = mlx->angle.z \
		};
	else if (key == D)
		mlx->angle = (t_angle3d){\
			.x = mlx->angle.x, \
			.y = ternary(mlx->angle.y >= 358, 0, mlx->angle.y + ANGLE_CHANGE), \
			.z = mlx->angle.z \
		};
}

void	handle_zoom(int key, t_data *mlx)
{
	int	z_move;

	z_move = ((mlx->c_scale * ZOOM_MOVE) / CELL_SIZE) + 1;
	if (key == Z)
		mlx->c_scale += z_move;
	else if (key == X && mlx->c_scale > z_move)
		mlx->c_scale -= z_move;
	reset_camera_center(mlx);
}

void	handle_exit(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_display(mlx->mlx);
	free_map(mlx->map->map, mlx->map->height - 1);
	free(mlx->mlx);
	ft_error(CLOSED);
}

int	handle_keys(int key, t_data *mlx)
{
	if (key == ESC)
		handle_exit(mlx);
	else if (key == UP || key == RIGHT || key == DOWN || key == LEFT)
		handle_move(key, mlx);
	else if (key == Z || key == X)
		handle_zoom(key, mlx);
	else if (key == Q || key == E || key == R)
		handle_scaling(key, mlx);
	else if (key == ZERO)
		init_camera(mlx);
	else if (key == A || key == D || key == W || key == S)
		handle_rotation(key, mlx);
	return (update(mlx));
}
