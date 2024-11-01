/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:06:42 by algultse          #+#    #+#             */
/*   Updated: 2024/02/20 01:27:41 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_info(t_data *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 10, 20, 0xffffff, \
		"ZOOM: + [Z], - [X]");
	mlx_string_put(mlx->mlx, mlx->win, 10, 40, 0xffffff, \
		"Z SCALE: + [E], - [Q]");
	mlx_string_put(mlx->mlx, mlx->win, 10, 60, 0xffffff, \
		"TRANSLATION: [UP], [DOWN], [LEFT], [RIGHT]");
	mlx_string_put(mlx->mlx, mlx->win, 10, 80, 0xffffff, \
		"ROTATION X: [W], [S] | ROTATION Y: [A], [D]");
	mlx_string_put(mlx->mlx, mlx->win, 10, 100, 0xffffff, \
		"REVERSE Z: [R]");
	mlx_string_put(mlx->mlx, mlx->win, 10, 120, 0xffffff, \
		"RESET: [ZERO]");
}
