/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:29:33 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/25 12:53:30 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_selection(t_ray *ray, double x, double y, double distance)
{
	ray->rx = x;
	ray->ry = y;
	ray->dist_from_wall = distance;
}

void	ray_count(t_ray *ray)
{
	if (ray->hd == 0)
	{
		ray_selection(ray, ray->vx, ray->vy, ray->vd);
		ray->type = ray->v_type;
		ray->direction_of_ray = VERTICAL;
	}
	else if (ray->vd == 0)
	{
		ray_selection(ray, ray->hx, ray->hy, ray->hd);
		ray->type = ray->h_type;
		ray->direction_of_ray = HORIZONTAL;
	}
	else if (ray->vd <= ray->hd)
	{
		ray_selection(ray, ray->vx, ray->vy, ray->vd);
		ray->type = ray->v_type;
		ray->direction_of_ray = VERTICAL;
	}
	else if (ray->vd >= ray->hd)
	{
		ray_selection(ray, ray->hx, ray->hy, ray->hd);
		ray->type = ray->h_type;
		ray->direction_of_ray = HORIZONTAL;
	}
}

void	init_ray(t_ray *ray, t_cub *cub)
{
	ray->vd = 0;
	ray->hd = 0;
	ray->x_step = 0;
	ray->y_step = 0;
	ray->stop_ray = 0;
	ray->hy = cub->py;
	ray->hx = cub->px;
	ray->vy = cub->py;
	ray->vx = cub->px;
	ray->rx = cub->px;
	ray->ry = cub->py;
	ray->ra = cub->pa - degree(FOV_ANGLE / 2);
	if (ray->ra < 0)
		ray->ra += M_PI + M_PI;
	if (ray->ra > M_PI + M_PI)
		ray->ra -= M_PI + M_PI;
}
int		is_in_open(t_cub *cub, double x, double y);

void	draw_wall(int x0, t_ray *ray, t_cub *cub)
{
	t_strip	strip;

	strip.texture = texture_selection(ray, cub);
	fish_eye_correction(ray, cub);
	lenth_and_offset_calculations(&strip, ray);
	texture_cordonates_generation(&strip, ray);
	texture_drawing(&strip, cub, x0);
}

int	draw_ray(t_cub *cub)
{
	int		x;
	t_ray	ray;

	init_ray(&ray, cub);
	x = -1;
	while (x <= WIDTH)
	{
		horizontal_count(&ray, cub);
		vertical_count(&ray, cub);
		ray_count(&ray);
		draw_wall(x, &ray, cub);
		ray.ra += degree(FOV_ANGLE / WIDTH);
		if (ray.ra < 0.0 || cub->pa < -0.0)
			ray.ra += M_PI + M_PI;
		else if (ray.ra > M_PI + M_PI)
			ray.ra -= M_PI + M_PI;
		x++;
		cub->raydist[x] = ray.dist_from_wall;
	}
	return (1);
}
