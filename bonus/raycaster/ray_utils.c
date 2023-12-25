/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:20:02 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 13:21:17 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	out_of_limit_h(t_ray *ray, t_cub *cub)
{
	if ((int)ray->hy < 0 || (int)ray->hx < 0 || (int)(ray->hy
		/ WALL_REZ) > cub->map_height - 1 || (int)(ray->hx
		/ WALL_REZ) > cub->map_width)
		return (1);
	return (0);
}

int	out_of_limit_v(t_ray *ray, t_cub *cub)
{
	if ((int)ray->vy < 0 || (int)ray->vx < 0 || (int)(ray->vy
		/ WALL_REZ) > cub->map_height - 1 || (int)(ray->vx
		/ WALL_REZ) > cub->map_width - 1)
		return (1);
	return (0);
}
