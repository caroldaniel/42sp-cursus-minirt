/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:08:16 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 14:04:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	intersection(int object, double t)
{
	t_intersection	x;

	x.object = object;
	x.t = t;
	return (x);
}

t_x_list	x_list(int count, ...)
{
	va_list			args;
	t_x_list		xl;
	int				i;

	xl.count = count;
	xl.list = NULL;
	if (!count)
		return (xl);
	xl.list = malloc(sizeof(t_intersection) * count);
	if (!xl.list)
		return (xl);
	va_start(args, count);
	i = -1;
	while (++i < count)
		xl.list[i] = va_arg(args, t_intersection);
	va_end(args);
	return (xl);
}
