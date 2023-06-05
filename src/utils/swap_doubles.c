/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_doubles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:57:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/05 15:58:33 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	swap_doubles(double *a, double *b)
{
	double temp;

	temp = *b;
	*b = *a;
	*a = temp;
	return ;
}
