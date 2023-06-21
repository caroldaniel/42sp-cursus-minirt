/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:22:01 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 00:05:25 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_color(char *token)
{
	t_color	c;
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
	c.red = (double)(ft_atod(rgb[0]) / 256.0);
	c.green = (double)(ft_atod(rgb[1]) / 256.0);
	c.blue = (double)(ft_atod(rgb[2]) / 256.0);
	c.alpha = 1;
	return (c);
}

t_tuple get_vector(char *token)
{
	t_tuple	v;
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
	v = vector(ft_atod(xyz[0]), ft_atod(xyz[1]), ft_atod(xyz[2]));
	return (v);
}

t_tuple get_point(char *token)
{
	t_tuple	p;
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
	p = point(ft_atod(xyz[0]), ft_atod(xyz[1]), ft_atod(xyz[2]));
	return (p);
}

t_pattern	get_pattern(char *pattern, char *color_str)
{
	if (comp_str(pattern, "solid"))
		return (solid_pattern(get_color(color_str)));
	if (comp_str(pattern, "stripe"))
		return (stripe_pattern(get_color(color_str), color(1, 1, 1, 1), \
			identity(4)));
	if (comp_str(pattern, "checker"))
		return (checker_pattern(get_color(color_str), color(1, 1, 1, 1), \
			identity(4)));
	return (solid_pattern(get_color(color_str)));
}
