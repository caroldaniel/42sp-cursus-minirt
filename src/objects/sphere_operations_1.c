/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:32:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 13:12:34 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_sphere(t_object *s, t_ray *ray)
{
	t_ray		*t_ray;
	t_tuple		s_to_ray;
	double		coef[3];
	double		disc;

	t_ray = transform(ray, matrix_inverse(s->transform));
	s_to_ray = tuple_subtract(t_ray->origin, point(0, 0, 0));
	coef[0] = dot(t_ray->direction, t_ray->direction);
	coef[1] = 2 * dot(t_ray->direction, s_to_ray);
	coef[2] = dot(s_to_ray, s_to_ray) - 1;
	ray_destroy(&t_ray);
	disc = pow(coef[1], 2.0) - 4.0 * coef[0] * coef[2];
	if (disc < 0)
		return ;
	x_list_add(&ray->x_list, x_new(s, (-coef[1] - sqrt(disc)) / (2 * coef[0])));
	x_list_add(&ray->x_list, x_new(s, (-coef[1] + sqrt(disc)) / (2 * coef[0])));
}

t_tuple	normal_at_sphere(t_object *s, t_tuple p)
{
	t_matrix	inv;
	t_matrix	trs;
	t_tuple		o_p;
	t_tuple		o_nml;
	t_tuple		nml;

	inv = matrix_inverse(s->transform);
	o_p = matrix_tuple_multiply(inv, p);
	o_nml = tuple_subtract(o_p, point(0, 0, 0));
	trs = matrix_transpose(inv);
	nml = matrix_tuple_multiply(trs, o_nml);
	nml.w = 0;
	matrix_destroy(&inv);
	matrix_destroy(&trs);
	return (normalize(nml));
}
