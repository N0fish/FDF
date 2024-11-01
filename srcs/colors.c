/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:08:42 by algultse          #+#    #+#             */
/*   Updated: 2024/02/23 18:39:35 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	red(int red_255)
{
	return (red_255 << 16);
}

int	green(int green_255)
{
	return (green_255 << 8);
}

int	blue(int blue_255)
{
	return (blue_255);
}

int	color(int red_255, int green_255, int blue_255)
{
	return (red(red_255) | green(green_255) | blue(blue_255));
}

int	z_color(double z, int min_z, int max_z)
{
	int		span_len;
	double	z_perc;

	if (min_z == max_z)
		return (color(LIGHT_GRAY, LIGHT_GRAY, LIGHT_GRAY));
	else
	{
		span_len = max_z - min_z;
		z_perc = (z - min_z) / (double)span_len;
		return (color((int)(z_perc * 255), \
			(int)(128 - (z_perc * 127.5)), \
			(int)(255 - (z_perc * 255))));
	}
}
