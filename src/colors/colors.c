/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:46:31 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 16:05:29 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color *color(double r, double g, double b)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}
