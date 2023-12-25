/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _free.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:00:05 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/25 12:14:27 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_data(t_cub *cub)
{
	free_array(cub->map);
	free(cub->colors);
	free(cub->sprites);
	free_initialized_textures(cub);
	mlx_delete_image(cub->mlx, cub->backround);
	mlx_delete_image(cub->mlx, cub->hand);
	mlx_delete_image(cub->mlx, cub->cursor);
	mlx_terminate(cub->mlx);
	free(cub);
}
