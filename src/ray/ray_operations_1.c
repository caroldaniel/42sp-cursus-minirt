/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:40:36 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 14:05:01 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	position(t_ray ray, double t)
{
	t_tuple	pos;
	t_tuple	mult;

	mult = tuple_multiply(ray.direction, t);
	pos = tuple_add(ray.origin, mult);
	return (pos);
}
