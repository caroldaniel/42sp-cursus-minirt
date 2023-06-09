/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:21:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/24 21:58:12 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_element_properties(t_line *line, t_data *data)
{
	t_line	*curr;

	curr = line;
	while (curr)
	{
		if ((comp_str(curr->tokens[0], "R")) && !get_ratio(curr, data))
			exit(data_destroy(data, ERR_PARSERA));
		if ((comp_str(curr->tokens[0], "A")) && !get_ambient(curr, data))
			exit(data_destroy(data, ERR_PARSEAM));
		if (comp_str(curr->tokens[0], "C") && !get_camera(curr, data))
			exit(data_destroy(data, ERR_PARSECA));
		if (comp_str(curr->tokens[0], "L") && !get_light(curr, data))
			exit(data_destroy(data, ERR_PARSELI));
		if (comp_str(curr->tokens[0], "sp") && !get_sphere(curr, data))
			exit(data_destroy(data, ERR_PARSESP));
		if (comp_str(curr->tokens[0], "pl") && !get_plane(curr, data))
			exit(data_destroy(data, ERR_PARSEPL));
		if (comp_str(curr->tokens[0], "cy") && !get_cylinder(curr, data))
			exit(data_destroy(data, ERR_PARSECY));
		if (comp_str(curr->tokens[0], "cn") && !get_cone(curr, data))
			exit(data_destroy(data, ERR_PARSECN));
		curr = curr->next;
	}
	return ;
}

bool	get_ratio(t_line *line, t_data *data)
{
	if (!check_int(line->tokens[1]) || !check_int(line->tokens[2]))
		return (false);
	data->img.x = ft_atoi(line->tokens[1]);
	data->img.y = ft_atoi(line->tokens[2]);
	data->win.x = data->img.x;
	data->win.y = data->img.y;
	return (true);
}

t_light	*get_ambient(t_line *line, t_data *data)
{
	t_light	*ambient;

	ambient = NULL;
	if (!check_ratio(line->tokens[1]))
		return (ambient);
	if (!check_color(line->tokens[2]))
		return (ambient);
	ambient = light_new();
	if (!ambient)
		return (ambient);
	ambient->ambient = ft_atod(line->tokens[1]);
	ambient->intensity = get_color(line->tokens[2]);
	light_add(&(data->world.l_list), ambient);
	return (ambient);
}

t_light	*get_light(t_line *line, t_data *data)
{
	t_light	*light;

	light = NULL;
	if (!check_tuple(line->tokens[1]))
		return (light);
	if (!check_ratio(line->tokens[2]))
		return (light);
	if (line->tokens[3] && !check_color(line->tokens[3]))
		return (light);
	light = light_new();
	if (!light)
		return (light);
	light->position = get_point(line->tokens[1]);
	if (line->tokens[3])
		light->intensity = color_multiply(get_color(line->tokens[3]), \
			ft_atod(line->tokens[2]));
	else
		light->intensity = color_multiply(color(1, 1, 1, 1), \
			ft_atod(line->tokens[2]));
	light_add(&(data->world.l_list), light);
	return (light);
}

t_cam	*get_camera(t_line *line, t_data *data)
{
	t_matrix	transform;

	data->camera = NULL;
	if (!check_tuple(line->tokens[1]))
		return (data->camera);
	if (!check_normalized_vector(line->tokens[2]))
		return (data->camera);
	if (!check_double(line->tokens[3]) || \
		!check_range(ft_atod(line->tokens[3]), 0.0, 180.0))
		return (data->camera);
	transform = view_transform(get_point(line->tokens[1]), \
		get_vector(line->tokens[2]), get_upv(get_vector(line->tokens[2])));
	data->camera = camera(data->img.x, data->img.y, \
		ft_atod(line->tokens[3]) * (M_PI / 180.0));
	set_camera_transform(data->camera, transform);
	return (data->camera);
}
