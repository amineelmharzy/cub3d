/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mhar <ael-mhar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:43:00 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/20 21:43:16 by ael-mhar         ###   ########.fr       */
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
			return (_free(array), 0);
		s++;
	}
	return (_free(array), 1);
}
