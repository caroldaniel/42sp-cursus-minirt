/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:37:44 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 17:06:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	rotation_x(double radians)
{
	t_matrix	rot_x;
	double		cos_ang;
	double		sin_ang;

	rot_x = identity(4);
	if (!rot_x.size)
		return (rot_x);
	cos_ang = cos(radians);
	sin_ang = sin(radians);
	rot_x.data[1][1] = cos_ang;
	rot_x.data[1][2] = -sin_ang;
	rot_x.data[2][1] = sin_ang;
	rot_x.data[2][2] = cos_ang;
	return (rot_x);
}

t_matrix	rotation_y(double radians)
{
	t_matrix	rot_y;
	double		cos_ang;
	double		sin_ang;

	rot_y = identity(4);
	if (!rot_y.size)
		return (rot_y);
	cos_ang = cos(radians);
	sin_ang = sin(radians);
	rot_y.data[0][0] = cos_ang;
	rot_y.data[0][2] = sin_ang;
	rot_y.data[2][0] = -sin_ang;
	rot_y.data[2][2] = cos_ang;
	return (rot_y);
}

t_matrix	rotation_z(double radians)
{
	t_matrix	rot_z;
	double		cos_ang;
	double		sin_ang;

	rot_z = identity(4);
	if (!rot_z.size)
		return (rot_z);
	cos_ang = cos(radians);
	sin_ang = sin(radians);
	rot_z.data[0][0] = cos_ang;
	rot_z.data[0][1] = -sin_ang;
	rot_z.data[1][0] = sin_ang;
	rot_z.data[1][1] = cos_ang;
	return (rot_z);
}
