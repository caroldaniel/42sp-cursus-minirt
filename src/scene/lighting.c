/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:57:18 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/14 19:58:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	diffuse(t_lighting p, t_color eff_color, t_tuple lightv);
static t_color	specular(t_lighting p, t_tuple reflectv);

t_lighting point_on_light(t_scene s, t_ray ray, t_x *hit)
{
	t_lighting	p_light;

	p_light.point = position(ray, hit->t);
	p_light.eyev = s.eyev;
	p_light.normalv = normal_at(hit->object, p_light.point);
	p_light.light = s.light;
	p_light.material = hit->object.material;
	return (p_light);	
}
t_color	lightning(t_lighting p)
{
	t_color eff_color;
	t_tuple	lightv;
	t_color	ambient;
	
	eff_color = hadamard_product(p.material.color, p.light.intensity);
	lightv = normalize(tuple_subtract(p.light.position, p.point));
	ambient = color_multiply(eff_color, p.material.ambient);
	return (hadamard_product(ambient, diffuse(p, eff_color, lightv)));
}

static t_color	diffuse(t_lighting p, t_color eff_color, t_tuple lightv)
{
	double	light_dot;
	t_color	diffuse;
	t_tuple	reflectv;

	light_dot = dot(lightv, p.normalv);
	if (light_dot < 0)
		return (color_add(color(0, 0, 0, 1), color(0, 0, 0, 1)));
	diffuse = color_multiply(eff_color, p.material.diffuse * light_dot);
	reflectv = reflect(tuple_negate(lightv), p.normalv);
	return (hadamard_product(diffuse, specular(p, reflectv)));
}

static t_color	specular(t_lighting p, t_tuple reflectv)
{
	double	reflect_dot;
	t_color	specular;
	
	reflect_dot = dot(reflectv, p.eyev);
	if (reflect_dot <= 0)
		specular = color(0, 0, 0, 1);
	else
		specular = color_multiply(p.light.intensity, p.material.specular * \
			pow(reflect_dot, p.material.shininess));
	return (specular);
}
