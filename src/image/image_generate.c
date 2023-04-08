/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_generate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:52:14 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 21:16:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	image_generate(t_img *img)
{
	int	x;
	int	y;

	x = -1;
	while (++x < IMG_X)
	{
		y = -1;
		while (++y < IMG_Y)
			img->data[x * IMG_Y + y] = combine(*img->grid[x][y], *img);
	}
}
