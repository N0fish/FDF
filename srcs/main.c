/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:28:44 by algultse          #+#    #+#             */
/*   Updated: 2024/02/20 01:18:22 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_maps	map;

	if (argc != 2)
		ft_error(NO_FDF);
	read_file(argv[1], &map);
	init_map(argv[1], &map);
	return (render_map(&map));
}
