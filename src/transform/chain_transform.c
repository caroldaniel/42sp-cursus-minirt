/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:56:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/24 13:19:14 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	calculate(int nb, va_list args);

t_matrix	chain_transform(int nb, ...)
{
	va_list		args;
	t_matrix	result;

	va_start(args, nb);
	result = calculate(nb, args);	
	va_end(args);
	return (result);
}

static t_matrix	calculate(int nb, va_list args)
{
	t_matrix	curr;

	curr = va_arg(args, t_matrix);
	if (nb == 0)
		return (curr);
	return (matrix_multiply(curr, calculate(--nb, args)));
}
