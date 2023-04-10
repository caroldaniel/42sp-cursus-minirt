/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:15:34 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 14:43:29 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	matrix_init(int size)
{
	t_matrix	matrix;
	int			y;

	matrix.size = 0;
	matrix.data = malloc(sizeof(double *) * size);
	if (!matrix.data)
		return (matrix);
	y = -1;
	while (++y < size)
	{
		matrix.data[y] = malloc(sizeof(double) * size);
		if (!matrix.data[y])
			return (matrix_destroy(&matrix));
		ft_bzero(matrix.data[y], sizeof(double) * size);
	}
	matrix.size = size;
	return (matrix);
}

t_matrix	matrix_populate(int size, ...)
{
	t_matrix	matrix;
	va_list		args;
	int			y;
	int			x;

	matrix = matrix_init(size);
	va_start(args, size);
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			matrix.data[y][x] = va_arg(args, double);
	}
	va_end(args);
	return (matrix);
}

t_matrix	matrix_destroy(t_matrix *matrix)
{
	int	i;

	i = -1;
	while (++i < matrix->size)
		if (matrix->data[i])
			free(matrix->data[i]);
	free(matrix->data);
	matrix->data = NULL;
	matrix->size = 0;
	return (*matrix);
}
