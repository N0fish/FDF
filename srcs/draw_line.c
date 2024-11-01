/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:40 by algultse          #+#    #+#             */
/*   Updated: 2024/02/25 14:18:18 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_points(t_point2d *d, t_point2d *s, t_point2d p1, t_point2d p2)
{
	s->x = ternary(p1.x < p2.x, 1, -1);
	s->y = ternary(p1.y < p2.y, 1, -1);
	d->x = abs(p2.x - p1.x);
	d->y = -abs(p2.y - p1.y);
}

void	pixel_put(t_data *mlx, int x, int y, unsigned int color)
{
	char	*d;

	if (x >= 0 && x < mlx->x_width && y >= 0 && y < mlx->y_height)
	{
		d = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
		*(unsigned int *)d = color;
	}
}

double	compute_z(t_pixel_data px, t_point2d p1, t_point2d p2, t_point2d point)
{
	double	curr_p;

	px.current_dist = pythagore(p1, p2);
	curr_p = px.current_dist / px.p1p2_dist;
	if (point.x > point.y)
		return ((double)(point.y - point.x) + (px.z_diff * curr_p));
	if (point.y > point.x)
		return ((double)(point.x - point.y) + (px.z_diff * curr_p));
	return ((double) point.x);
}

void	compute_movement(int *err, t_point2d *p1, t_point2d d, t_point2d s)
{
	int	e2;

	e2 = 2 * (*err);
	if (e2 >= d.y)
	{
		*err += d.y;
		p1->x += s.x;
	}
	if (e2 <= d.x)
	{
		*err += d.x;
		p1->y += s.y;
	}
}

void	draw_line(t_data *mlx, t_point2d p1, t_point2d p2, t_point2d point)
{
	t_point2d		d;
	t_point2d		s;
	t_pixel_data	px;
	int				err;

	reset_points(&d, &s, p1, p2);
	px.p1p2_dist = pythagore(p1, p2);
	px.z_diff = abs(point.y - point.x);
	err = d.x + d.y;
	while (1)
	{
		if (p1.x + mlx->x_offset > 0 && p1.x + mlx->x_offset <= WIN_W && \
			p1.y + mlx->y_offset > 0 && p1.y + mlx->y_offset <= WIN_H)
			pixel_put(mlx, p1.x + mlx->x_offset, p1.y + mlx->y_offset, \
				z_color(compute_z(px, p1, p2, point), \
					mlx->map->zmin, mlx->map->zmax));
		if (p1.x == p2.x && p1.y == p2.y)
			return ;
		compute_movement(&err, &p1, d, s);
	}
}
