/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:43:00 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/25 12:08:52 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_color(char *s)
{
	char	**array;

	while (*s == ' ')
		s++;
	while (*s != ' ' && *s != 0)
		s++;
	while (*s == ' ')
		s++;
	if (count_strings(s, ',') != 3)
		return (0);
	array = ft_split(s, ',');
	if (!array)
		return (perror("Error\n"), 0);
	s = array[2];
	while (*s != 0)
	{
		if (!(*s >= 48 && *s <= 57) && (*s != ' ' && *s != '\n'))
			return (free_array(array), 0);
		s++;
	}
	return (free_array(array), 1);
}
