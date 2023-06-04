/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:44:51 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 19:13:00 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "minirt.h"
# include "tuples.h"

/*
** Color type definition
*/
typedef struct s_color
{
	double	alpha;
	double	red;
	double	green;
	double	blue;
}	t_color;

/*
** Image type definition
*/
typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		y;
	int		x;
	t_color	**grid;
}	t_img;

/*
** Pattern types
*/
enum e_pattern {
	SOLID,
	STRIPE
};

/*
** Pattern type definition
*/
typedef struct s_pattern
{
	t_color	a;
	t_color b;
	int		type;
}	t_pattern;

/*
** Init
*/
t_color	color(double r, double g, double b, double a);

/*
** Operations
*/
t_color	color_add(t_color a, t_color b);
t_color	color_subtract(t_color a, t_color b);
t_color	color_multiply(t_color c, double scalar);
t_color	hadamard_product(t_color a, t_color b);

/*
** Pattern
*/
t_pattern	solid_pattern(t_color a);
t_pattern	stripe_pattern(t_color a, t_color b);
t_color		pattern_at(t_pattern pattern, t_tuple point);

/*
** Utils
*/
void	print_color(t_color color);
int		combine(t_color c, t_img img);

#endif