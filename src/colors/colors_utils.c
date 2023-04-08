/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:40:43 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 19:51:20 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	four_channels(t_color c, t_img img);
static int	three_channels(t_color c, t_img img);

void	print_color(t_color color)
{
	printf("color.red = %.1f\n", color.red);
	printf("color.green = %.1f\n", color.green);
	printf("color.blue = %.1f\n", color.blue);
	printf("color.alpha = %.1f\n", color.alpha);
	return ;
}

int	combine(t_color c, t_img img)
{
	if (img.bits_per_pixel == 32)
		return (four_channels(c, img));
	else if (img.bits_per_pixel == 24)
		return (three_channels(c, img));
	return (-1);
}

static int	four_channels(t_color c, t_img img)
{
	int	c_red;
	int	c_green;
	int	c_blue;
	int	c_alpha;

	c_red = (int)(fmin(fmax(c.red, 0.0), 1.0) * 255.0);
	c_green = (int)(fmin(fmax(c.green, 0.0), 1.0) * 255.0);
	c_blue = (int)(fmin(fmax(c.blue, 0.0), 1.0) * 255.0);
	c_alpha = (int)(fmin(fmax(c.alpha, 0.0), 1.0) * 255.0);
	if (img.endian == BIG_ENDIAN)
		return ((c_alpha << 24) | (c_red << 16) | (c_green << 8) | c_blue);
	return (c_blue | (c_green << 8) | (c_red << 16) | (c_alpha << 24));
}

static int	three_channels(t_color c, t_img img)
{
	int	c_red;
	int	c_green;
	int	c_blue;

	c_red = (int)(fmin(fmax(c.red, 0.0), 1.0) * 255.0);
	c_green = (int)(fmin(fmax(c.green, 0.0), 1.0) * 255.0);
	c_blue = (int)(fmin(fmax(c.blue, 0.0), 1.0) * 255.0);
	if (img.endian == BIG_ENDIAN)
		return ((c_red << 16) | (c_green << 8) | c_blue);
	return (c_blue | (c_green << 8) | (c_red << 16));
}
