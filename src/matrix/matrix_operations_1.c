/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:49:19 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/05 15:48:02 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	matrix_compare(t_matrix a, t_matrix b)
{
	int	x;
	int	y;

	if (a.size != b.size)
		return (false);
	y = -1;
	while (++y < a.size)
	{
		x = -1;
		while (++x < a.size)
			if (!float_cmp(a.data[y][x], b.data[y][x], EPSILON))
				return (false);
	}
	return (true);
}

t_matrix	matrix_multiply(t_matrix a, t_matrix b)
{
	t_matrix	mult;
	int			x;
	int			y;
	int			i;

	if (a.size != b.size)
		return (matrix_init(0));
	mult = matrix_init(a.size);
	y = -1;
	while (++y < a.size)
	{
		x = -1;
		while (++x < a.size)
		{
			i = -1;
			while (++i < a.size)
				mult.data[y][x] += a.data[y][i] * b.data[i][x];
		}
	}
	return (mult);
}

t_tuple	matrix_tuple_multiply(t_matrix m, t_tuple t)
{
	t_tuple	result;

	if (m.size != 4)
		return (tuple(0, 0, 0, 0));
	result = tuple(0, 0, 0, 0);
	result.x = m.data[0][0] * t.x + m.data[0][1] * t.y + \
		m.data[0][2] * t.z + m.data[0][3] * t.w;
	result.y = m.data[1][0] * t.x + m.data[1][1] * t.y + \
		m.data[1][2] * t.z + m.data[1][3] * t.w;
	result.z = m.data[2][0] * t.x + m.data[2][1] * t.y + \
		m.data[2][2] * t.z + m.data[2][3] * t.w;
	result.w = m.data[3][0] * t.x + m.data[3][1] * t.y + \
		m.data[3][2] * t.z + m.data[3][3] * t.w;
	return (result);
}

t_matrix	matrix_transpose(t_matrix m)
{
	t_matrix	t;
	int			y;
	int			x;

	t = matrix_init(m.size);
	y = -1;
	while (++y < m.size)
	{
		x = -1;
		while (++x < m.size)
			t.data[y][x] = m.data[x][y];
	}
	return (t);
}

t_matrix	matrix_inverse(t_matrix m)
{
	t_matrix	m_inv;
	int			y;
	int			x;

	if (!determinant(m))
		return (matrix_init(0));
	m_inv = matrix_init(m.size);
	y = -1;
	while (++y < m.size)
	{
		x = -1;
		while (++x < m.size)
			m_inv.data[x][y] = cofactor(m, y, x) / determinant(m);
	}
	return (m_inv);
}
