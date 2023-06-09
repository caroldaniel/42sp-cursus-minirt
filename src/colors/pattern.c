/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:38:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 23:43:29 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_pattern(t_object *obj, t_pattern pattern)
{
	if (obj->material.pattern.transform.data)
		matrix_destroy(&obj->material.pattern.transform);
	obj->material.pattern = pattern;
	return ;
}

t_pattern	solid_pattern(t_color a)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = a;
	pattern.type = SOLID;
	pattern.transform = identity(4);
	return (pattern);
}

t_pattern	stripe_pattern(t_color a, t_color b, t_matrix transform)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	pattern.type = STRIPE;
	pattern.transform = transform;
	return (pattern);
}

t_pattern	checker_pattern(t_color a, t_color b, t_matrix transform)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	pattern.type = CHECKER;
	pattern.transform = transform;
	return (pattern);
}
