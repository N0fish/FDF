/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:44:45 by algultse          #+#    #+#             */
/*   Updated: 2024/02/22 13:45:13 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_iso_and_draw(t_data *data, t_point3d c)
{
	t_point2d	p1;
	t_point2d	p2;
	t_point2d	p3;

	ft_memset(&p1, 0, sizeof(t_point2d));
	ft_memset(&p2, 0, sizeof(t_point2d));
	ft_memset(&p3, 0, sizeof(t_point2d));
	iso_proj(c, &p1, data);
	if (c.x < data->map->width - 1)
	{
		iso_proj((t_point3d){c.x + 1, c.y, data->map->map[c.y][c.x + 1]}, \
			&p2, data);
		draw_line(data, p1, p2, (t_point2d){data->map->map[c.y][c.x + 1], c.z});
	}
	if (c.y < data->map->height - 1)
	{
		iso_proj((t_point3d){c.x, c.y + 1, data->map->map[c.y + 1][c.x]}, \
			&p3, data);
		draw_line(data, p1, p3, (t_point2d){c.z, data->map->map[c.y + 1][c.x]});
	}
}

void	clear_image(t_data *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->y_height)
	{
		x = 0;
		while (x < mlx->x_width)
		{
			pixel_put(mlx, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

int	update(t_data *data)
{
	int	x;
	int	y;

	clear_image(data);
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			apply_iso_and_draw(data, (t_point3d){x, y, data->map->map[y][x]});
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	display_info(data);
	return (0);
}

int	close_window(t_data *mlx)
{
	handle_exit(mlx);
	return (0);
}

int	render_map(t_maps *map)
{
	t_data	mlx;
	int		err;

	ft_memset(&mlx, 0, sizeof(t_data));
	mlx.map = map;
	init_camera(&mlx);
	err = init_mlx(&mlx);
	if (err != 0)
		return (err);
	mlx_hook(mlx.win, 33, 1L << 9, close_window, &mlx);
	mlx_key_hook(mlx.win, &handle_keys, &mlx);
	mlx_expose_hook(mlx.win, &update, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
