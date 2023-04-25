/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:35:51 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/24 20:36:12 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel(t_img img, int x, int y, t_color color)
{
	if (x < 0 || y < 0)
		return ;
	if (x >= img.x || y >= img.y)
		return ;
	img.grid[y][x] = color;
}
