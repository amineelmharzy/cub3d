/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:16:56 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 19:54:36 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	sprite_animation(t_cub *cub, t_sprite *sprite)
{
	if (sprite->state % 2 == 0)
	{
		if (sprite->to_switch % 8 == 0)
			sprite->text = (mlx_texture_t *)cub->textures->sprite[0];
		else if (sprite->to_switch % 8 == 1)
			sprite->text = (mlx_texture_t *)cub->textures->sprite[1];
		else if (sprite->to_switch % 8 == 2)
			sprite->text = (mlx_texture_t *)cub->textures->sprite[2];
		else if (sprite->to_switch % 8 == 3)
			sprite->text = (mlx_texture_t *)cub->textures->sprite[3];
		else if (sprite->to_switch % 8 == 4)
			sprite->text = (mlx_texture_t *)cub->textures->sprite[4];
		else if (sprite->to_switch % 8 == 5)
			sprite->text = (mlx_texture_t *)cub->textures->sprite[5];
		else if (sprite->to_switch % 8 == 6)
			sprite->text = (mlx_texture_t *)cub->textures->sprite[6];
		else
			sprite->text = (mlx_texture_t *)cub->textures->sprite[7];
		sprite->to_switch++;
	}
	sprite->state++;
}

void	put_sprite(t_cub *cub, t_sprite *sprite, int dim, t_point *p)
{
	if (cub->raydist[(int)(sprite->sx + p->i) + 2] > sprite->distance)
		mlx_put_pixel(cub->backround, sprite->sx + p->i, sprite->sy + p->j,
			sprite_colors((uint32_t *)sprite->text->pixels, p->i / dim, p->j
				/ dim, sprite->text->width));
}

void	sprite_rendering(t_cub *cub, t_sprite *sprite)
{
	int		dim;
	t_point	p;

	if ((int)(sprite->distance) > 10)
	{
		dim = 1000 / sprite->distance;
		p.i = 0;
		while (p.i < (int)sprite->text->width * dim)
		{
			p.j = 0;
			while (p.j < (int)sprite->text->height * dim)
			{
				if (sprite->sx + p.i > 0 && sprite->sx + p.i < WIDTH
					&& sprite->sy + p.j > 0 && sprite->sy + p.j < HEIGHT)
					put_sprite(cub, sprite, dim, &p);
				p.j++;
			}
			p.i++;
		}
	}
}

void	sprite_data_init(t_cub *cub, t_sprite **sprite, int index)
{
	(*sprite) = &cub->sprites[index];
	(*sprite)->dx = (*sprite)->x - cub->px;
	(*sprite)->dy = (*sprite)->y - cub->py;
	(*sprite)->s_angle = atan2((*sprite)->dy, (*sprite)->dx);
	if ((*sprite)->s_angle > cub->pa + M_PI)
		(*sprite)->s_angle -= 2 * M_PI;
	if ((*sprite)->s_angle < cub->pa - M_PI)
		(*sprite)->s_angle += 2 * M_PI;
	(*sprite)->angle_diff = ((*sprite)->s_angle - cub->pa) * 180 / M_PI;
}

void	draw_sprite(t_cub *cub)
{
	t_sprite	*sprite;
	int			index;

	index = 0;
	while (index < cub->count_sprites)
	{
		sprite_data_init(cub, &sprite, index);
		if (sprite->angle_diff <= FOV_ANGLE && sprite->angle_diff >= -FOV_ANGLE)
		{
			sprite_animation(cub, sprite);
			sprite->distance = distance_between_tow_points(cub->px, cub->py,
					sprite->x, sprite->y);
			sprite->sx = (sprite->angle_diff + FOV_ANGLE / 2) / FOV_ANGLE
				* WIDTH;
			sprite->sy = HEIGHT / 2;
			sprite_rendering(cub, sprite);
		}
		index++;
	}
}
