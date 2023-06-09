/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:50:19 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 11:00:38 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_color(char *token)
{
	int		i;
	char	**rgb;

	i = 0;
	rgb = ft_split(token, ',');
	if (!rgb)
		return (false);
	while (rgb[i])
	{
		if (!check_int(rgb[i]) || !check_range(ft_atoi(rgb[i]), 0, 255))
		{
			ft_free_split(rgb);
			return (false);
		}
		i++;
	}
	ft_free_split(rgb);
	if (i != 3)
		return (false);
	return (true);
}

bool	check_tuple(char *token)
{
	int		i;
	char	**xyz;

	i = 0;
	xyz = ft_split(token, ',');
	if (!xyz)
		return (false);
	while (xyz[i])
	{
		if (!check_double(xyz[i]))
		{
			ft_free_split(xyz);
			return (false);
		}
		i++;
	}
	ft_free_split(xyz);
	if (i != 3)
		return (false);
	return (true);
}

bool	check_normalized_vector(char *token)
{
	int		i;
	double	mag;
	char	**xyz;

	i = 0;
	mag = 0.0;
	xyz = ft_split(token, ',');
	if (!xyz)
		return (false);
	while (xyz[i])
	{
		if (!check_double(xyz[i]))
		{
			ft_free_split(xyz);
			return (false);
		}
		i++;
	}
	if (i == 3)
		mag = magnitude(vector(ft_atod(xyz[0]), ft_atod(xyz[1]), \
			ft_atod(xyz[2])));
	ft_free_split(xyz);
	if (i != 3 || (i == 3 && !comp(mag, 1.0, 0.01)))
		return (false);
	return (true);
}

bool	check_material(char **tokens)
{
	if (!tokens[0])
		return (true);
	if (tokens[0] && (!tokens[1] || !tokens[2]))
		return (false);
	if (!check_ratio(tokens[0]))
		return (false);
	if (!check_ratio(tokens[1]))
		return (false);
	if (!comp_str(tokens[2], "solid") && !comp_str(tokens[2], "stripe") && \
		!comp_str(tokens[2], "checker"))
		return (false);
	return (true);
}
