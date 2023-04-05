/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:10:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 15:47:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

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
# include "../lib/minilibx/mlx.h"

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

/*
** Boolean type definition
*/
typedef enum e_bool
{
	false,
	true
}	t_bool;

/*
** Utils
*/
t_bool	float_cmp(float a, float b, float epsilon);
float	abs_float(float flt);

#endif