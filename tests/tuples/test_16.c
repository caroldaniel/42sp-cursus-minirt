/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_16.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:10:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 14:25:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minirt.h"
#include "../../inc/tuples.h"
#include "../../lib/libft/libft.h"

/*
** Test for magnitude calculation
*/

int main(void)
{
	t_tuple *v;
	double	mag;

	printf("\nThis is a tuple:\n");
	v = vector(-1, -2, -3);
	print_tuple(*v);
	printf("\nNow, let's get its magnitude:\n");
	mag = magnitude(*v);
	if (mag < 0)
		printf("Can't get a point's magnitude!\n");
	else
		printf("magnitude of vector(%.1f, %.1f, %.1f) is %.1f\n", v->x, v->y, v->z, mag);
	free(v);
	return (0);
}
