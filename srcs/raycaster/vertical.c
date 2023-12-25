/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:29:00 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/20 14:24:35 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	vertical_count(t_ray *ray, t_cub *cub)
{
	v_closest_point_and_increment(ray, cub);
	v_increment_until_wall(ray, cub);
	ray->vd = distance_between_tow_points(cub->px, cub->py, ray->vx, ray->vy);
}

void	v_closest_point_and_increment(t_ray *ray, t_cub *cub)
{
	ray->stop_ray = 0;
	if (ray->ra > M_PI_2 && ray->ra < M_PI + M_PI_2)
	{
		ray->vx = ((int)(cub->px / WALL_REZ) * WALL_REZ);
		ray->vy = cub->py + (cub->px - ray->vx) * -tan(ray->ra);
		ray->x_step = -WALL_REZ;
		ray->y_step = ray->x_step * tan(ray->ra);
	}
	else if (ray->ra < M_PI_2 || ray->ra > M_PI + M_PI_2)
	{
		ray->vx = ((int)(cub->px / WALL_REZ) * WALL_REZ) + WALL_REZ;
		ray->vy = cub->py + (cub->px - ray->vx) * -tan(ray->ra);
		ray->x_step = WALL_REZ;
		ray->y_step = ray->x_step * tan(ray->ra);
	}
	else if (ray->ra == M_PI_2 || ray->ra == (M_PI + M_PI_2))
	{
		ray->vy = cub->py;
		ray->vx = cub->px;
		ray->stop_ray = 1;
	}
}

int	out_of_limit_v(t_ray *ray, t_cub *cub)
{
	if ((int)ray->vy < 0 || (int)ray->vx < 0 || (int)(ray->vy
		/ WALL_REZ) > cub->map_height - 1 || (int)(ray->vx
		/ WALL_REZ) > cub->map_width - 1)
		return (1);
	return (0);
}

void	v_increment_until_wall(t_ray *ray, t_cub *cub)
{
	while (!ray->stop_ray)
	{
		if (out_of_limit_v(ray, cub))
			break ;
		if (ray->ra < M_PI_2 || ray->ra > M_PI + M_PI_2)
		{
			if (is_in_wall(cub, ray->vx + REY_PER, ray->vy + REY_PER))
				break ;
			else
			{
				ray->vy += ray->y_step;
				ray->vx += ray->x_step;
			}
		}
		else if (ray->ra > M_PI_2 && ray->ra < M_PI + M_PI_2)
		{
			if (is_in_wall(cub, ray->vx - REY_PER, ray->vy - REY_PER))
				break ;
			else
			{
				ray->vy += ray->y_step;
				ray->vx += ray->x_step;
			}
		}
	}
}
