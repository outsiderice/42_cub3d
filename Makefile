NAME    := cub3d
CC      := cc
CFLAGS  := -Wextra -Wall -Werror -Wunreachable-code
LIBMLX  := ./lib/MLX42
LIBFT   := ./lib/libft

HEADERS := -I ./inc -I $(LIBMLX)/include -I $(LIBFT)
LIBS    := $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
SRCS    := src/fill_map.c src/get_next_line.c src/parse.c src/pre_map_parse.c src/map_parse.c \
           src/utils_parse.c src/utils_parse_2.c src/parse_main.c src/game.c src/input.c src/raycast.c \
           src/movements.c src/assets.c src/textures.c src/init_cub.c src/raycast_utils.c

OBJDIR  := .obj
OBJS    := $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS    := $(OBJS:.o=.d)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

$(OBJDIR)/%.o: %.c Makefile| $(OBJDIR)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(OBJDIR):
	@mkdir -p $(OBJDIR)/src

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFT)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libmlx libft

