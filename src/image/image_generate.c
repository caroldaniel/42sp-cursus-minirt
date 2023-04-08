/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_generate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:52:14 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/08 14:23:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	image_generate(t_img *img)
{
	int	x;
	int	y;

	y = -1;
	while (++y < IMG_Y)
	{
		x = -1;
		while (++x < IMG_X)
			img->data[y * IMG_X + x] = combine(img->grid[y][x], *img);
	}
}
