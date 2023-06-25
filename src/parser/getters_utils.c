/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:22:01 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/24 22:33:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_color(char *token)
{
	t_color	c;
	char	**rgb;
	int		i;

	c = color(0, 0, 0, 1);
	rgb = ft_split(token, ',');
	if (!rgb)
		return (c);
	i = 0;
	while (rgb[i])
		i++;
	if (i == 3)
	{
		c.red = (double)(ft_atod(rgb[0]) / 256.0);
		c.green = (double)(ft_atod(rgb[1]) / 256.0);
		c.blue = (double)(ft_atod(rgb[2]) / 256.0);
		c.alpha = 1;
	}
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	return (c);
}

t_tuple	get_vector(char *token)
{
	t_tuple	v;
	char	**xyz;
	int		i;

	v = vector(0, 0, 0);
	xyz = ft_split(token, ',');
	if (!xyz)
		return (v);
	i = 0;
	while (xyz[i])
		i++;
	if (i == 3)
		v = vector(ft_atod(xyz[0]), ft_atod(xyz[1]), ft_atod(xyz[2]));
	i = 0;
	while (xyz[i])
		free(xyz[i++]);
	free(xyz);
	return (v);
}

t_tuple	get_upv(t_tuple forward)
{
	t_tuple	arbitrary_up;
	t_tuple	up;
	t_tuple	right;

	if (comp(forward.y, 1.0, EPSILON) || comp(forward.y, -1.0, EPSILON))
		arbitrary_up = vector(0, 0, -1);
	else
		arbitrary_up = vector(0, 1, 0);
	right = cross(forward, arbitrary_up);
	up = cross(normalize(right), forward);
	return (normalize(up));
}

t_tuple	get_point(char *token)
{
	t_tuple	p;
	char	**xyz;
	int		i;

	p = point(0, 0, 0);
	xyz = ft_split(token, ',');
	if (!xyz)
		return (p);
	i = 0;
	while (xyz[i])
		i++;
	if (i == 3)
		p = point(ft_atod(xyz[0]), ft_atod(xyz[1]), ft_atod(xyz[2]));
	i = 0;
	while (xyz[i])
		free(xyz[i++]);
	free(xyz);
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
