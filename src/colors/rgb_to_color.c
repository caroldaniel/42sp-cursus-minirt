/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:52:28 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/18 00:01:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	rgb_to_color(int red, int green, int blue)
{
	t_color	color;

	color.r = fmin(fmax((double)(red / 255.0), 0.0), 1.0);
	color.g = fmin(fmax((double)(green / 255.0), 0.0), 1.0);
	color.b = fmin(fmax((double)(blue / 255.0), 0.0), 1.0);
	return (color);
}
