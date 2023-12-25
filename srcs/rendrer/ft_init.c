/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:59:28 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/26 19:01:50 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init(t_cub *cub)
{
	cub->px = cub->px * WALL_REZ + WALL_REZ / 2;
	cub->py = cub->py * WALL_REZ + WALL_REZ / 2;
	cub->player_increment = 15;
	cub->angle_increment = (M_PI / 180.0) * (10);
	if (cub->player_direction == 'N')
		cub->pa = (M_PI / 180.0) * (180 + 90);
	if (cub->player_direction == 'S')
		cub->pa = (M_PI / 180.0) * (90);
	if (cub->player_direction == 'E')
		cub->pa = (M_PI / 180.0) * (0);
	if (cub->player_direction == 'W')
		cub->pa = (M_PI / 180.0) * (180);
	cub->dx = cos(cub->pa) * cub->player_increment;
	cub->dy = sin(cub->pa) * cub->player_increment;
	cub->dx2 = cos(M_PI_2 - cub->pa) * cub->player_increment;
	cub->dy2 = -sin(M_PI_2 - cub->pa) * cub->player_increment;
}

int	initialize_map(t_cub *cub, char *map_file)
{
	int	fd;

	if (!check_extention(map_file))
		return (0);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (perror("Error\n"), 0);
	if (!parse_map(cub, fd))
		return (close(fd), 0);
	return (close(fd), 1);
}

int	window_initialisation(t_cub *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!cub->mlx)
	{
		printf("%s\n", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (0);
}
	/*
		void  mlx_set_icon(mlx_t* mlx, mlx_texture_t* image);
		void  mlx_set_setting(mlx_settings_t setting, int32_t value);
	*/
