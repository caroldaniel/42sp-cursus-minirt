/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:10:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 21:11:12 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*------MACROS------*/

/*
** Macros for the window
*/

# define MINIRT			"MiniRT"
# define IMG_X			500
# define IMG_Y			500
# define BIG_ENDIAN		1

/*
** Macros for exit_codes
*/

# define ERR_MLXINIT	1
# define ERR_IMGINIT	2

/*------LIBRARIES------*/

/*
** Basic libraries for the previous allowed functions: open, read, write, close,
** malloc, free, perror, strerror and exit. 
*/
# include <stdio.h>
# include <stdlib.h>
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
# include "tuples.h"
# include "colors.h"
# include "keys.h"

/*
** Boolean type definition
*/
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

/*
** Data type definition
*/
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

/*
** Data utils
*/
void	data_init(t_data *data);
int		data_destroy(t_data *data, int exit_code);

void	image_init(t_data *data);
void	image_generate(t_img *img);
void	image_create(t_data *data);

void	set_hooks(t_data *data);

/*
** Utils
*/
t_bool	float_cmp(float a, float b, float epsilon);
float	abs_float(float flt);

#endif