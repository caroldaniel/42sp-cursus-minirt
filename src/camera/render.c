/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:06:56 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 20:30:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_data *data)
{
	t_ray	*ray;
	t_color	c;
	int		y;
	int		x;

	y = -1;
	while (++y < data->camera.vsize)
	{
		x = -1;
		while (++x < data->camera.hsize)
		{
			ray = ray_for_pixel(data->camera, x, y);
			c = color_at(data->world, ray);
			put_pixel(data->img, x, y, c);
			ray_destroy(&ray);
			update_progress_bar((x + (y * data->camera.hsize)), \
				data->camera.vsize * data->camera.hsize);
		}
	}
	update_progress_bar((x + (y * data->camera.hsize)), \
		data->camera.vsize * data->camera.hsize);
	printf("\n%sRendering Complete%s\n", ESC_BOLD_GREEN, ESC_RESET_COLOR);
}
