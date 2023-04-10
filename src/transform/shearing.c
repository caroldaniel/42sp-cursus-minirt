/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:08:06 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 19:31:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	shearing(int size, ...)
{
	t_matrix	skew;
	va_list		args;
	int			x;
	int			y;

	skew = identity(size);
	if (!skew.size)
		return (skew);
	va_start(args, size);
	y = -1;
	while (++y < (size - 1))
	{
		x = -1;
		while (++x < (size - 1))
			if (x != y)
				skew.data[y][x] = va_arg(args, double);
	}
	va_end(args);
	return (skew);
}
