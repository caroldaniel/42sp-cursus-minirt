/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:45:34 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/16 00:43:59 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	perlin_noise(double x, double y, double z);
static void 	get_perlin_tuples(t_perlin *p);
static void		get_perlin_gradients(t_perlin *p);

t_tuple	perturb_normal(t_tuple nmlv, t_tuple p, double scale, double bump)
{
	t_tuple	scaled_p;
	t_tuple	perturbation;

	bump = fmax(0.0, fmin(1.0, bump));
	if (comp(bump, 0.0, EPSILON))
		return (nmlv);
	scale = fmax(0.0, scale);
	scaled_p = tuple_multiply(p, scale);
	perturbation = vector( \
		perlin_noise(scaled_p.x, scaled_p.y, scaled_p.z) * bump, \
 		perlin_noise(scaled_p.y, scaled_p.z, scaled_p.x) * bump, \
		perlin_noise(scaled_p.z, scaled_p.x, scaled_p.y) * bump);
	return (normalize(tuple_add(nmlv, perturbation)));
}

static double	perlin_noise(double x, double y, double z)
{
	t_perlin perlin;

	perlin.p.x = x;
	perlin.p.y = y;
	perlin.p.z = z;
	perlin.p.w = 0;
	get_perlin_tuples(&perlin);
	perlin.prm = generate_permutation_table(256);
	if (!perlin.prm)
		return (0);
	get_perlin_gradients(&perlin);
	free(perlin.prm);
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
	p->pfloor.x = (int)floor(p->p.x) & 255;
	p->pfloor.y = (int)floor(p->p.y) & 255;
	p->pfloor.z = (int)floor(p->p.z) & 255;
	p->df.x = p->p.x - p->pfloor.x;
	p->df.y = p->p.y - p->pfloor.y;
	p->df.z = p->p.z - p->pfloor.z;
	p->pfade.x = fade(p->df.x);
	p->pfade.y = fade(p->df.y);
	p->pfade.z = fade(p->df.z);
}

static void	get_perlin_gradients(t_perlin *p)
{
	p->t[0] = p->prm[(int)p->pfloor.x] + (int)p->pfloor.y;
	p->t[1] = p->prm[p->t[0]] + (int)p->pfloor.z;
	p->t[2] = p->prm[p->t[0] + 1] + (int)p->pfloor.z;
	p->t[3] = p->prm[(int)p->pfloor.x + 1] + (int)p->pfloor.y;
	p->t[4] = p->prm[p->t[3]] + (int)p->pfloor.z;
	p->t[5] = p->prm[p->t[3] + 1] + (int)p->pfloor.z;
	p->g[0] = grad(p->prm[p->t[1]], p->df.x, p->df.y, p->df.z);
	p->g[1] = grad(p->prm[p->t[4]], p->df.x - 1, p->df.y, p->df.z);
	p->g[2] = grad(p->prm[p->t[2]], p->df.x, p->df.y - 1, p->df.z);
	p->g[3] = grad(p->prm[p->t[5]], p->df.x - 1, p->df.y - 1, p->df.z);
	p->g[4] = grad(p->prm[p->t[1] + 1], p->df.x, p->df.y, p->df.z - 1);
	p->g[5] = grad(p->prm[p->t[4] + 1], p->df.x - 1, p->df.y, p->df.z - 1);
	p->g[6] = grad(p->prm[p->t[2] + 1], p->df.x, p->df.y - 1, p->df.z - 1);
	p->g[7] = grad(p->prm[p->t[5] + 1], p->df.x - 1, p->df.y - 1, p->df.z - 1);
}