/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:32:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/06 18:43:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_sphere(t_object *s, t_ray *ray, t_ray *local_ray)
{
	t_tuple		sphere_to_ray;
	double		coef[3];
	double		disc;

	sphere_to_ray = tuple_subtract(local_ray->origin, point(0, 0, 0));
	coef[0] = dot(local_ray->direction, local_ray->direction);
	coef[1] = 2 * dot(local_ray->direction, sphere_to_ray);
	coef[2] = dot(sphere_to_ray, sphere_to_ray) - 1;
	disc = pow(coef[1], 2.0) - 4.0 * coef[0] * coef[2];
	if (disc < 0)
		return ;
	x_list_add(&ray->x_list, x_new(s, (-coef[1] - sqrt(disc)) / (2 * coef[0])));
	x_list_add(&ray->x_list, x_new(s, (-coef[1] + sqrt(disc)) / (2 * coef[0])));
}

t_tuple	normal_at_sphere(t_object *s, t_tuple p)
{
	t_tuple	sph_nml;

	s = (t_object *)s;
	sph_nml = tuple_subtract(p, point(0, 0, 0));
	return (sph_nml);
}
