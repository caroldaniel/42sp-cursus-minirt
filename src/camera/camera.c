/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:09:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/24 09:49:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	calculate_ratios(t_cam *cam);

t_cam	camera(int hsize, int vsize, int field_of_view)
{
	t_cam	cam;

	cam.hsize = hsize;
	cam.vsize = vsize;
	cam.field_of_view = field_of_view;
	cam.transform = identity(4);
	calculate_ratios(&cam);
	return (cam);
}

static void	calculate_ratios(t_cam *cam)
{
	double	half_view;
	double	aspect;
	
	half_view = tan(cam->field_of_view / 2);
	aspect = cam->hsize / cam->vsize;
	if (aspect >= 1)
	{
		cam->half_width = half_view;
		cam->half_height = half_view / aspect;
	}
	else
	{
		cam->half_width = half_view * aspect;
		cam->half_height = half_view;
	}
	cam->pixel_size = (cam->half_width * 2) / cam->hsize;
	return ;
}