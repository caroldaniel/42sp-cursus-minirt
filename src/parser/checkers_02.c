/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:39:14 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/20 21:22:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_element_properties_count(t_line *line)
{
	int	i;

	i = 0;
	while (line->tokens[i])
		i++;
	if (comp_str(identifier, "A") && i == 3)
		return (true);
	if (comp_str(identifier, "C") && i == 4)
		return (true);
	if (comp_str(identifier, "L") && i == 4)
		return (true);
	if (comp_str(identifier, "sp") && (i == 4 || i == 7))
		return (true);
	if (comp_str(identifier, "pl") && (i == 4 || i == 7))
		return (true);
	if (comp_str(identifier, "cy") && (i == 6 || i == 9))
		return (true);
	if (comp_str(identifier, "cn") && (i == 6 || i == 9))
		return (true);
	return (false);
}

bool	check_range(double value, double min, double max)
{
	if (value < min || value > max)
		return (false);
	return (true);
}

bool	check_ratio(char *token)
{
	double	ratio;

	if (!check_double(token))
		return (false);
	ratio = ft_atod(token);
	if (!check_range(ratio, 0.0, 1.0))
		return (false);
	return (true);
}

bool	check_int(char *token)
{
	int	i;

	i = 0;
	while (token[i] == '-' || token[i] == '+')
		i++;
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_double(char *token)
{
	int		i;
	bool	has_dot;

	i = 0;
	has_dot = false;
	while (token[i] == '-' || token[i] == '+')
		i++;
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
		{
			if (token[i] == '.' && has_dot == false)
				has_dot = true;
			else
				return (false);
		}
		i++;
	}
	return (true);
}
