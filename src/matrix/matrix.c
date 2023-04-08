/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:15:34 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/08 01:10:39 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	matrix_init(int size, ...)
{
	t_matrix	matrix;
	va_list		args;
	int			y;
	int			x;

	matrix.size = size;
	matrix.data = NULL;
	matrix.data = malloc(sizeof(double) * (int)pow(size, 2.0));
	if (!matrix.data)
		return (matrix);
	va_start(args, size);
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			matrix.data[y][x] = va_arg(args, double);
	}
	return (matrix);
}
