/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:38:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 20:37:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	solid_pattern(t_color a)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = a;
	pattern.type = SOLID;
	return (pattern);
}

t_pattern	stripe_pattern(t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	pattern.type = STRIPE;
	return (pattern);
}

t_color	pattern_at(t_pattern pattern, t_tuple point)
{
	double mod;

	if (pattern.type == SOLID)
		return (pattern.a);
	if (pattern.type == STRIPE)
	{
		mod = fmod(point.x, 2.0);
		if (mod < 0)
			mod *= -1.0;
		if (mod < 1.0)
			return (pattern.a);
		return (pattern.b);
	}
	return (color(0, 0, 0, 1));
}
