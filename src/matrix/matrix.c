/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:15:34 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/08 00:25:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_row	row_init(double a, double b, double c, double d)
{
	t_row	row;

	row[0] = a;
	row[1] = b;
	row[2] = c;
	row[3] = d;
	return (row);
}

t_matrix	matrix_init(t_row a, t_row b, t_row c, t_row d)
{
	t_matrix	matrix;

	matrix[0] = a;
	matrix[1] = b;
	matrix[2] = c;
	matrix[3] = d;
	return (matrix);
}
