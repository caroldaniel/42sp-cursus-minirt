/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:37:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/15 21:37:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	*generate_permutation_table(int size)
{
	int	*p;
	int	i;
	int j;
	int tmp;
	
	p = malloc(sizeof(int) * (size + size));
	if (!p)
		return (NULL);
	i = -1;
	while (++i < size)
		p[i] = i;
	i = -1;
	while (++i < size)
	{
		j = fmod(random_double(), (double)size);
		tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;
	}
	while (++i < (size + size))
		p[i + size] = p[i];
	return (p);
}

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

	h = hash & 15;
	if (h < 8) 
		u = x;
	else
		u = y;
	if (h < 4) 
		v = y;
	else
	{
		if (h == 12 || h == 14) 
			v = x;
		else
			v = z;
	}
	if ((h & 1) != 0)
		u *= -1;
	if ((h & 2) != 0)
		v *= -1;
	return (u + v);
}
