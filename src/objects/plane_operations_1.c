/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:50:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/05/29 21:33:47 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	intersect_plane(t_object *pl, t_ray *ray)
{
	t_ray		*ray_t;
	double		t;

	ray_t = transform(ray, matrix_inverse(pl->transform));
	if (abs_float(ray_t->direction.y) < 0.001)
		return ;
	t = -ray->origin.y / ray->direction.y
	
}

t_tuple	normal_at_plane(t_object *pl)
{
	t_matrix	inv;
	t_matrix	trs;
	t_tuple		o_nml;
	t_tuple		nml;

	inv = matrix_inverse(pl->transform);
	o_nml = vector(0, 1, 0);
	trs = matrix_transpose(inv);
	nml = matrix_tuple_multiply(trs, o_nml);
	nml.w = 0;
	matrix_destroy(&inv);
	matrix_destroy(&trs);
	return (normalize(nml));
}
