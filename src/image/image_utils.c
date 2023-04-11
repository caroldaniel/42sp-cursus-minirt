/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:03:27 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 21:03:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_line(t_data *data, t_coord a, t_coord b, t_color c)
{
	int		dx;
	int		dy;
	float	slope;
	int		y_intercept;
	int		i;

	dx = b.x - a.x;
	dy = b.y - a.y;
	slope = (float)(dy / dx);
	y_intercept = a.y - slope * a.x;
	i = a.x - 1;
	while (++i <= b.x)
		put_pixel(data->img, i, slope * i + y_intercept, c);
}
