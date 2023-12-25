/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:59:57 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/20 14:24:35 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_down(double a)
{
	if (a < M_PI && a >= 0)
		return (1);
	return (0);
}

int	is_up(double a)
{
	if (a >= M_PI && a <= M_PI * 2)
		return (1);
	return (0);
}

int	is_left(double a)
{
	if (a >= M_PI_2 && a <= M_PI + M_PI_2)
		return (1);
	return (0);
}

int	is_right(double a)
{
	if (a <= M_PI_2 || a >= M_PI + M_PI_2)
		return (1);
	return (0);
}
