/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:31:55 by algultse          #+#    #+#             */
/*   Updated: 2024/02/20 01:28:37 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int exit_fdf)
{
	if (exit_fdf == CLOSED)
		ft_printf("FDF closed. Adios :)\n");
	else if (exit_fdf == NO_FDF)
		ft_printf("Wrong usage. Expected './fdf <file_path>'.\n");
	else if (exit_fdf == LIRE_FICHIER_IMPOSSIBLE)
		ft_printf("Cannot read file.\n");
	else if (exit_fdf == ERROR_CLOSING)
		ft_printf("Error while closing file.\n");
	else if (exit_fdf == EMPTY_FILE)
		ft_printf("File is empty.\n");
	else if (exit_fdf == ERROR_MAP)
		ft_printf("Cannot parse map.\n");
	else if (exit_fdf == MALLOC_NULL)
		ft_printf("Cannot do malloc.\n");
	else if (exit_fdf == SPLIT_ERROR)
		ft_printf("Error during ft_split.\n");
	exit(exit_fdf);
}

void	free_map_error(int **map, int i)
{
	free_map(map, i);
	ft_error(MALLOC_NULL);
}
