CC = cc
CFLAGS = -Werror -Wall -Wextra
INCLUDES = includes/cub3d.h
NAME = cub3D
BONUS = cub3D_bonus

BSRCS = bonus/controls/angle_keys.c \
	bonus/controls/door_rays_horizental.c \
	bonus/controls/door_rays_vertical.c \
	bonus/controls/door_utils.c \
	bonus/controls/exit_keys.c \
	bonus/controls/keys.c \
	bonus/controls/mouse.c \
	bonus/controls/movement_keys.c \
	bonus/parser/check_colors.c \
	bonus/parser/check_map.c \
	bonus/parser/initialize_textures.c \
	bonus/parser/parse_map.c \
	bonus/parser/parse_textures.c \
	bonus/parser/read_map.c \
	bonus/raycaster/horizontal.c \
	bonus/raycaster/ray_count.c \
	bonus/raycaster/ray_utils.c \
	bonus/raycaster/vertical.c \
	bonus/raycaster/wall_calculations.c \
	bonus/rendrer/basic_drawing.c \
	bonus/rendrer/calculations_utils.c \
	bonus/rendrer/draw_map.c \
	bonus/rendrer/ft_init.c \
	bonus/rendrer/get_direction.c \
	bonus/rendrer/main.c \
	bonus/rendrer/sprites.c \
	bonus/utils/_free.c \
	bonus/utils/ft_atoi.c \
	bonus/utils/ft_isempty_line.c \
	bonus/utils/ft_joinstr.c \
	bonus/utils/ft_split.c \
	bonus/utils/ft_strdup.c \
	bonus/utils/ft_strncmp.c \
	bonus/utils/get_next_line.c \
	bonus/utils/get_next_line_utils.c \
	bonus/utils/write_error.c 

BOBJS = $(BSRCS:.c=.o)

SRCS = srcs/controls/angle_keys.c \
	srcs/controls/exit_keys.c \
	srcs/controls/keys.c \
	srcs/controls/movement_keys.c \
	srcs/parser/check_colors.c \
	srcs/parser/check_map.c \
	srcs/parser/initialize_textures.c \
	srcs/parser/parse_map.c \
	srcs/parser/parse_textures.c \
	srcs/parser/read_map.c \
	srcs/raycaster/horizontal.c \
	srcs/raycaster/ray_count.c \
	srcs/raycaster/vertical.c \
	srcs/raycaster/wall_calculations.c \
	srcs/rendrer/basic_drawing.c \
	srcs/rendrer/calculations_utils.c \
	srcs/rendrer/draw_map.c \
	srcs/rendrer/ft_init.c \
	srcs/rendrer/get_direction.c \
	srcs/rendrer/main.c \
	srcs/utils/_free.c \
	srcs/utils/ft_atoi.c \
	srcs/utils/ft_isempty_line.c \
	srcs/utils/ft_joinstr.c \
	srcs/utils/ft_split.c \
	srcs/utils/ft_strdup.c \
	srcs/utils/ft_strncmp.c \
	srcs/utils/get_next_line.c \
	srcs/utils/get_next_line_utils.c \
	srcs/utils/write_error.c

OBJS = $(SRCS:.c=.o)


GLFW	= $(shell brew  --prefix glfw)
MINI_LIBX = ./MLX42/build/libmlx42.a
INC_MLX := ./MLX42/include
MINI_LIBX_DEPS = $(MINI_LIBX) -framework Cocoa -framework OpenGL -framework IOKit

all:  $(NAME)
$(NAME): $(OBJS) $(INCLUDES) $(MINI_LIBX)
	@$(CC) $(CFLAGS)  -o $(NAME) $(OBJS) $(MINI_LIBX_DEPS) -lglfw -L"$(GLFW)/lib"
	@echo "\033[1;32m ----Mandatory created----- \033[0m"

srcs/%.o: srcs/%.c $(INCLUDES)
	@$(CC) $(CFLAGS)  -I $(INCLUDES) -I $(INC_MLX) -c $< -o $@
	@echo "\033[1;33m $@ created \033[0m"

bonus: $(BONUS)
$(BONUS): $(BOBJS) $(INCLUDES) $(MINI_LIBX)
	@$(CC) $(CFLAGS)  -o $(BONUS) $(BOBJS) $(MINI_LIBX_DEPS) -lglfw -L"$(GLFW)/lib"
	@echo "\033[1;32m ----Bonus created----- \033[0m"
bonus/%.o: bonus/%.c $(INCLUDES)
	@$(CC) $(CFLAGS)  -I $(INCLUDES) -I $(INC_MLX) -c $< -o $@
	@echo "\033[1;33m $@ created \033[0m"

$(MINI_LIBX):
	@cmake ./MLX42 -B ./MLX42/build
	@make -C ./MLX42/build -j4
	@echo "\033[1;35m ----Minlibx compiled---- \033[0m"


fcleanlib:
	@rm -rf MLX42/build
	@echo "\033[1;35m ----Library Cleaned-----\033[0m"

clean:
	@rm -rf $(OBJS) $(BOBJS)
	@echo "\033[1;33m ----Objects Cleaned-----\033[0m"


fclean: clean
	@rm -rf $(NAME) $(BONUS)
	@echo "\033[1;31m ----Project Cleaned-----\033[0m"

re:  fclean all
bre: fclean bonus
.PHONY: all re clean fclean bonus fcleanlib bre