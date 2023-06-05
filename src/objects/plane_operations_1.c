/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:50:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/05 12:37:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_plane(t_object *pl, t_ray *ray)
{
	t_ray		*ray_t;
	double		t;

	ray_t = transform(ray, matrix_inverse(pl->transform));
	if (float_cmp(ray_t->direction.y, 0.0, 0.00001))
		return ;
	t = -ray_t->origin.y / ray_t->direction.y;
	ray_destroy(&ray_t);
	x_list_add(&ray->x_list, x_new(pl, t));
	return ;
}

t_tuple	normal_at_plane(t_object *pl, t_tuple p)
{
	t_tuple		pl_nml;

	pl = (t_object *)pl;
	p = (t_tuple)p;
	pl_nml = vector(0, 1, 0);
	return (pl_nml);
}
