# Compiler
NAME			= fractol
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

# Libs
LIBFT_DIR		= includes/libft
LIBFT			= $(LIBFT_DIR)/libft.a
LINKER  	    = -lft -L $(LIBFT_DIR)

# Includes
INCLUDES_DIR 	= includes
INCLUDES_FLAG 	= -I$(INCLUDES_DIR) \
				  -I$(LIBFT_DIR) \

INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) \
				  $(LIBFT_DIR)/includes/libft.h \

# Sources
SRCS_DIR		= srcs/
SRC_FILES		= main.c \
				  fractals.c \
				  utils_1.c \
				  utils_2.c \
			 	  utils_3.c \

SRCS			= $(addprefix $(SRCS_DIR), $(SRC_FILES))

# Objects
OBJS_DIR		= objs/
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

MLX_DIR			= includes/minilibx-linux
MLX				= $(MLX_DIR)/libmlx.a
LINKER			+= -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
INCLUDES_FLAG	+= -I$(MLX_DIR)

all : $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(LIBFT) :
	$(MAKE) $(LIBFT_DIR)

$(MLX) :
	$(MAKE) $(MLX_DIR)

$(OBJS_DIR) :
	$(MKDIR) $(OBJS_DIR)

$(NAME) : $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) $(MLX_DIR) clean
	$(MAKE) $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re