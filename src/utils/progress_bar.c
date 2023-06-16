/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:28:43 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/15 22:28:15 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_progress_bar(int current, int total)
{
	int	progress;
	int	bars;
	int	i;

	progress = (current * 100) / total;
	bars = progress / 2;
	printf("\r[");
	i = -1;
	while (++i < 50)
	{
		if (i < bars)
			printf("=");
		else
			printf(" ");
	}
	if (progress >= 100)
		printf("] %s100%%%s", ESC_BOLD_GREEN, ESC_RESET_COLOR);
	else
		printf("] %s%3d%%%s", ESC_BOLD_ORANGE, progress, ESC_RESET_COLOR);
}
