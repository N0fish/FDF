/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:53:42 by algultse          #+#    #+#             */
/*   Updated: 2024/02/22 12:25:17 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_move(int key, t_data *mlx)
{
	if (key == LEFT)
		mlx->x_offset -= TRANSLATION_MOVE;
	else if (key == RIGHT)
		mlx->x_offset += TRANSLATION_MOVE;
	else if (key == UP)
		mlx->y_offset -= TRANSLATION_MOVE;
	else if (key == DOWN)
		mlx->y_offset += TRANSLATION_MOVE;
}

void	handle_scaling(int key, t_data *mlx)
{
	if (key == Q && (mlx->z_scale < -SCALING_MOVE \
			|| mlx->z_scale >= SCALING_MOVE))
		mlx->z_scale += SCALING_MOVE;
	else if (key == E && (mlx->z_scale > SCALING_MOVE \
			|| mlx->z_scale <= -SCALING_MOVE))
		mlx->z_scale -= SCALING_MOVE;
	else if (key == R)
		mlx->z_scale *= -1;
}
