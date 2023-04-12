/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:32:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 14:04:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_x_list	intersect_sphere(int sphere, t_ray ray)
{
	t_tuple	sphere_to_ray;
	double	discriminant;
	double	a;
	double	b;
	double	c;

	sphere_to_ray = tuple_subtract(ray.origin, point(0, 0, 0));
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = pow(b, 2.0) - 4 * a * c;
	if (discriminant < 0)
		return (x_list(0));
	else
		return (x_list(2, \
			intersection(sphere, (-b - sqrt(discriminant)) / (2 * a)), \
			intersection(sphere, (-b + sqrt(discriminant)) / (2 * a))));
}
