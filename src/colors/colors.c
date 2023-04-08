/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:46:31 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/08 14:16:38 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color(double r, double g, double b, double a)
{
	t_color	color;

	color.red = r;
	color.green = g;
	color.blue = b;
	color.alpha = a;
	return (color);
}
