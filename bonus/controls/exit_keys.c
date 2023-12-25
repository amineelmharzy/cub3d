/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:58:41 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/25 14:10:48 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	close_window(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	free_data(cub);
	exit(0);
}

void	escape_key(mlx_key_data_t keydata, t_cub *cub)
{
	(void)keydata;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
	{
		free_data(cub);
		exit(0);
	}
}
