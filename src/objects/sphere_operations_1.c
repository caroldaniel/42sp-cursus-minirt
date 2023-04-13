/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:32:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 23:24:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_x_list	intersect_sphere(t_object sphere, t_ray ray)
{
	t_tuple		sphere_to_ray;
	double		coef[3];
	double		disc;
	t_x_list	xl;

	ray = transform(ray, matrix_inverse(sphere.transform));
	sphere_to_ray = tuple_subtract(ray.origin, point(0, 0, 0));
	coef[0] = dot(ray.direction, ray.direction);
	coef[1] = 2 * dot(ray.direction, sphere_to_ray);
	coef[2] = dot(sphere_to_ray, sphere_to_ray) - 1;
	disc = pow(coef[1], 2.0) - 4.0 * coef[0] * coef[2];
	xl = x_list_init();
	if (disc < 0)
		return (xl);
	return (x_list(&xl, 2, \
		intersection(sphere, (-coef[1] - sqrt(disc)) / (2 * coef[0])), \
		intersection(sphere, (-coef[1] + sqrt(disc)) / (2 * coef[0]))));
}

void	set_transform(t_object *object, t_matrix t)
{
	matrix_destroy(&object->transform);
	object->transform = t;
}
