/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:33:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/18 16:36:53 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	comp_str(const char *str1, const char *str2)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	while (str1[i] && str2[i])
	{
		c1 = ft_tolower(str1[i]);
		c2 = ft_tolower(str2[i]);
		if (c1 != c2)
			return (false);
		i++;
	}
	if (str1[i] || str2[i])
		return (false);
	return (true);
}
