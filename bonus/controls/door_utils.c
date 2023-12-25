/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:24:26 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 13:25:32 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_in_open(t_cub *cub, double x, double y)
{
	if (x < 0 || x > (cub->map_width) * WALL_REZ || y < 0
		|| y > (cub->map_height) * WALL_REZ)
		return (0);
	if (cub->map[(int)(y / WALL_REZ)][(int)(x / WALL_REZ)] == 'O')
		return (1);
	return (0);
}

int	is_in_close(t_cub *cub, double x, double y)
{
	if (x < 0 || x > (cub->map_width) * WALL_REZ || y < 0
		|| y > (cub->map_height) * WALL_REZ)
		return (0);
	if (cub->map[(int)(y / WALL_REZ)][(int)(x / WALL_REZ)] == 'C')
		return (1);
	return (0);
}

void	closed_door_change(t_cub *cub, t_ray ray)
{
	if (is_up(ray.ra) && is_left(ray.ra))
		cub->map[(int)((ray.ry - REY_PER) / WALL_REZ)][(int)((ray.rx - REY_PER)
				/ WALL_REZ)] = 'O';
	if (is_up(ray.ra) && is_right(ray.ra))
		cub->map[(int)((ray.ry - REY_PER) / WALL_REZ)][(int)((ray.rx + REY_PER)
				/ WALL_REZ)] = 'O';
	if (is_down(ray.ra) && is_left(ray.ra))
		cub->map[(int)((ray.ry + REY_PER) / WALL_REZ)][(int)((ray.rx - REY_PER)
				/ WALL_REZ)] = 'O';
	if (is_down(ray.ra) && is_right(ray.ra))
		cub->map[(int)((ray.ry + REY_PER) / WALL_REZ)][(int)((ray.rx + REY_PER)
				/ WALL_REZ)] = 'O';
}

void	opened_door_change(t_cub *cub, t_ray ray)
{
	if (is_up(ray.ra) && is_left(ray.ra))
		cub->map[(int)((ray.ry - REY_PER) / WALL_REZ)][(int)((ray.rx - REY_PER)
				/ WALL_REZ)] = 'C';
	if (is_up(ray.ra) && is_right(ray.ra))
		cub->map[(int)((ray.ry - REY_PER) / WALL_REZ)][(int)((ray.rx + REY_PER)
				/ WALL_REZ)] = 'C';
	if (is_down(ray.ra) && is_left(ray.ra))
		cub->map[(int)((ray.ry + REY_PER) / WALL_REZ)][(int)((ray.rx - REY_PER)
				/ WALL_REZ)] = 'C';
	if (is_down(ray.ra) && is_right(ray.ra))
		cub->map[(int)((ray.ry + REY_PER) / WALL_REZ)][(int)((ray.rx + REY_PER)
				/ WALL_REZ)] = 'C';
}
