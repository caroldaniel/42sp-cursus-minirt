/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:00:00 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 14:21:47 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_cylinder_properties(t_line *line, t_object **cylinder);
static void	get_cone_properties(t_line *line, t_object **cone);

t_object	*get_cylinder(t_line *line, t_data *data)
{
	t_object	*cylinder;

	cylinder = NULL;
	if (!check_tuple(line->tokens[1]))
		return (cylinder);
	if (!check_normalized_vector(line->tokens[2]))
		return (cylinder);
	if (!check_double(line->tokens[3]) || ft_atod(line->tokens[3]) < 0)
		return (cylinder);
	if (!check_double(line->tokens[4]) || ft_atod(line->tokens[4]) < 0)
		return (cylinder);
	if (!check_color(line->tokens[5]))
		return (cylinder);
	if (!check_material(&(line->tokens[6])))
		return (cylinder);
	cylinder = cylinder_new(-ft_atod(line->tokens[4]) / 2.0, \
		ft_atod(line->tokens[4]) / 2.0);
	if (!cylinder)
		return (cylinder);
	get_cylinder_properties(line, &cylinder);
	object_add(&(data->world.o_list), cylinder);
	return (cylinder);
}

static void	get_cylinder_properties(t_line *line, t_object **cylinder)
{
	t_tuple	trsl;
	t_tuple	axis;
	double	scale;
	double	rad_x;
	double	rad_z;

	trsl = get_point(line->tokens[1]);
	axis = get_vector(line->tokens[2]);
	rad_x = atan2(axis.z, axis.y);
	rad_z = atan2(axis.x, axis.y);
	scale = ft_atod(line->tokens[3]) / 2.0;
	set_object_transform(*cylinder, chain_transform(4, \
		scaling(scale, scale, scale), rotation_x(rad_x), \
		rotation_z(rad_z), translation(trsl.x, trsl.y, trsl.z)));
	if (!line->tokens[6])
		set_pattern(*cylinder, solid_pattern(get_color(line->tokens[5])));
	else
	{
		(*cylinder)->material.specular = ft_atod(line->tokens[6]);
		(*cylinder)->material.bumpiness = ft_atod(line->tokens[7]);
		set_pattern(*cylinder, get_pattern(line->tokens[8], line->tokens[5]));
	}
	return ;
}

t_object	*get_cone(t_line *line, t_data *data)
{
	t_object	*cone;

	cone = NULL;
	if (!check_tuple(line->tokens[1]))
		return (cone);
	if (!check_normalized_vector(line->tokens[2]))
		return (cone);
	if (!check_double(line->tokens[3]) || ft_atod(line->tokens[3]) < 0)
		return (cone);
	if (!check_double(line->tokens[4]) || ft_atod(line->tokens[4]) < 0)
		return (cone);
	if (!check_color(line->tokens[5]))
		return (cone);
	if (!check_material(&(line->tokens[6])))
		return (cone);
	cone = cone_new(-ft_atod(line->tokens[4]) / 2.0, \
		ft_atod(line->tokens[4]) / 2.0);
	if (!cone)
		return (cone);
	get_cone_properties(line, &cone);
	object_add(&(data->world.o_list), cone);
	return (cone);
}

static void	get_cone_properties(t_line *line, t_object **cone)
{
	t_tuple	trsl;
	t_tuple	axis;
	double	scale;
	double	rad_x;
	double	rad_z;

	trsl = get_point(line->tokens[1]);
	axis = get_vector(line->tokens[2]);
	rad_x = atan2(axis.z, axis.y);
	rad_z = atan2(axis.x, axis.y);
	scale = ft_atod(line->tokens[3]) / 2.0;
	set_object_transform(*cone, chain_transform(4, rotation_x(rad_x), \
		rotation_z(rad_z), translation(trsl.x, trsl.y, trsl.z), \
		scaling(scale, scale, scale)));
	if (!line->tokens[6])
		set_pattern(*cone, solid_pattern(get_color(line->tokens[5])));
	else
	{
		(*cone)->material.specular = ft_atod(line->tokens[6]);
		(*cone)->material.bumpiness = ft_atod(line->tokens[7]);
		set_pattern(*cone, get_pattern(line->tokens[8], line->tokens[5]));
	}
	return ;
}
