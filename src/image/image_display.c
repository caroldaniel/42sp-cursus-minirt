/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:47:01 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/24 20:49:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	image_display(t_data *data)
{
	int	scroll_x;
	int	scroll_y;

	if (data->img.x > data->win.x)
		scroll_x = (data->img.x - data->img.x) / 2;
	else
		scroll_x = 0;
	if (data->img.y > data->win.y)
		scroll_y = (data->img.y - data->img.y) / 2;
	else
		scroll_y = 0;
	mlx_clear_window(data->mlx_ptr, data->win.ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win.ptr, data->img.ptr, \
		-scroll_x, -scroll_y);
	return ;
}
