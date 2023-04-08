/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:36 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/08 01:02:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_matrix(t_matrix matrix)
{
	int x;
	int y;

	y = -1;
	while (++y < matrix.size)
	{
		x = -1;
		while (++x < matrix.size)
			printf("%f ", matrix.data[y][x]);
		printf("\n");
	}
}
