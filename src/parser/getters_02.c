/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:30:36 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/20 22:12:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_sphere_properties(t_line *line, t_object **sphere);

t_object	*get_sphere(t_line *line, t_data *data)
{
	t_object	*sphere;

	sphere = NULL;
	if (!check_tuple(line->tokens[1]))
		return (sphere);
	if (!check_double(line->tokens[2]))
		return (sphere);
	if (!check_color(line->tokens[3]))
		return (sphere);
	if (!check_material(&(line->tokens[4])))
		return (sphere);
	sphere = sphere_new();
	if (!sphere)
		return (sphere);
	get_sphere_properties(line, &sphere);
	object_add(&(data->world.o_list), sphere);
	return (sphere);
}

static void	get_sphere_properties(t_line *line, t_object **sphere)
{
	t_tuple		trsl;
	double		scale;

	trsl = get_point(line->tokens[1]);
	scale = ft_atod(line->tokens[2]);
	set_object_transform(*sphere, chain_transform(2, \
		translation(trsl.x, trsl.y, trsl.z), scaling(scale, scale, scale)));
	if (!line->tokens[4])
		set_pattern(*sphere, solid_pattern(get_color(line->tokens[3])));
	else
	{
		(*sphere)->material.specular = ft_atod(line->tokens[4]);
		(*sphere)->material.bumpiness = ft_atod(line->tokens[5]);
		set_pattern(*sphere, get_pattern(line->tokens[6], line->tokens[3]));
	}
	return ;
}

t_object	*get_plane(t_line *line, t_data *data)
{
	t_object	*plane;

	plane = NULL;
	if (!check_tuple(line->tokens[1]))
		return (plane);
	if (!check_normalized_vector(line->tokens[2]))
		return (plane);
	if (!check_color(line->tokens[3]))
		return (plane);
	if (!check_material(&(line->tokens[4])))
		return (plane);
	plane = plane_new();
	if (!plane)
		return (plane);
	
}

static void	get_plane_properties(t_line *line, t_object **plane)
{
	t_tuple	trns;
	t_tuple	normal_v;
	double	rad_x;
	double	rad_z;
	
	trns = get_point(line->tokens[1]);
	normalv = get_vector(line->tokens[2]);
	rad_x = atan2(trns.z, trns.y);
	rad_z = atan2(trns.x, trns.y);
	
	if (!line->tokens[4])
		set_pattern(*sphere, solid_pattern(get_color(line->tokens[3])));
	else
	{
		(*sphere)->material.specular = ft_atod(line->tokens[4]);
		(*sphere)->material.bumpiness = ft_atod(line->tokens[5]);
		set_pattern(*sphere, get_pattern(line->tokens[6], line->tokens[3]));
	}
	return ;
}
