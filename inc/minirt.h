/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:10:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 23:48:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*------MACROS------*/

/*
** Macros for the window
*/

# define RT				"MiniRT"
# define IMG_X			10
# define IMG_Y			10
# define BIG_ENDIAN		1
# define EPSILON		0.0001

/*
** Macros for exit_codes
*/

# define ERR_WRNGARG	1
# define ERR_MEMALOC	2
# define ERR_MLXINIT	3
# define ERR_EXTINVL	4
# define ERR_FDERROR	5

/*
** Macros for message colors
*/

# define ESC_BOLD_ORANGE	"\033[1;33m"
# define ESC_BOLD_GREEN		"\033[1;32m"
# define ESC_BOLD_RED		"\033[1;31m"
# define ESC_RESET_COLOR	"\033[0m"

/*------LIBRARIES------*/

/*
** Basic libraries for the previous allowed functions: open, read, write, close,
** malloc, free, perror, strerror and exit. 
*/
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

/*
** Allowed libraries: math and minilibx, witch is appended in the project's 
** folder to guarantee usage by testers. 
*/

# include <math.h>
# include "../lib/libmlx/mlx.h"

/*
** My own libft library, completed with previously implemented functions such as
** get_next_line and ft_printf. 
*/
# include "../lib/libft/libft.h"

/*
** Personal libraries
*/
# include "colors.h"
# include "tuples.h"
# include "matrix.h"
# include "keys.h"
# include "scene.h"

/*
** Bhaskara type definition
*/
typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_bhaskara;

/*
** Point type definition
*/
typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

/*
** WIndow type definition
*/
typedef struct s_win
{
	void	*ptr;
	int		y;
	int		x;
}	t_win;

/*
** Data type definition
*/
typedef struct s_data
{
	void	*mlx_ptr;
	t_win	win;
	t_img	img;
	t_cam	camera;
	t_world	world;
}	t_data;

/*
** Data utils
*/
void		data_init(t_data *data, char *file_path);
int			data_destroy(t_data *data, int exit_code);
void		set_hooks(t_data *data);

/*
** Coordinate utils
*/
t_coord		coordinate(int x, int y);

/*
** Image utils
*/
void		image_init(t_data *data);
void		image_create(t_data *data);
void		image_display(t_data *data);
void		draw_line(t_data *data, t_coord a, t_coord b, t_color c);
void		render(t_data *data);
void		put_pixel(t_img img, int x, int y, t_color color);

/*
** World management
*/
void		world_init(t_data *data);
void		world_destroy(t_world *world);
void		intersect_world(t_world world, t_ray *ray);

/*
** Utils
*/
t_bhaskara	get_delta(t_object *object, t_ray *l_ray);
void		update_progress_bar(int current, int total);
bool		comp(double a, double b, double epsilon);

#endif