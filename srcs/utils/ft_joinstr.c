/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:00:52 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/20 14:24:35 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_joinstr(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*newstr;
	int		length;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = (char *)ft_calloc(sizeof(char) * (length + 1), 1);
	if (!newstr)
		return (NULL);
	while (s1[++i] != 0)
	{
		if (s1[i] == '\\' && s1[i + 1] == 0)
			break ;
		newstr[i] = s1[i];
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (free(s1), free(s2), newstr);
}