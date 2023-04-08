/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:28:47 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 21:28:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	*color_add(t_color a, t_color b)
{
	t_color	*sum;

	sum = color(a.red + b.red, a.green + b.green, a.blue + b.blue, \
		a.alpha + b.alpha);
	return (sum);
}

t_color	*color_subtract(t_color a, t_color b)
{
	t_color	*sub;

	sub = color(a.red - b.red, a.green - b.green, a.blue - b.blue, \
		a.alpha - b.alpha);
	return (sub);
}

t_color	*color_multiply(t_color c, double scalar)
{
	t_color	*res;

	res = color(c.red * scalar, c.green * scalar, c.blue * scalar, \
		c.alpha * scalar);
	return (res);
}

t_color	*hadamard_product(t_color a, t_color b)
{
	t_color	*res;

	res = color(a.red * b.red, a.green * b.green, a.blue * b.blue, \
		a.alpha * b.alpha);
	return (res);
}
