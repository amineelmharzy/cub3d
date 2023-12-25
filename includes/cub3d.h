/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou <mkhellou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:03:34 by ael-mhar          #+#    #+#             */
/*   Updated: 2023/07/26 19:03:27 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080
# define WALL_REZ 32
# define REY_PER 0.000001
# define MAP_SCALE 0.3
# define FOV_ANGLE 60.0
# define MV_LIMIT 10

# define BUFFER_SIZE 1

enum
{
	VERTICAL,
	HORIZONTAL,
};

enum
{
	FL,
	CL,
};

enum
{
	WALL = 1,
	OPEN_DOOR = 2,
	CLOSED_DOOR = 3,
};

enum
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
	int				alpha;
}					t_color;

typedef struct s_image
{
	mlx_texture_t	*image;
	uint32_t		color;
}					t_image;

typedef struct s_ray
{
	double			x_step;
	double			y_step;
	int				stop_ray;
	double			hy;
	double			hx;
	double			vx;
	double			vy;
	double			rx;
	double			ry;
	double			ra;
	double			vd;
	double			hd;
	int				direction_of_ray;
	double			dist_from_wall;
	int				v_type;
	int				h_type;
	int				type;
	int				wx;
	int				wy;
}					t_ray;

typedef struct t_strip
{
	double			real_distance;
	double			lineh;
	double			lineo;
	double			text_y_step;
	double			texty_off;
	double			tx;
	double			ty;
	mlx_texture_t	*texture;
}					t_strip;

typedef struct t_sprite
{
	int				x;
	int				y;
	double			dx;
	double			dy;
	double			sx;
	double			sy;
	double			s_angle;
	double			angle_diff;
	double			distance;
	mlx_texture_t	*text;
	unsigned int	state;
	unsigned int	to_switch;
}					t_sprite;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	mlx_texture_t	*door;
	mlx_texture_t	*cursor;
	mlx_texture_t	*hand;
	mlx_texture_t	*sprite[8];
}					t_textures;

typedef struct s_point
{
	int				i;
	int				j;
}					t_point;

typedef struct s_cub
{
	double			pa;
	int				px;
	int				py;
	double			dx;
	double			dy;
	double			dx2;
	double			dy2;
	double			angle_increment;
	double			player_increment;
	char			player_direction;
	int				map_height;
	int				map_width;
	int				count_sprites;
	int				raydist[WIDTH];
	char			**texture_files;
	char			**map;
	mlx_image_t		*backround;
	mlx_image_t		*cursor;
	mlx_image_t		*hand;
	t_color			*colors;
	mlx_t			*mlx;
	t_textures		*textures;
	t_sprite		*sprites;
}					t_cub;

void				free_array(char **array);
int					ft_atoi(char *str);
char				**ft_split(char *str, char set);
char				*ft_joinstr(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, int n);
char				*ft_strdup(char *src);
char				*get_next_line(int fd);
void				*ft_calloc(size_t elementCount, size_t elementSize);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strlen(const char *str);
int					parse_map(t_cub *cub, int fd);
char				**read_map(t_cub *cub, int fd);
int					parse_textures(t_cub *cub, int fd, int i);
int					check_map(t_cub *cub);
int					check_textures(t_cub *cub);
int					count_strings(char *str, char set);
int					check_extention(char *file_name);

int					ft_pixel(int r, int g, int b, int a);
void				image_generation(t_cub *cub);
double				degree(double angle);
int					is_in_wall(t_cub *cub, double x, double y);
int					is_down(double a);
int					is_up(double a);
int					is_left(double a);
int					is_right(double a);
void				key_update(mlx_key_data_t keydata, void *param);
void				draw_floor_and_celling(t_cub *cub);
void				draw_map(t_cub *cub);
void				draw_player(t_cub *cub);
double				distance(double x1, double y1, double x2, double y2);
void				draw_wall(int i, t_ray *ray, t_cub *cub);
int					draw_ray(t_cub *cub);
void				horizontal_count(t_ray *ray, t_cub *cub);
void				vertical_count(t_ray *ray, t_cub *cub);
void				ray_count(t_ray *ray);
void				h_closest_point_and_increment(t_ray *ray, t_cub *cub);
void				h_increment_until_wall(t_ray *ray, t_cub *cub);
void				v_closest_point_and_increment(t_ray *ray, t_cub *cub);
void				v_increment_until_wall(t_ray *ray, t_cub *cub);
void				init_ray(t_ray *ray, t_cub *cub);
double				distance_between_tow_points(double x1, double y1, double x2,
						double y2);
void				texture_drawing(t_strip *strip, t_cub *cub, int x0);
void				texture_cordonates_generation(t_strip *strip, t_ray *ray);
void				lenth_and_offset_calculations(t_strip *strip, t_ray *ray);
void				fish_eye_correction(t_ray *ray, t_cub *cub);
mlx_texture_t		*texture_selection(t_ray *ray, t_cub *cub);
void				horizontal_count_doors(t_ray *ray, t_cub *cub);

void				draw_pixel_map(uint32_t x, uint32_t y, t_cub *cub,
						uint32_t color);

void				free_data(t_cub *cub);
void				ft_init(t_cub *cub);
uint32_t			color_selection(t_strip *strip, uint32_t *text);
void				w_key(mlx_key_data_t keydata, t_cub *cub);
void				s_key(mlx_key_data_t keydata, t_cub *cub);
void				d_key(mlx_key_data_t keydata, t_cub *cub);
void				a_key(mlx_key_data_t keydata, t_cub *cub);
void				close_window(void *param);
void				escape_key(mlx_key_data_t keydata, t_cub *cub);
void				right_key(mlx_key_data_t keydata, t_cub *cub);
void				left_key(mlx_key_data_t keydata, t_cub *cub);
int					window_initialisation(t_cub *cub);
int					initialize_map(t_cub *cub, char *map_file);
int					initialize_textures(t_cub *cub);
int					write_error(int error_number);
int					ft_isempty_line(char *s);
int					check_color(char *s);
void				free_initialized_textures(t_cub *cub);

void				mouse_update(mouse_key_t but, action_t act,
						modifier_key_t mods, void *par);
int					is_in_open(t_cub *cub, double x, double y);
int					is_in_close(t_cub *cub, double x, double y);
void				draw_door(t_cub *cub);
int					out_of_limit_h(t_ray *ray, t_cub *cub);
int					out_of_limit_v(t_ray *ray, t_cub *cub);
void				shoot_door_ray(t_cub *cub);
void				cursor_update(double xpos, double ypos, void *param);
void				vertical_count_doors(t_ray *ray, t_cub *cub);
void				closed_door_change(t_cub *cub, t_ray ray);
void				opened_door_change(t_cub *cub, t_ray ray);
void				draw_sprite(t_cub *cub);
uint32_t			sprite_colors(uint32_t *text, int x, int y, int withd);
void				_free(char **array);

#endif
