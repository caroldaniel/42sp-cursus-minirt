/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:25:24 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/04 21:33:23 by cado-car         ###   ########.fr       */
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
	t_tuple *sum;

	a = tuple(3, -2, 5, 0);
	printf("\nThis is tuple A:\n");
	print_tuple(*a);
	b = tuple(-2, 3, 1, 0);
	printf("\nThis is tuple B:\n");
	print_tuple(*b);
	printf("\nAdding them together...\n");
	sum = tuple_add(*a, *b);
	if (!sum)
		printf("Can't add two points!");
	else
	{
		print_tuple(*sum);
		free(sum);
	}
	free(a);
	free(b);
	return (0);
}
