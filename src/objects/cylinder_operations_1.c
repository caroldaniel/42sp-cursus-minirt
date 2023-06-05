/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_operations_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:50:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 23:23:15 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_cylinder(t_object *s, t_ray *ray)
{
	t_ray		*ray_t;
	double		coef[3];
	double		disc;

	ray_t = transform(ray, matrix_inverse(s->transform));
	coef[0] = pow(ray_t->direction.x, 2.0) + pow(ray_t->direction.z, 2.0);
	if (float_cmp(coef[0], 0.0, 0.001) == true)
		return ;
	coef[1] = 2 * ray_t->origin.x * ray_t->direction.x + \
		2 * ray_t->origin.z * ray_t->direction.z;
	coef[2] = pow(ray_t->origin.x, 2.0) + pow(ray_t->origin.z, 2.0) - 1;
	ray_destroy(&ray_t);
	disc = pow(coef[1], 2.0) - 4.0 * coef[0] * coef[2];
	if (disc < 0)
		return ;
	x_list_add(&ray->x_list, x_new(s, (-coef[1] - sqrt(disc)) / (2 * coef[0])));
	x_list_add(&ray->x_list, x_new(s, (-coef[1] + sqrt(disc)) / (2 * coef[0])));
}

t_tuple	normal_at_cylinder(t_object *c, t_tuple p)
{
	t_matrix	inv;
	t_matrix	trs;
	t_tuple		o_p;
	t_tuple		o_nml;
	t_tuple		nml;

	inv = matrix_inverse(c->transform);
	o_p = matrix_tuple_multiply(inv, p);
	o_nml = vector(o_p.x, 0, o_p.z);
	trs = matrix_transpose(inv);
	nml = matrix_tuple_multiply(trs, o_nml);
	nml.w = 0;
	matrix_destroy(&inv);
	matrix_destroy(&trs);
	return (normalize(nml));
}
