/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:21:05 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/26 18:43:29 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_exit_message(int exit_code);
static void	print_parser_message(int exit_code);
static void	grid_destroy(t_img *img, int height);

int	data_destroy(t_data *data, int exit_code)
{
	print_exit_message(exit_code);
	if (data->fd > 2)
		close(data->fd);
	if (exit_code == ERR_WRNGARG)
		return (exit_code);
	line_list_destroy(&data->line_list);
	world_destroy(&data->world);
	camera_destroy(&data->camera);
	if (data->mlx_ptr && exit_code != ERR_MLXINIT)
	{
		grid_destroy(&data->img, data->img.y);
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
		mlx_destroy_window(data->mlx_ptr, data->win.ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	return (exit_code);
}

static void	print_exit_message(int exit_code)
{
	if (exit_code)
		printf("%sError%s\n", ESC_BOLD_RED, ESC_RESET_COLOR);
	else
		printf("\n%sClosing MiniRT%s\n", ESC_BOLD_ORANGE, ESC_RESET_COLOR);
	if (exit_code == ERR_WRNGARG)
		printf("Wrong usage. Use: `./minirt <path_to_rt_file>`\n");
	if (exit_code == ERR_MEMALOC)
		printf("Memory allocation failed.\n");
	if (exit_code == ERR_MLXINIT)
		printf("Unable to initialize MinilibX. Please verify dependencies.\n");
	if (exit_code == ERR_WININIT)
		printf("Unable to initialize MinilibX Window.");
	if (exit_code == ERR_IMGINIT)
		printf("Unable to initialize MinilibX Image.");
	if (exit_code == ERR_EXTINVL)
		printf("Invalid extention. Please choose a `.rt` file to continue.\n");
	if (exit_code == ERR_FDERROR)
		perror("Failed to open file");
	if (exit_code == ERR_INVELEM)
		printf("Parser error. Invalid element.\n");
	if (exit_code == ERR_SCNCNTR)
		printf("Parser error. Invalid number of elements to render.\n");
	if (exit_code >= ERR_PARSERA)
		print_parser_message(exit_code);
	return ;
}

static void	print_parser_message(int exit_code)
{
	if (exit_code == ERR_PARSERA)
		printf("Parser error. Invalid ratio aspect.\n");
	if (exit_code == ERR_PARSEAM)
		printf("Parser error. Invalid ambient light.\n");
	if (exit_code == ERR_PARSECA)
		printf("Parser error. Invalid camera.\n");
	if (exit_code == ERR_PARSELI)
		printf("Parser error. Invalid light.\n");
	if (exit_code == ERR_PARSESP)
		printf("Parser error. Invalid sphere.\n");
	if (exit_code == ERR_PARSEPL)
		printf("Parser error. Invalid plane.\n");
	if (exit_code == ERR_PARSECY)
		printf("Parser error. Invalid cylinder.\n");
	if (exit_code == ERR_PARSECN)
		printf("Parser error. Invalid cone.\n");
	return ;
}

static void	grid_destroy(t_img *img, int height)
{
	int	y;

	if (!img->grid)
		return ;
	y = -1;
	while (++y < height)
	{
		if (img->grid[y])
		{
			free(img->grid[y]);
			img->grid[y] = NULL;
		}
	}
	free(img->grid);
	img->grid = NULL;
}
