/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:55:55 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/09 23:03:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		cofactor(t_matrix m, int row_idx, int col_idx);
t_matrix	submatrix(t_matrix m, int row_idx, int col_idx);

double	determinant(t_matrix m)
{
	double		det;
	int			i;

	if (m.size == 1)
		return (m.data[0][0]);
	det = 0.0;
	i = -1;
	while (++i < m.size)
		det += m.data[0][i] * cofactor(m, 0, i);
	return (det);
}

double	cofactor(t_matrix m, int row_idx, int col_idx)
{
	t_matrix	sub_m;
	double		sign;
	double		minor;

	sub_m = submatrix(m, row_idx, col_idx);
	sign = pow(-1, row_idx + col_idx);
	minor = determinant(sub_m);
	matrix_destroy(&sub_m);
	return (sign * minor);
}

t_matrix	submatrix(t_matrix m, int row_idx, int col_idx)
{
	t_matrix	sub_m;
	int			x;
	int			sub_x;
	int			y;
	int			sub_y;

	sub_m = matrix_init(m.size - 1);
	sub_y = 0;
	y = -1;
	while (++y < m.size)
	{
		if (y == row_idx)
			continue ;
		x = -1;
		sub_x = 0;
		while (++x < m.size)
		{
			if (x == col_idx)
				continue ;
			sub_m.data[sub_y][sub_x] = m.data[y][x];
			sub_x++;
		}
		sub_y++;
	}
	return (sub_m);
}
