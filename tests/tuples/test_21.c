/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_21.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:10:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 15:19:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minirt.h"
#include "../../inc/tuples.h"
#include "../../lib/libft/libft.h"

/*
** Test for cross product
*/

int main(void)
{
	t_tuple *a;
	t_tuple *b;
	t_tuple *pdt;

	printf("\nThis is a tuple:\n");
	a = vector(1, 2, 3);
	print_tuple(*a);
	printf("\nThis is a tuple:\n");
	b = vector(2, 3, 4);
	print_tuple(*b);
	printf("\nNow, let's get its cross product:\n");
	pdt = cross(*a, *b);
	printf("cross(b, a) = (%.1f, %.1f, %.1f)\n", pdt->x, pdt->y, pdt->z);
		free(pdt);
	pdt = cross(*b, *a);
	printf("cross(b, a) = (%.1f, %.1f, %.1f)\n", pdt->x, pdt->y, pdt->z);
	free(pdt);
	free(a);
	free(b);
	return (0);
}
