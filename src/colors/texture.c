/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:45:34 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/15 20:05:00 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	perlin_noise(t_tuple point);
static void 	get_perlin_tuples(t_perlin *p);
static void		get_perlin_gradients(t_perlin *p);

t_tuple	perturb_normal(t_tuple normalv, t_tuple point, double bumpiness)
{
	t_tuple	perturbation;

	bumpiness = fmax(0.0, fmin(1.0, bumpiness));
	if (comp(bumpiness, 0.0, EPSILON))
		return (normalv);
	perturbation.x = perlin_noise(point) * bumpiness;
	perturbation.y = perlin_noise(point) * bumpiness;
	perturbation.z = perlin_noise(point) * bumpiness;
	return (normalize(tuple_add(normalv, perturbation)));
}

static double	perlin_noise(t_tuple point)
{
	t_perlin perlin;

	perlin.p = point;
	get_perlin_tuples(&perlin);
	perlin.ptable = generate_permutation_table(256);
	if (!perlin.ptable)
		return (0);
	get_perlin_gradients(&perlin);
	perlin.lerp[0] = lerp(perlin.g[0], perlin.g[1], perlin.pfade.x);
	perlin.lerp[1] = lerp(perlin.g[2], perlin.g[3], perlin.pfade.x);
	perlin.lerp[2] = lerp(perlin.g[4], perlin.g[5], perlin.pfade.x);
	perlin.lerp[3] = lerp(perlin.g[6], perlin.g[7], perlin.pfade.x);
	perlin.lerp[4] = lerp(perlin.lerp[0], perlin.lerp[1], perlin.pfade.y);
	perlin.lerp[5] = lerp(perlin.lerp[2], perlin.lerp[3], perlin.pfade.y);
	perlin.lerp[6] = lerp(perlin.lerp[4], perlin.lerp[5], perlin.pfade.z);
	return (perlin.lerp[6]);
}

static void get_perlin_tuples(t_perlin *p)
{
	p->pfloor.x = floor(p->p.x);
	p->pfloor.y = floor(p->p.y);
	p->pfloor.z = floor(p->p.z);
	p->pdiff.x = p->p.x - p->pfloor.x;
	p->pdiff.y = p->p.y - p->pfloor.y;
	p->pdiff.z = p->p.z - p->pfloor.z;
	p->pfade.x = fade(p->pdiff.x);
	p->pfade.y = fade(p->pdiff.y);
	p->pfade.z = fade(p->pdiff.z);
}

static void	get_perlin_gradients(t_perlin *p)
{
	p->t[A] = p->ptable[(int)p->pfloor.x] + (int)p->pfloor.y;
	p->t[AA] = p->ptable[p->t[A]] + (int)p->pfloor.z;
	p->t[AB] =	p->ptable[p->t[A] + 1] + (int)p->pfloor.z;
	p->t[B] = p->ptable[(int)p->pfloor.x + 1] + (int)p->pfloor.y;
	p->t[BA] = p->ptable[p->t[B]] + (int)p->pfloor.z;
	p->t[BB] = p->ptable[p->t[B] + 1] + (int)p->pfloor.z;
	p->g[0] = grad(p->t[AA], p->pdiff.x, p->pdiff.y, p->pdiff.z);
	p->g[1] = grad(p->t[BA], p->pdiff.x - 1, p->pdiff.y, p->pdiff.z);
	p->g[2] = grad(p->t[AB], p->pdiff.x, p->pdiff.y - 1, p->pdiff.z);
	p->g[3] = grad(p->t[BB], p->pdiff.x - 1, p->pdiff.y - 1, p->pdiff.z);
	p->g[4] = grad(p->t[AA + 1], p->pdiff.x, p->pdiff.y, p->pdiff.z - 1);
	p->g[5] = grad(p->t[BA + 1], p->pdiff.x - 1, p->pdiff.y, p->pdiff.z - 1);
	p->g[6] = grad(p->t[AB + 1], p->pdiff.x, p->pdiff.y - 1, p->pdiff.z - 1);
	p->g[7] = grad(p->t[BB + 1], p->pdiff.x - 1, p->pdiff.y - 1, p->pdiff.z \
		- 1);
}