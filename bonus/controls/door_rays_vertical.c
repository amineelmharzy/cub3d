/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_rays_vertical.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:24:29 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 13:58:40 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_intersected_v_right(t_ray *ray, t_cub *cub)
{
	if (is_in_open(cub, ray->vx + REY_PER, ray->vy + REY_PER))
	{
		ray->v_type = OPEN_DOOR;
		return (1);
	}
	if (is_in_close(cub, ray->vx + REY_PER, ray->vy + REY_PER))
	{
		ray->v_type = CLOSED_DOOR;
		return (1);
	}
	if (is_in_wall(cub, ray->vx + REY_PER, ray->vy + REY_PER))
	{
		ray->v_type = WALL;
		return (1);
	}
	return (0);
}

int	is_intersected_v_left(t_ray *ray, t_cub *cub)
{
	if (is_in_open(cub, ray->vx - REY_PER, ray->vy - REY_PER))
	{
		ray->v_type = OPEN_DOOR;
		return (1);
	}
	if (is_in_close(cub, ray->vx - REY_PER, ray->vy - REY_PER))
	{
		ray->v_type = CLOSED_DOOR;
		return (1);
	}
	if (is_in_close(cub, ray->vx - REY_PER, ray->vy - REY_PER))
	{
		ray->v_type = WALL;
		return (1);
	}
	return (0);
}

void	v_increment_until_wall_doors(t_ray *ray, t_cub *cub)
{
	while (!ray->stop_ray)
	{
		if (out_of_limit_v(ray, cub))
			break ;
		if (ray->ra < M_PI_2 || ray->ra > M_PI + M_PI_2)
		{
			if (is_intersected_v_right(ray, cub))
				break ;
			else
			{
				ray->vy += ray->y_step;
				ray->vx += ray->x_step;
			}
		}
		else if (ray->ra > M_PI_2 && ray->ra < M_PI + M_PI_2)
		{
			if (is_intersected_v_left(ray, cub))
				break ;
			else
			{
				ray->vy += ray->y_step;
				ray->vx += ray->x_step;
			}
		}
	}
}

void	vertical_count_doors(t_ray *ray, t_cub *cub)
{
	v_closest_point_and_increment(ray, cub);
	v_increment_until_wall_doors(ray, cub);
	ray->vd = distance_between_tow_points(cub->px, cub->py, ray->vx, ray->vy);
}
