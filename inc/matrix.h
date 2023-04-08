/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:11:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/08 00:26:14 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef float	t_row[4];
typedef float	t_matrix[4][4];

t_row		row_init(double a, double b, double c, double d);
t_matrix	matrix_init(t_row a, t_row b, t_row c, t_row d);

#endif