/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:57:18 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 21:07:38 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_shadowed(t_world world, t_light *light, t_tuple point);

t_hit	*get_hit_info(t_world world, t_light *light, t_ray *ray)
{
	t_hit	*h_light;
	t_x		*h;

	h = hit(ray);
	if (!h)
		return (NULL);
	h_light = malloc(sizeof(t_hit));
	if (!h_light)
		return (NULL);
	h_light->point = position(ray, h->t);
	h_light->eyev = tuple_negate(ray->direction);
	h_light->normalv = normal_at(h->object, h_light->point);
	h_light->light = *light;
	h_light->material = h->object->material;
	h_light->color_hit = pattern_at_object(h->object, h_light->point);
	h_light->inside = true;
	if (dot(h_light->normalv, h_light->eyev) < 0)
		h_light->normalv = tuple_negate(h_light->normalv);
	else
		h_light->inside = false;
	h_light->over_point = tuple_add(h_light->point, \
		tuple_multiply(h_light->normalv, 0.00001));
	h_light->in_shadow = is_shadowed(world, light, h_light->over_point);
	return (h_light);
}

static bool	is_shadowed(t_world world, t_light *light, t_tuple point)
{
	t_tuple	v;
	double	distance;
	t_tuple	direction;
	t_ray	*r;
	t_x		*h;

	v = tuple_subtract(light->position, point);
	distance = magnitude(v);
	direction = normalize(v);
	r = ray_new(point, direction);
	intersect_world(world, r);
	h = hit(r);
	if (h && h->t < distance)
		return (true);
	return (false);
}

void	hit_info_destroy(t_hit **h_light)
{
	if (!(*h_light))
		return ;
	free(*h_light);
	return ;
}
