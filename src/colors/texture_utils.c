/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:37:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/16 13:25:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double fade(double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

double lerp(double t, double a, double b)
{
	return (a + t * (b - a));
}

double grad(int hash, double x, double y, double z)
{
	int		h;
	double	u;
	double	v;
	double	result;

	h = hash & 15;
	if (h < 8)
	{
		u = x;
		v = y;	
	}
	else
	{
		u = y;
		v = z;
	}
	if (h & 1)
		result = -u;
	else
		result = u;
	if (h & 2)
		result -= v;
	else
		result += v;
	return (result);
}
