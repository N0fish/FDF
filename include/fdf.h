/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:28:55 by algultse          #+#    #+#             */
/*   Updated: 2024/02/22 13:47:00 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"
# include "constants.h"

typedef struct s_maps {
	int	**map;
	int	height;
	int	width;
	int	zmax;
	int	zmin;
}				t_maps;

typedef struct s_angle3d {
	float	x;
	float	y;
	float	z;
}				t_angle3d;

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x_width;
	int			y_height;
	int			x_offset;
	int			y_offset;
	int			c_scale;
	int			z_scale;
	int			count;
	t_angle3d	angle;
	t_maps		*map;
}				t_data;

typedef struct s_matrix3x3 {
	float	m[3][3];
}				t_matrix3x3;

typedef struct s_point3d {
	int	x;
	int	y;
	int	z;
}				t_point3d;

typedef struct s_point2d {
	int	x;
	int	y;
}				t_point2d;

typedef struct s_pixel_data {
	double	p1p2_dist;
	double	current_dist;
	int		z_diff;
}				t_pixel_data;

/*
** error
*/
void		ft_error(int exit_fdf);
void		free_map_error(int **map, int i);
/*
** init
*/
void		init_camera(t_data *mlx);
void		init_map(char	*file_fdf, t_maps *map);
int			init_mlx(t_data *mlx);
void		reset_camera_center(t_data *mlx);
/*
** map
*/
void		fill_numbers(int fd, t_maps *map);
void		fill_zmap(t_maps *map);
void		free_map(int **map, int i);
/*
** draw_line
*/
void		draw_line(t_data *mlx, t_point2d p1, t_point2d p2, t_point2d point);
/*
** colors
*/
int			red(int red_255);
int			green(int green_255);
int			blue(int blue_255);
int			color(int red_255, int green_255, int blue_255);
int			z_color(double z, int min_z, int max_z);
/*
** utils
*/
int			ternary(int cond, int then, int or);
void		iso_proj(t_point3d p1, t_point2d *iso, t_data *data);
double		pythagore(t_point2d p1, t_point2d p2);
/*
** render
*/
int			render_map(t_maps *map);
void		pixel_put(t_data *mlx, int x, int y, unsigned int color);
int			update(t_data *data);
/*
** keys
*/
int			handle_keys(int key, t_data *mlx);
void		handle_exit(t_data *mlx);
void		handle_rotation(int key, t_data *mlx);
void		handle_scaling(int key, t_data *mlx);
void		handle_move(int key, t_data *mlx);
/*
** read
*/
void		read_file(char *file_fdf, t_maps *map);
int			ft_line(int fd, char **line);
/*
** rotation
*/
t_point3d	apply_rotation(t_point3d point, float rotx, float roty, float rotz);
/*
** text
*/
void		display_info(t_data *mlx);

#endif