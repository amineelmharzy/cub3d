/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:28:27 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/25 13:21:00 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	horizontal_count(t_ray *ray, t_cub *cub)
{
	h_closest_point_and_increment(ray, cub);
	h_increment_until_wall(ray, cub);
	ray->hd = distance_between_tow_points(cub->px, cub->py, ray->hx, ray->hy);
}

void	h_closest_point_and_increment(t_ray *ray, t_cub *cub)
{
	ray->stop_ray = 0;
	if (ray->ra == 0.0 || ray->ra == -0.0 || ray->ra == +0.0 || ray->ra == M_PI)
	{
		ray->hy = cub->py;
		ray->hx = cub->px;
		ray->stop_ray = 1;
	}
	else if (ray->ra > M_PI)
	{
		ray->hy = ((int)(cub->py / WALL_REZ) * WALL_REZ);
		ray->hx = cub->px + (cub->py - ray->hy) / -(tan(ray->ra) + 0.00001);
		ray->y_step = -WALL_REZ;
		ray->x_step = ray->y_step / (tan(ray->ra) + 0.00001);
	}
	else if (ray->ra < M_PI)
	{
		ray->hy = ((int)(cub->py / WALL_REZ) * WALL_REZ) + WALL_REZ;
		ray->hx = (cub->px + (cub->py - ray->hy) / -(tan(ray->ra) + 0.00001));
		ray->y_step = WALL_REZ;
		ray->x_step = ray->y_step / (tan(ray->ra) + 0.00001);
	}
}

int	is_ray_selection_up_h(t_ray *ray, t_cub *cub)
{
	if (is_in_wall(cub, ray->hx - REY_PER, ray->hy - REY_PER))
	{
		ray->h_type = WALL;
		return (1);
	}
	if (is_in_close(cub, ray->hx - REY_PER, ray->hy - REY_PER))
	{
		ray->h_type = CLOSED_DOOR;
		return (1);
	}
	return (0);
}

int	is_ray_selection_down_h(t_ray *ray, t_cub *cub)
{
	if (is_in_wall(cub, ray->hx + REY_PER, ray->hy + REY_PER))
	{
		ray->h_type = WALL;
		return (1);
	}
	if (is_in_close(cub, ray->hx + REY_PER, ray->hy + REY_PER))
	{
		ray->h_type = CLOSED_DOOR;
		return (1);
	}
	return (0);
}

void	h_increment_until_wall(t_ray *ray, t_cub *cub)
{
	while (!ray->stop_ray)
	{
		if (out_of_limit_h(ray, cub))
			break ;
		if (ray->ra > M_PI && is_ray_selection_up_h(ray, cub))
			break ;
		else if (ray->ra < M_PI && is_ray_selection_down_h(ray, cub))
			break ;
		ray->hy += ray->y_step;
		ray->hx += ray->x_step;
	}
}
