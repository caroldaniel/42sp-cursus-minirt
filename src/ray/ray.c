/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:35:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 23:19:00 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;
	
	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_intersection	intersection(int object, int count, ...)
{
	t_intersection	inter;
	va_list			args;
	int				i;

	inter.object = object;
	inter.count = count;
	inter.t = NULL;
	if (!count)
		return (inter);
	inter.t = malloc(sizeof(double) * count);
	if (!inter.t)
		return (inter);
	va_start(args, count);
	i = -1;
	while (++i < count)
		inter.t[i] = va_arg(args, double);
	va_end(args);
	return (inter);
}
