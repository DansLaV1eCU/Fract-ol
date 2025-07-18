# Program name
NAME = libft.a

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

# Includes
INC = -I ./includes/

# libft sources
LIBFT_SRC_PATH	=	src/
LIBFT_SRC = 	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

# ft_printf sources
PRINTF_SRC_PATH = printf/
PRINTF_SRC = 	ft_printf.c \
				hex_low.c \
				hex_up.c \
				print_ptr.c \
				putnbr.c \
				put_uns_nbr.c \
				utilits.c

LIBFT_SRCS		= $(addprefix $(LIBFT_SRC_PATH), $(LIBFT_SRC))
PRINTF_SRCS		= $(addprefix $(PRINTF_SRC_PATH), $(PRINTF_SRC))

LIBFT_OBJ_PATH	= libft_obj/
LIBFT_OBJ		= $(LIBFT_SRC:.c=.o)
LIBFT_OBJS		= $(addprefix $(LIBFT_OBJ_PATH), $(LIBFT_OBJ))

PRINTF_OBJ_PATH	= printf_obj/
PRINTF_OBJ		= $(PRINTF_SRC:.c=.o)
PRINTF_OBJS		= $(addprefix $(PRINTF_OBJ_PATH), $(PRINTF_OBJ))

all: $(NAME)

$(LIBFT_OBJ_PATH)%.o: $(LIBFT_SRC_PATH)%.c | $(LIBFT_OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT_OBJ_PATH):
	@mkdir $(LIBFT_OBJ_PATH)


$(PRINTF_OBJ_PATH)%.o: $(PRINTF_SRC_PATH)%.c | $(PRINTF_OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(PRINTF_OBJ_PATH):
	@mkdir $(PRINTF_OBJ_PATH)

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS)
	@$(AR) $(NAME)  $^

clean:
	@rm -rf $(LIBFT_OBJ_PATH)
	@rm -rf $(PRINTF_OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re