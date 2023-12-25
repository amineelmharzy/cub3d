/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:50:55 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/25 15:43:50 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_initialized_textures(t_cub *cub)
{
	if (cub->textures->north)
		mlx_delete_texture(cub->textures->north);
	if (cub->textures->south)
		mlx_delete_texture(cub->textures->south);
	if (cub->textures->east)
		mlx_delete_texture(cub->textures->east);
	if (cub->textures->west)
		mlx_delete_texture(cub->textures->west);
	if (cub->textures)
		free(cub->textures);
}

int	initialize_textures(t_cub *cub)
{
	cub->textures = malloc(sizeof(t_textures));
	if (!cub->textures)
		return (0);
	cub->textures->north = 0;
	cub->textures->south = 0;
	cub->textures->east = 0;
	cub->textures->west = 0;
	cub->textures->north = mlx_load_png(cub->texture_files[0]);
	if (!cub->textures->north)
		return (free_initialized_textures(cub), 0);
	cub->textures->south = mlx_load_png(cub->texture_files[1]);
	if (!cub->textures->south)
		return (free_initialized_textures(cub), 0);
	cub->textures->east = mlx_load_png(cub->texture_files[2]);
	if (!cub->textures->east)
		return (free_initialized_textures(cub), 0);
	cub->textures->west = mlx_load_png(cub->texture_files[3]);
	if (!cub->textures->west)
		return (free_initialized_textures(cub), 0);
	_free(cub->texture_files);
	return (1);
}
