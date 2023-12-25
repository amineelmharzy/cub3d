/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:53:17 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/20 21:11:40 by ael-mhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*add_padding(char *line, int max_length)
{
	char	*padding;
	char	*res;
	int		i;

	i = 0;
	padding = ft_calloc((max_length - ft_strlen(line)) + 1, 1);
	if (!padding)
		return (perror("Error\n"), NULL);
	padding[(max_length - ft_strlen(line))] = 0;
	while (i < max_length - ft_strlen(line))
		padding[i++] = ' ';
	res = ft_joinstr(line, padding);
	return (res);
}

int	extract_map(t_cub *cub, char **raw_map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && line[0] != '\n')
	{
		cub->map_height++;
		if (ft_strlen(line) > cub->map_width)
			cub->map_width = ft_strlen(line) - 1;
		*raw_map = ft_joinstr(*raw_map, line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (!ft_isempty_line(line))
			return (free(line), free(*raw_map), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

char	**read_map(t_cub *cub, int fd)
{
	char	*raw_map;
	char	**map;
	char	*line;
	int		i;

	i = 0;
	raw_map = ft_calloc(1, 1);
	if (!raw_map)
		return (NULL);
	if (!extract_map(cub, &raw_map, fd))
		return (NULL);
	if (!raw_map)
		return (perror("Error\n"), NULL);
	map = ft_split(raw_map, '\n');
	if (!map)
		return (free(raw_map), perror("Error\n"), NULL);
	while (map[i])
	{
		line = add_padding(map[i], cub->map_width);
		if (!line)
			return (free(raw_map), _free(map), perror("Error\n"), NULL);
		map[i++] = line;
	}
	return (free(raw_map), map);
}
