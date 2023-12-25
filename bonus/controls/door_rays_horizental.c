/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_rays_horizental.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:24:29 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 13:51:35 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_intersected_h_up(t_ray *ray, t_cub *cub)
{
	if (is_in_open(cub, ray->hx - REY_PER, ray->hy - REY_PER))
	{
		ray->h_type = OPEN_DOOR;
		return (1);
	}
	if (is_in_close(cub, ray->hx - REY_PER, ray->hy - REY_PER))
	{
		ray->h_type = CLOSED_DOOR;
		return (1);
	}
	if (is_in_wall(cub, ray->hx - REY_PER, ray->hy - REY_PER))
	{
		ray->h_type = WALL;
		return (1);
	}
	return (0);
}

int	is_intersected_h_down(t_ray *ray, t_cub *cub)
{
	if (is_in_open(cub, ray->hx + REY_PER, ray->hy + REY_PER))
	{
		ray->h_type = OPEN_DOOR;
		return (1);
	}
	if (is_in_close(cub, ray->hx + REY_PER, ray->hy + REY_PER))
	{
		ray->h_type = CLOSED_DOOR;
		return (1);
	}
	if (is_in_wall(cub, ray->hx + REY_PER, ray->hy + REY_PER))
	{
		ray->h_type = WALL;
		return (1);
	}
	return (0);
}

void	h_increment_until_wall_doors(t_ray *ray, t_cub *cub)
{
	while (!ray->stop_ray)
	{
		if (out_of_limit_h(ray, cub))
			break ;
		if (ray->ra > M_PI)
		{
			if (is_intersected_h_up(ray, cub))
				break ;
			else
			{
				ray->hy += ray->y_step;
				ray->hx += ray->x_step;
			}
		}
		else if (ray->ra < M_PI)
		{
			if (is_intersected_h_down(ray, cub))
				break ;
			else
			{
				ray->hy += ray->y_step;
				ray->hx += ray->x_step;
			}
		}
	}
}

void	horizontal_count_doors(t_ray *ray, t_cub *cub)
{
	h_closest_point_and_increment(ray, cub);
	h_increment_until_wall_doors(ray, cub);
	ray->hd = distance_between_tow_points(cub->px, cub->py, ray->hx, ray->hy);
}
