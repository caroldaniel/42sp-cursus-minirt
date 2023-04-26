/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuplest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:49:25 by fmoreira          #+#    #+#             */
/*   Updated: 2023/04/26 22:49:42 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLEST_H
# define TUPLEST_H

# include "minirt.h"

typedef struct s_proj
{
	t_tuple	p_posi;
	t_tuple v_velo;
}	t_proj;

typedef struct	s_envi
{
	t_tuple	v_grav;
	t_tuple	v_wind;
}	t_envi;



#endif