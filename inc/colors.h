/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:44:51 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 16:08:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;


/*
** Init
*/
t_color *color(double r, double g, double b);

/*
** Operations
*/
t_color	*color_add(t_color a, t_color b);
t_color	*color_subtract(t_color a, t_color b);
t_color *color_multiply(t_color c, double scalar);
t_color *hadamard_product(t_color a, t_color b);

/*
** Utils
*/
void	print_color(t_color color);

#endif