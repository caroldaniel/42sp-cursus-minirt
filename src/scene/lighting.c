/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:57:18 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 13:20:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	diffuse(t_hit h, t_color eff_color, t_tuple lightv);
static t_color	specular(t_hit h, t_tuple reflectv);

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

t_color	lightning(t_hit h)
{
	t_color	eff_color;
	t_tuple	lightv;
	t_color	ambient;

	eff_color = hadamard_product(h.material.color, h.light.intensity);
	lightv = normalize(tuple_subtract(h.light.position, h.point));
	ambient = color_multiply(eff_color, h.material.ambient);
	return (color_add(ambient, diffuse(h, eff_color, lightv)));
}

static t_color	diffuse(t_hit h, t_color eff_color, t_tuple lightv)
{
	double	light_dot;
	t_color	diffuse;
	t_tuple	reflectv;

	light_dot = dot(lightv, h.normalv);
	if (light_dot < 0)
		return (color_add(color(0, 0, 0, 1), color(0, 0, 0, 1)));
	diffuse = color_multiply(eff_color, h.material.diffuse * light_dot);
	reflectv = reflect(tuple_negate(lightv), h.normalv);
	return (color_add(diffuse, specular(h, reflectv)));
}

static t_color	specular(t_hit h, t_tuple reflectv)
{
	double	reflect_dot;
	double	factor;

	reflect_dot = dot(reflectv, h.eyev);
	if (reflect_dot <= 0)
		return (color(0, 0, 0, 1));
	factor = pow(reflect_dot, h.material.shininess);
	return (color_multiply(h.light.intensity, h.material.specular * factor));
}
