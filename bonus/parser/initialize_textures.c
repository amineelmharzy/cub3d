/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:50:55 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/25 14:54:59 by ael-mhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	initialize_wrapper(t_cub *cub)
{
	int	i;

	i = 0;
	cub->textures = ft_calloc(sizeof(t_textures), 1);
	if (!cub->textures)
		return (0);
	cub->textures->north = 0;
	cub->textures->south = 0;
	cub->textures->east = 0;
	cub->textures->west = 0;
	cub->textures->door = 0;
	cub->textures->cursor = 0;
	cub->textures->hand = 0;
	while (i < 8)
		cub->textures->sprite[i++] = 0;
	return (1);
}

void	free_initialized_textures(t_cub *cub)
{
	int	i;

	i = -1;
	if (cub->textures->north)
		mlx_delete_texture(cub->textures->north);
	if (cub->textures->south)
		mlx_delete_texture(cub->textures->south);
	if (cub->textures->east)
		mlx_delete_texture(cub->textures->east);
	if (cub->textures->west)
		mlx_delete_texture(cub->textures->west);
	if (cub->textures->door)
		mlx_delete_texture(cub->textures->door);
	if (cub->textures->cursor)
		mlx_delete_texture(cub->textures->cursor);
	if (cub->textures->hand)
		mlx_delete_texture(cub->textures->hand);
	if (!cub->sprites)
		return (free(cub->textures));
	while (++i < 8)
	{
		if (cub->textures->sprite[i])
			mlx_delete_texture(cub->textures->sprite[i]);
	}
	return (free(cub->textures));
}

int	initialize_sprite_textures(t_cub *cub)
{
	cub->textures->sprite[0] = mlx_load_png("./textures/qmark0.png");
	if (!cub->textures->sprite[0])
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->sprite[1] = mlx_load_png("./textures/qmark1.png");
	if (!cub->textures->sprite[1])
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->sprite[2] = mlx_load_png("./textures/qmark2.png");
	if (!cub->textures->sprite[2])
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->sprite[3] = mlx_load_png("./textures/qmark3.png");
	if (!cub->textures->sprite[3])
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->sprite[4] = mlx_load_png("./textures/qmark4.png");
	if (!cub->textures->sprite[4])
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->sprite[5] = mlx_load_png("./textures/qmark5.png");
	if (!cub->textures->sprite[5])
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->sprite[6] = mlx_load_png("./textures/qmark6.png");
	if (!cub->textures->sprite[6])
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->sprite[7] = mlx_load_png("./textures/qmark7.png");
	if (!cub->textures->sprite[7])
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	return (free_array(cub->texture_files), 1);
}

int	initialize_textures(t_cub *cub)
{
	if (!initialize_wrapper(cub))
		return (0);
	cub->textures->north = mlx_load_png(cub->texture_files[0]);
	if (!cub->textures->north)
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->south = mlx_load_png(cub->texture_files[1]);
	if (!cub->textures->south)
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->east = mlx_load_png(cub->texture_files[2]);
	if (!cub->textures->east)
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->west = mlx_load_png(cub->texture_files[3]);
	if (!cub->textures->west)
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->door = mlx_load_png("./textures/door.png");
	if (!cub->textures->door)
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->cursor = mlx_load_png("./textures/cursor.png");
	if (!cub->textures->cursor)
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	cub->textures->hand = mlx_load_png("./textures/hand.png");
	if (!cub->textures->hand)
		return (perror("Error\n"), free_initialized_textures(cub), 0);
	return (initialize_sprite_textures(cub), 1);
}
