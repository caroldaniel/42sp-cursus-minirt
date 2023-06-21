/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:45:45 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 12:18:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	shade_hit(t_world world, t_light *light, t_ray *ray);
static t_color	lightning(t_hit *h);
static t_color	diffuse(t_hit h, t_color eff_color, t_tuple lightv);
static t_color	specular(t_hit h, t_tuple reflectv);

t_color	color_at(t_world world, t_ray *ray)
{
	t_color	color;

	intersect_world(world, ray);
	color = shade_hit(world, world.l_list, ray);
	return (color);
}

static t_color	shade_hit(t_world world, t_light *light, t_ray *ray)
{
	t_hit	*h;
	t_color	c;

	h = get_hit_info(world, light, ray);
	if (!h)
		return (color(0, 0, 0, 1));
	c = lightning(h);
	hit_info_destroy(&h);
	if (!light->next)
		return (c);
	return (color_add(c, shade_hit(world, light->next, ray)));
}

static t_color	lightning(t_hit *h)
{
	t_color	eff_color;
	t_tuple	lightv;
	t_color	ambient;

	eff_color = hadamard_product(h->color_hit, h->light.intensity);
	lightv = normalize(tuple_subtract(h->light.position, h->over_point));
	ambient = color_multiply(eff_color, h->light.ambient);
	if (h->in_shadow || h->light.ambient > 0.0)
		return (ambient);
	return (color_add(ambient, diffuse(*h, eff_color, lightv)));
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
