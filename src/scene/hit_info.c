/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:57:18 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/21 16:07:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	*get_hit_info(t_light *light, t_ray *ray)
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
	h_light->inside = true;		
	if (dot(h_light->normalv, h_light->eyev) < 0)
		h_light->normalv = tuple_negate(h_light->normalv);
	else
		h_light->inside = false;		
	return (h_light);
}

void	hit_info_destroy(t_hit **h_light)
{
	if (!(*h_light))
		return ;
	free(*h_light);
	return ;
}

