/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:19:05 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 13:26:38 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	shoot_door_ray(t_cub *cub)
{
	t_ray	ray;

	init_ray(&ray, cub);
	ray.ra = cub->pa;
	horizontal_count_doors(&ray, cub);
	vertical_count_doors(&ray, cub);
	ray_count(&ray);
	if (ray.type == CLOSED_DOOR)
		closed_door_change(cub, ray);
	else if (ray.type == OPEN_DOOR)
		opened_door_change(cub, ray);
}

void	mouse_update(mouse_key_t but, action_t act, modifier_key_t m, void *par)
{
	t_cub	*cub;

	(void)but;
	(void)act;
	(void)m;
	(void)par;
	cub = (t_cub *)par;
	if (mlx_is_mouse_down(cub->mlx, MLX_MOUSE_BUTTON_LEFT))
		shoot_door_ray(cub);
}

void	left_mouvement(t_cub *cub)
{
	cub->pa += cub->angle_increment;
	if (cub->pa > M_PI + M_PI)
		cub->pa -= M_PI + M_PI;
	cub->dx = cos(cub->pa) * cub->player_increment;
	cub->dy = sin(cub->pa) * cub->player_increment;
	cub->dx2 = cos(M_PI_2 - cub->pa) * cub->player_increment;
	cub->dy2 = -sin(M_PI_2 - cub->pa) * cub->player_increment;
}

void	right_mouvement(t_cub *cub)
{
	cub->pa -= cub->angle_increment;
	if (cub->pa < 0.0 || cub->pa < -0.0)
		cub->pa += M_PI + M_PI;
	cub->dx = cos(cub->pa) * cub->player_increment;
	cub->dy = sin(cub->pa) * cub->player_increment;
	cub->dx2 = cos(M_PI_2 - cub->pa) * cub->player_increment;
	cub->dy2 = -sin(M_PI_2 - cub->pa) * cub->player_increment;
}

void	cursor_update(double xpos, double ypos, void *param)
{
	t_cub			*cub;
	static double	oldx;

	cub = (t_cub *)param;
	(void)ypos;
	if (xpos - oldx > 0)
		left_mouvement(cub);
	else if (xpos - oldx < 0)
		right_mouvement(cub);
	oldx = xpos;
}
