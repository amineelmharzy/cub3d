/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:40:01 by mkhellou          #+#    #+#             */
/*   Updated: 2023/07/27 13:31:29 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	display_update(void *data)
{
	t_cub	*cub;

	cub = (t_cub *)data;
	draw_floor_and_celling(cub);
	draw_ray(cub);
	draw_sprite(cub);
	draw_map(cub);
	draw_player(cub);
}

void	cursor_hand_generation(t_cub *cub)
{
	cub->cursor = mlx_texture_to_image(cub->mlx, cub->textures->cursor);
	if (!cub->cursor)
	{
		mlx_close_window(cub->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return ;
	}
	cub->hand = mlx_texture_to_image(cub->mlx, cub->textures->hand);
	if (!cub->hand)
	{
		mlx_close_window(cub->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return ;
	}
}

void	render_image_in_window(t_cub *cub)
{
	cursor_hand_generation(cub);
	if (mlx_image_to_window(cub->mlx, cub->backround, 0, 0) == -1)
	{
		mlx_close_window(cub->mlx);
		printf("%s", mlx_strerror(mlx_errno));
	}
	if (mlx_image_to_window(cub->mlx, cub->cursor, ((WIDTH) / 2) - 16, (HEIGHT
				/ 2) - 16) == -1)
	{
		mlx_close_window(cub->mlx);
		printf("%s", mlx_strerror(mlx_errno));
	}
	if (mlx_image_to_window(cub->mlx, cub->hand, ((WIDTH) / 2) + 100, (HEIGHT
				- cub->hand->height)) == -1)
	{
		mlx_close_window(cub->mlx);
		printf("%s", mlx_strerror(mlx_errno));
	}
}

void	image_generation(t_cub *cub)
{
	unsigned int	backround_color;
	unsigned int	x;
	unsigned int	y;
	unsigned int	color;

	backround_color = ft_pixel(25, 255, 25, 0);
	cub->backround = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->backround)
	{
		mlx_close_window(cub->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return ;
	}
	x = 0;
	while (++x < cub->backround->width)
	{
		y = 0;
		while (++y < cub->backround->height)
		{
			color = backround_color;
			if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
				mlx_put_pixel(cub->backround, x, y, color);
		}
	}
	render_image_in_window(cub);
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	if (ac != 2)
		return (write_error(4), EXIT_FAILURE);
	cub = (t_cub *)ft_calloc(sizeof(t_cub), 1);
	if (!cub || !initialize_map(cub, av[1]))
		return (EXIT_FAILURE);
	if (window_initialisation(cub))
		return (EXIT_FAILURE);
	if (!initialize_textures(cub))
		return (free_array(cub->texture_files), EXIT_FAILURE);
	ft_init(cub);
	image_generation(cub);
	mlx_loop_hook(cub->mlx, display_update, cub);
	mlx_key_hook(cub->mlx, key_update, cub);
	mlx_mouse_hook(cub->mlx, mouse_update, cub);
	mlx_close_hook(cub->mlx, close_window, cub);
	mlx_cursor_hook(cub->mlx, cursor_update, cub);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_DISABLED);
	mlx_loop(cub->mlx);
	free_data(cub);
	return (EXIT_SUCCESS);
}
