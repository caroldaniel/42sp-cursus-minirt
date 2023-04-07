/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:10:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/06 23:44:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*------MACROS------*/

/*
** Macros for unmutable strings
*/

# define MINIRT	"MiniRT"

/*
** Macros for exit_code
*/

# define ERR_DATAINIT	1
# define ERR_MLXINIT	2

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
	void	*mlx;
	void	*mlx_win;
}	t_data;

/*
** Data utils
*/
void	data_init(t_data *data);
int		data_destroy(t_data *data, int exit_code);

void	set_hooks(t_data *data);

/*
** Utils
*/
t_bool	float_cmp(float a, float b, float epsilon);
float	abs_float(float flt);

#endif