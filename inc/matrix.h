/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:11:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/09 00:04:08 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>

typedef struct s_matrix
{
	int		size;
	double	**data;
}	t_matrix;

t_matrix	matrix_init(int size);
t_matrix	matrix_populate(int size, ...);
t_matrix	matrix_destroy(t_matrix *matrix);

bool		matrix_compare(t_matrix a, t_matrix b);
t_matrix	matrix_multiply(t_matrix a, t_matrix b);
t_tuple		matrix_tuple_multiply(t_matrix m, t_tuple t);
t_matrix	matrix_transpose(t_matrix m);

void		print_matrix(t_matrix matrix);

#endif