/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:36:01 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 09:36:02 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		*generate_permutation_table(int size);
static double	gradient_lerp(t_perlin perlin);

t_perlin	perlin_init(void)
{
	t_perlin	perlin;

	perlin.permutation = generate_permutation_table(256);
	perlin.x = 0;
	perlin.y = 0;
	perlin.z = 0;
	perlin.pfade = vector(0, 0, 0);
	ft_bzero(perlin.hash, sizeof(int) * 6);
	return (perlin);
}

static int	*generate_permutation_table(int size)
{
	int	*p;
	int	i;
	int	j;
	int	tmp;

	p = malloc(sizeof(int) * size * 2);
	if (!p)
		return (NULL);
	i = -1;
	while (++i < size)
		p[i] = i;
	i = -1;
	while (++i < size)
	{
		j = abs(rand() % size);
		tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;
	}
	i--;
	while (++i < size * 2)
		p[i] = p[i - size];
	return (p);
}

void	perlin_destroy(t_perlin *perlin)
{
	if (perlin->permutation)
		free(perlin->permutation);
	return ;
}

double	perlin_noise(double x, double y, double z, t_material m)
{
	t_perlin	p;

	p = m.perlin;
	p.x = (int)floor(x) & 255;
	p.y = (int)floor(y) & 255;
	p.z = (int)floor(z) & 255;
	x -= floor(x);
	y -= floor(y);
	z -= floor(z);
	p.pfade.x = fade(x);
	p.pfade.y = fade(y);
	p.pfade.z = fade(z);
	p.hash[0] = p.permutation[p.x] + p.y;
	p.hash[1] = p.permutation[p.hash[0]] + p.z;
	p.hash[2] = p.permutation[p.hash[0] + 1] + p.z;
	p.hash[3] = p.permutation[p.x + 1] + p.y;
	p.hash[4] = p.permutation[p.hash[3]] + p.z;
	p.hash[5] = p.permutation[p.hash[3] + 1] + p.z;
	return (gradient_lerp(p));
}

static double	gradient_lerp(t_perlin p)
{
	double	x[2];
	double	y[2];
	double	res[2];

	x[0] = grad(p.permutation[p.hash[1]], p.x, p.y, p.z);
	x[1] = grad(p.permutation[p.hash[4]], p.x - 1, p.y, p.z);
	y[0] = lerp(p.pfade.x, x[0], x[1]);
	x[0] = grad(p.permutation[p.hash[2]], p.x, p.y - 1, p.z);
	x[1] = grad(p.permutation[p.hash[5]], p.x - 1, p.y - 1, p.z);
	y[1] = lerp(p.pfade.x, x[0], x[1]);
	res[0] = lerp(p.pfade.y, y[0], y[1]);
	x[0] = grad(p.permutation[p.hash[1] + 1], p.x, p.y, p.z - 1);
	x[1] = grad(p.permutation[p.hash[4] + 1], p.x - 1, p.y, p.z - 1);
	y[0] = lerp(p.pfade.x, x[0], x[1]);
	x[0] = grad(p.permutation[p.hash[2] + 1], p.x, p.y - 1, p.z - 1);
	x[1] = grad(p.permutation[p.hash[5] + 1], p.x - 1, p.y - 1, p.z - 1);
	y[1] = lerp(p.pfade.x, x[0], x[1]);
	res[1] = lerp(p.pfade.y, y[0], y[1]);
	return (lerp(p.pfade.z, res[0], res[1]));
}
