/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:32:38 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/25 15:50:43 by ael-mhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (-1);
	return (write(fd, s, ft_strlen(s)));
}

int	write_error(int error_number)
{
	ft_putstr_fd("Error\n", 2);
	if (error_number == 0)
		return (ft_putstr_fd("File not .cub\n", 2));
	else if (error_number == 1)
		return (ft_putstr_fd("Error in parameters\n", 2));
	else if (error_number == 2)
		return (ft_putstr_fd("Error in textures\n", 2));
	else if (error_number == 3)
		return (ft_putstr_fd("Error in colors\n", 2));
	else if (error_number == 4)
		return (ft_putstr_fd("Not Enough Arguments\n", 2));
	else if (error_number == 5)
		return (ft_putstr_fd("Stranger item in map\n", 2));
	else if (error_number == 6)
		return (ft_putstr_fd("More players in map\n", 2));
	else if (error_number == 7)
		return (ft_putstr_fd("Map not suronded by walls\n", 2));
	else if (error_number == 8)
		return (ft_putstr_fd("Hidden file not supported\n", 2));
	return (0);
}
