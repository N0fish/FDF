/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:09:41 by algultse          #+#    #+#             */
/*   Updated: 2024/02/22 13:05:38 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ternary(int cond, int then, int or)
{
	if (cond)
		return (then);
	return (or);
}

double	pythagore(t_point2d p1, t_point2d p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

void	iso_proj(t_point3d p1, t_point2d *iso, t_data *data)
{
	if (p1.z > 0)
		p1.z /= data->z_scale;
	p1 = apply_rotation(p1, data->angle.x, data->angle.y, data->angle.z);
	p1.x *= data->c_scale;
	p1.y *= data->c_scale;
	p1.z *= data->c_scale;
	if (iso != NULL)
	{
		if (iso->x != -1)
			iso->x = p1.x - p1.y;
		if (iso->y != -1)
			iso->y = (p1.x + p1.y) / 2 - p1.z;
	}
}
