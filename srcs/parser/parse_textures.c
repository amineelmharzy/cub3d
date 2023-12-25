/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:54:27 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/22 14:58:26 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_index(char *s)
{
	while (*s && *s == ' ')
		s++;
	if (!ft_strncmp(s, "NO ", 3))
		return (0);
	else if (!ft_strncmp(s, "SO ", 3))
		return (1);
	else if (!ft_strncmp(s, "WE ", 3))
		return (2);
	else if (!ft_strncmp(s, "EA ", 3))
		return (3);
	else if (!ft_strncmp(s, "F ", 2))
		return (4);
	else if (!ft_strncmp(s, "C ", 2))
		return (5);
	else
		return (-1);
}

char	*get_element(char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (*s != 0 && *s == ' ')
		s++;
	while (*s != 0 && *s != ' ')
		s++;
	while (*s != 0 && *s == ' ')
		s++;
	res = ft_calloc(ft_strlen(s), 1);
	while (*s != 0 && *s != '\n' && *s != ' ')
		res[i++] = *s++;
	res[i] = 0;
	return (res);
}

int	check_element(char **str, int i)
{
	char	*s;
	int		count;

	count = 0;
	s = *str;
	if (i == -1 || (i < 4 && count_strings(*str, ' ') != 2))
		return (write_error(2), 0);
	if (i > 3)
	{
		while (*s)
		{
			if (*s == ',')
				count++;
			s++;
		}
		if (count != 2 || !check_color(*str))
			return (write_error(3), 0);
		s = *str;
	}
	s = get_element(s);
	free(*str);
	*str = s;
	return (1);
}

int	set_color(t_cub *cub, char *s, int i)
{
	char	**arr;

	arr = ft_split(s, ',');
	if (!arr)
		return (0);
	cub->colors[i % 4].red = ft_atoi(arr[0]);
	if ((cub->colors[i % 4].red == -1)
		|| !(cub->colors[i % 4].red >= 0 && cub->colors[i % 4].red <= 255))
		return (_free(arr), 0);
	cub->colors[i % 4].green = ft_atoi(arr[1]);
	if ((cub->colors[i % 4].green == -1)
		|| !(cub->colors[i % 4].red >= 0 && cub->colors[i % 4].red <= 255))
		return (_free(arr), 0);
	cub->colors[i % 4].blue = ft_atoi(arr[2]);
	if ((cub->colors[i % 4].blue == -1)
		|| !(cub->colors[i % 4].red >= 0 && cub->colors[i % 4].red <= 255))
		return (_free(arr), 0);
	_free(arr);
	return (1);
}

int	parse_textures(t_cub *cub, int fd, int i)
{
	char		*s;
	static int	count;

	if (count != 0)
		return (write_error(4), 0);
	if (i == 5)
		return (1);
	s = get_next_line(fd);
	if (s && s[0] != '\n')
	{
		i = get_index(s);
		if (!check_element(&s, i))
			return (free(s), 0);
		if ((i < 4 && cub->texture_files[i])
			|| (i > 4 && i < 5 && cub->colors[i % 4].red != -1))
			count++;
		if (i < 4)
			cub->texture_files[i] = ft_strdup(s);
		else if (i >= 4 && i < 6 && !set_color(cub, s, i))
			return (free(s), 0);
	}
	if (s)
		free(s);
	return (parse_textures(cub, fd, i));
}
