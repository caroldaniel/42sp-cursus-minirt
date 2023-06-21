/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:22:01 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/20 20:56:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_color(char *token)
{
	t_color	color;
	char	**rgb;
	int		i;

	rgb = ft_split(token, ',');
	if (!rgb)
		return (color(0, 0, 0, 1));
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		return (color(0, 0, 0, 1));
	color.r = (double)(ft_atod(rgb[0]) / 256.0);
	color.g = (double)(ft_atod(rgb[1]) / 256.0);
	color.b = (double)(ft_atod(rgb[2]) / 256.0);
	color.a = 1;
	return (color);
}

t_tuple get_vector(char *token)
{
	t_tuple	vector;
	char	**xyz;
	int		i;

	xyz = ft_split(token, ',');
	if (!xyz)
		return (vector(0, 0, 0));
	i = 0;
	while (xyz[i])
		i++;
	if (i != 3)
		return (vector(0, 0, 0));
	vector = vector(ft_atod(xyz[0]), ft_atod(xyz[1]), ft_atod(xyz[2]));
	return (vector);
}

t_tuple get_point(char *token)
{
	t_tuple	point;
	char	**xyz;
	int		i;

	xyz = ft_split(token, ',');
	if (!xyz)
		return (point(0, 0, 0));
	i = 0;
	while (xyz[i])
		i++;
	if (i != 3)
		return (point(0, 0, 0));
	point = point(ft_atod(xyz[0]), ft_atod(xyz[1]), ft_atod(xyz[2]));
	return (point);
}

t_pattern	get_pattern(char *pattern, char *color_str)
{
	if (comp_str(pattern, "solid"))
		return (solid_pattern(get_color(color_str)));
	if (comp_str(pattern, "stripe"))
		return (stripe_pattern(get_color(color_str), color(1, 1, 1, 1)));
	if (comp_str(pattern, "checker"))
		return (checker_pattern(get_color(color_str), color(1, 1, 1, 1)),\
			scaling(0.5, 0.5, 0.5));
	return (solid_pattern(get_color(color_str)));
}
