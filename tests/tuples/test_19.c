/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_19.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:10:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 15:08:27 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minirt.h"
#include "../../inc/tuples.h"
#include "../../lib/libft/libft.h"

/*
** Test for normatization
*/

int main(void)
{
	t_tuple *v;
	t_tuple	*norm;

	printf("\nThis is a tuple:\n");
	v = vector(1, 2, 3);
	print_tuple(*v);
	printf("\nNow, let's normalize it:\n");
	norm = normalize(*v);
	if (!norm)
		printf("Can't normalize a point!\n");
	else
	{
		printf("vector(%.1f, %.1f, %.1f) normalized: (%.1f, %.1f, %.1f)\n", \
			v->x, v->y, v->z, norm->x, norm->y, norm->z);
		printf("magnitude of vector(%.1f, %.1f, %.1f): %.1f\n", \
			norm->x, norm->y, norm->z, magnitude(*norm));
		free(norm);
	}
	free(v);
	return (0);
}
