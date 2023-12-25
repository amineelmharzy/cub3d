/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:49:18 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/20 21:52:25 by ael-mhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_atoi(char *str)
{
	int			i;
	long long	number;

	i = 0;
	number = 0;
	if (!str || !str[0] || str[0] == '\n')
		return (-1);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	while (str[i] == ' ' || str[i] == '\n')
		i++;
	if (str[i] || number < 0 || number > 255)
		return (-1);
	return (number);
}
