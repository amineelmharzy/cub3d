/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:58:05 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 15:30:18 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	w_key(mlx_key_data_t keydata, t_cub *cub)
{
	int	pxo;
	int	pyo;

	if (cub->dx < 0)
		pxo = -MV_LIMIT;
	else
		pxo = MV_LIMIT;
	if (cub->dy < 0)
		pyo = -MV_LIMIT;
	else
		pyo = MV_LIMIT;
	(void)keydata;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
	{
		if (!is_in_wall(cub, cub->px + pxo + cub->dx, cub->py))
			cub->px += cub->dx;
		if (!is_in_wall(cub, cub->px, cub->py + cub->dy + pyo))
			cub->py += cub->dy;
	}
}

void	s_key(mlx_key_data_t keydata, t_cub *cub)
{
	int	pxo;
	int	pyo;

	if (cub->dx < 0)
		pxo = -MV_LIMIT;
	else
		pxo = MV_LIMIT;
	if (cub->dy < 0)
		pyo = -MV_LIMIT;
	else
		pyo = MV_LIMIT;
	(void)keydata;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
	{
		if (!is_in_wall(cub, cub->px - pxo - cub->dx, cub->py))
			cub->px -= cub->dx;
		if (!is_in_wall(cub, cub->px, cub->py - cub->dy - pyo))
			cub->py -= cub->dy;
	}
}

void	d_key(mlx_key_data_t keydata, t_cub *cub)
{
	int	pxo;
	int	pyo;

	if (cub->dx2 < 0)
		pxo = -MV_LIMIT;
	else
		pxo = MV_LIMIT;
	if (cub->dy2 < 0)
		pyo = -MV_LIMIT;
	else
		pyo = MV_LIMIT;
	(void)keydata;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		if (!is_in_wall(cub, cub->px - pxo - cub->dx2, cub->py))
			cub->px -= cub->dx2;
		if (!is_in_wall(cub, cub->px, cub->py - cub->dy2 - pyo))
			cub->py -= cub->dy2;
	}
}

void	a_key(mlx_key_data_t keydata, t_cub *cub)
{
	int	pxo;
	int	pyo;

	if (cub->dx2 < 0)
		pxo = -MV_LIMIT;
	else
		pxo = MV_LIMIT;
	if (cub->dy2 < 0)
		pyo = -MV_LIMIT;
	else
		pyo = MV_LIMIT;
	(void)keydata;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		if (!is_in_wall(cub, cub->px + pxo + cub->dx2, cub->py))
			cub->px += cub->dx2;
		if (!is_in_wall(cub, cub->px, cub->py + cub->dy2 + pyo))
			cub->py += cub->dy2;
	}
}
