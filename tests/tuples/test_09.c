/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_09.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:25:24 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/04 21:45:47 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minirt.h"
#include "../../inc/tuples.h"
#include "../../lib/libft/libft.h"

/*
** Test for vector creation
*/

int main(void)
{
	t_tuple *a;
	t_tuple *b;
	t_tuple *sub;

	a = vector(3, 2, 1);
	printf("\nThis is tuple A:\n");
	print_tuple(*a);
	b = point(3, 2, 1);
	printf("\nThis is tuple B:\n");
	print_tuple(*b);
	printf("\nSubtracting B from A...\n");
	sub = tuple_subtract(*a, *b);
	if (!sub)
		printf("Can't subtract a point from a vector!\n");
	else
	{
		print_tuple(*sub);
		free(sub);
	}
	free(a);
	free(b);
	return (0);
}
