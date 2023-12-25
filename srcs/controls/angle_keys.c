/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:57:12 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/20 14:24:35 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	left_key(mlx_key_data_t keydata, t_cub *cub)
{
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		cub->pa -= cub->angle_increment;
		if (cub->pa < 0.0 || cub->pa < -0.0)
			cub->pa += M_PI + M_PI;
		cub->dx = cos(cub->pa) * cub->player_increment;
		cub->dy = sin(cub->pa) * cub->player_increment;
		cub->dx2 = cos(M_PI_2 - cub->pa) * cub->player_increment;
		cub->dy2 = -sin(M_PI_2 - cub->pa) * cub->player_increment;
	}
}

void	right_key(mlx_key_data_t keydata, t_cub *cub)
{
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		cub->pa += cub->angle_increment;
		if (cub->pa > M_PI + M_PI)
			cub->pa -= M_PI + M_PI;
		cub->dx = cos(cub->pa) * cub->player_increment;
		cub->dy = sin(cub->pa) * cub->player_increment;
		cub->dx2 = cos(M_PI_2 - cub->pa) * cub->player_increment;
		cub->dy2 = -sin(M_PI_2 - cub->pa) * cub->player_increment;
	}
}
