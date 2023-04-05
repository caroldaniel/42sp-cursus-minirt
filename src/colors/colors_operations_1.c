/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:58:56 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 16:08:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	*color_add(t_color a, t_color b)
{
	t_color	*sum;

	sum = color(a.r + b.r, a.g + b.g, a.b + b.b);
	return (sum);
}

t_color	*color_subtract(t_color a, t_color b)
{
	t_color	*sub;

	sub = color(a.r - b.r, a.g - b.g, a.b - b.b);
	return (sub);
}

t_color *color_multiply(t_color c, double scalar)
{
	t_color *res;
	
	res = color(c.r * scalar, c.g * scalar, c.b * scalar);
	return (res);
}

t_color *hadamard_product(t_color a, t_color b)
{
	t_color *res;
	
	res = color(a.r * b.r, a.g * b.g, a.b * b.b);
	return (res);
}
