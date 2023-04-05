/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_20.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:10:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 15:14:17 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minirt.h"
#include "../../inc/tuples.h"
#include "../../lib/libft/libft.h"

/*
** Test for dot product
*/

int main(void)
{
	t_tuple *a;
	t_tuple *b;
	double	pdt;

	printf("\nThis is a tuple:\n");
	a = vector(1, 2, 3);
	print_tuple(*a);
	printf("\nThis is a tuple:\n");
	b = vector(2, 3, 4);
	print_tuple(*b);
	printf("\nNow, let's get its dot product:\n");
	pdt = dot(*a, *b);
	if (pdt < 0)
		printf("Can't get a dot product of a point!\n");
	else
		printf("dot(a, b) = %.1f\n", pdt);
	free(a);
	free(b);
	return (0);
}
