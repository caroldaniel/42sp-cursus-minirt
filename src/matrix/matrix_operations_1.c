/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:49:19 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/08 15:39:09 by cado-car         ###   ########.fr       */
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
			if (a.data[y][x] != b.data[y][x])
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
