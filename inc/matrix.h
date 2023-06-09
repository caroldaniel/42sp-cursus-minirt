/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:11:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/24 13:11:31 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "minirt.h"

/*
** Basic libraries
*/
# include <stdbool.h>
# include <math.h>

/*
** Matrix type definition
*/
typedef struct s_matrix
{
	int		size;
	double	**data;
}	t_matrix;

/*
** Matrix utils
*/
t_matrix	matrix_init(int size);
t_matrix	matrix_populate(int size, ...);
t_matrix	matrix_destroy(t_matrix *matrix);

/*
** Matrix operations
*/
bool		matrix_compare(t_matrix a, t_matrix b);
t_matrix	matrix_multiply(t_matrix a, t_matrix b);
t_tuple		matrix_tuple_multiply(t_matrix m, t_tuple t);
t_matrix	matrix_transpose(t_matrix m);
t_matrix	matrix_inverse(t_matrix m);

/*
** Matrix operation helpers
*/
double		determinant(t_matrix m);
double		cofactor(t_matrix m, int row_idx, int col_idx);
t_matrix	submatrix(t_matrix m, int row_idx, int col_idx);
t_matrix	identity(int size);

/*
** Matrix utils
*/
void		print_matrix(t_matrix matrix);

/*
** Transformation matrix generators
*/
t_matrix	translation(double x, double y, double z);
t_matrix	scaling(double x, double y, double z);
t_matrix	rotation_x(double radians);
t_matrix	rotation_y(double radians);
t_matrix	rotation_z(double radians);
t_matrix	shearing(int size, ...);
t_matrix	chain_transform(int nb, ...);

#endif