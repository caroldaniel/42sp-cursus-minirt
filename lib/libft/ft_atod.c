/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:51:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/18 15:30:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	-
*	DESCRIPTION
*	The atod() function converts the initial portion of the string pointed to by 
*	str to double representation.
*	PARAMETERS
*	#1. The string to convert to integer.
*	RETURN VALUES
*	The atod() function returns its converted double representation.
*/

#include "libft.h"

static int	is_valid(char *str);

double	ft_atod(char *str)
{
	double	result;
	int		i;

	result = 0.0;
	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_strlen(&str[i]) > 12 || !is_valid(&str[i]))
		return (0.0);
	result = (double)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
	{
		str++;
		result += ((double)ft_atoi(str) / pow(10, ft_strlen(str)));
	}
	return (result);
}

static int	is_valid(char *str)
{
	int	has_dot;
	int	i;

	has_dot = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);	
			has_dot = 1;
		}
	}
	return (1);
}