/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:24:24 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/22 12:24:23 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_update(mlx_key_data_t keydata, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	left_key(keydata, cub);
	right_key(keydata, cub);
	w_key(keydata, cub);
	s_key(keydata, cub);
	d_key(keydata, cub);
	a_key(keydata, cub);
	escape_key(keydata, cub);
}
