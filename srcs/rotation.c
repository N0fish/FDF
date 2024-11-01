/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:44:06 by algultse          #+#    #+#             */
/*   Updated: 2024/02/22 11:54:11 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix3x3	rotate_x_matrix(float angle)
{
	float	rad;

	rad = angle * M_PI / 180.0;
	return ((t_matrix3x3){\
		.m = {\
			{1, 0, 0}, \
			{0, cos(rad), -sin(rad)}, \
			{0, sin(rad), cos(rad)} \
		} \
	});
}

t_matrix3x3	rotate_y_matrix(float angle)
{
	float	rad;

	rad = angle * M_PI / 180.0;
	return ((t_matrix3x3){\
		.m = {\
			{cos(rad), 0, sin(rad)}, \
			{0, 1, 0}, \
			{-sin(rad), 0, cos(rad)} \
		} \
	});
}

t_matrix3x3	rotate_z_matrix(float angle)
{
	float	rad;

	rad = angle * M_PI / 180.0;
	return ((t_matrix3x3){\
		.m = {\
			{cos(rad), -sin(rad), 0}, \
			{sin(rad), cos(rad), 0}, \
			{0, 0, 1} \
		} \
	});
}

t_matrix3x3	matrix_multiply(t_matrix3x3 a, t_matrix3x3 b)
{
	t_matrix3x3	result;
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	result = (t_matrix3x3){0};
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			while (k < 3)
			{
				result.m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

t_point3d	apply_rotation(t_point3d p, float rotx, float roty, float rotz)
{
	t_matrix3x3	rx;
	t_matrix3x3	ry;
	t_matrix3x3	rz;
	t_matrix3x3	comb;
	t_point3d	rotated_point;

	rx = rotate_x_matrix(rotx);
	ry = rotate_y_matrix(roty);
	rz = rotate_z_matrix(rotz);
	comb = matrix_multiply(matrix_multiply(rz, ry), rx);
	rotated_point = (t_point3d){\
		.x = p.x * comb.m[0][0] + p.y * comb.m[0][1] + p.z * comb.m[0][2], \
		.y = p.x * comb.m[1][0] + p.y * comb.m[1][1] + p.z * comb.m[1][2], \
		.z = p.x * comb.m[2][0] + p.y * comb.m[2][1] + p.z * comb.m[2][2] \
	};
	return (rotated_point);
}
