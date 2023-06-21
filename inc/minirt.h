/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:10:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 13:38:40 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*------MACROS------*/

/*
** Macros for the window
*/

# define RT				"MiniRT"
# define IMG_X			200
# define IMG_Y			200
# define BIG_ENDIAN		1
# define EPSILON		0.0001

/*
** Macros for exit_codes
*/

# define ERR_WRNGARG	1
# define ERR_MEMALOC	2
# define ERR_MLXINIT	3
# define ERR_WININIT	4
# define ERR_IMGINIT	5
# define ERR_EXTINVL	6
# define ERR_FDERROR	7
# define ERR_INVELEM	8
# define ERR_SCNCNTR	9
# define ERR_PARSERA	10
# define ERR_PARSEAM	11
# define ERR_PARSECA	12
# define ERR_PARSELI	13
# define ERR_PARSESP	14
# define ERR_PARSEPL	15
# define ERR_PARSECY	16
# define ERR_PARSECN	17

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
# include <limits.h>

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
** Parser elements struct definition
*/
typedef struct s_line
{
	char			**tokens;
	struct s_line	*next;
}	t_line;

/*
**	ELements struct definition
*/
typedef struct s_element
{
	int		count;
	bool	locked;
}	t_element;

/*
** Elements counter struct definition
*/
typedef struct s_counter
{
	t_element	ratio;
	t_element	ambient;
	t_element	camera;
	t_element	light;
	t_element	sphere;
	t_element	plane;
	t_element	cylinder;
	t_element	cone;
}	t_counter;

/*
** Data type definition
*/
typedef struct s_data
{
	int		fd;
	void	*mlx_ptr;
	t_win	win;
	t_img	img;
	t_cam	*camera;
	t_world	world;
	t_line	*line_list;
}	t_data;

/*
** Data utils
*/
void		data_init(t_data *data, char *file_path);
int			data_destroy(t_data *data, int exit_code);
void		set_hooks(t_data *data);

/*
**	Parser line struct utils
*/
t_line		*line_new(char *content);
void		line_add(t_line **list, t_line *new);
void		line_destroy(t_line **line);
void		line_list_destroy(t_line **list);

/*
**	Parser utils
*/
void		parser(t_data *data);
char		**tokenizer(char const *s);
void		token_array_destroy(char **matrix);

/*
**	Checkers
*/
bool		check_count(t_line *line);
bool		check_element(char *identifier);
bool		check_element_properties_count(t_line *line);
bool		check_range(double value, double min, double max);
bool		check_ratio(char *token);
bool		check_int(char *token);
bool		check_double(char *token);
bool		check_color(char *token);
bool		check_tuple(char *token);
bool		check_normalized_vector(char *token);
bool		check_material(char **tokens);

/*
**	Getters
*/
t_color		get_color(char *token);
t_tuple		get_vector(char *token);
t_tuple		get_point(char *token);
t_pattern	get_pattern(char *pattern, char *color_str);
void		get_element_properties(t_line *line, t_data *data);
bool		get_ratio(t_line *line, t_data *data);
t_light		*get_ambient(t_line *line, t_data *data);
t_light		*get_light(t_line *line, t_data *data);
t_cam		*get_camera(t_line *line, t_data *data);
t_object	*get_sphere(t_line *line, t_data *data);
t_object	*get_plane(t_line *line, t_data *data);
t_object	*get_cylinder(t_line *line, t_data *data);
t_object	*get_cone(t_line *line, t_data *data);

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
int			random_nb(void);
bool		comp(double a, double b, double epsilon);
bool		comp_str(const char *str1, const char *str2);

#endif