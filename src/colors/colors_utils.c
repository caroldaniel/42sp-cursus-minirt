/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:40:43 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 16:05:35 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_color(t_color color)
{
	printf("color.red = %.1f\n", color.r);
	printf("color.green = %.1f\n", color.g);
	printf("color.blue = %.1f\n", color.b);
	return ;
}
