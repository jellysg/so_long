# character
OBJS_CHAR = $(SRC_CHAR:.c=.o)
SRC_CHAR = $(addprefix $(SRC_DIR)/char/, \
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c \
)

# linked list
OBJS_LST = $(SRC_LST:.c=.o)
SRC_LST	= $(addprefix $(SRC_DIR)/lst/, \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
)

# memory
OBJS_MEM = $(SRC_MEM:.c=.o)
SRC_MEM	= $(addprefix $(SRC_DIR)/mem/, \
ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c \
)

# conversion
OBJS_CONV = $(SRC_CONV:.c=.o)
SRC_CONV = $(addprefix $(SRC_DIR)/conv/, \
ft_atoi.c ft_itoa.c \
)

# character string
OBJS_STR = $(SRC_STR:.c=.o)
SRC_STR	= $(addprefix $(SRC_DIR)/str/, \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
)

# file descriptor
OBJS_PUT = $(SRC_PUT:.c=.o)
SRC_PUT	= $(addprefix $(SRC_DIR)/put/, \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
)

# printf
OBJS_PRINTF = $(SRC_PRINTF:.c=.o)
SRC_PRINTF = $(addprefix $(SRC_DIR)/printf/, \
ft_printf.c ft_putaddress.c ft_putalnum.c ft_puthex.c ft_putstr.c \
)

# get next line
OBJS_GNL = $(SRC_GNL:.c=.o)
SRC_GNL	= $(addprefix $(SRC_DIR)/gnl/, \
get_next_line.c get_next_line_utils.c \
)

SRC_DIR	= .
INC_DIR	= ./includes/
CC = gcc
AR = ar
MF = Makefile
FLAGS = -Wall -Wextra -Werror

NAME = libft.a
HEADER	= $(INC_DIR)/libft.h

all : $(NAME)

$(NAME) : $(MF) $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL)
	@$(AR) -rcs $(NAME) $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL)
	@echo ""
	@printf "\033[1;34m%s\033[0m\n" "[libft] Compiled successfully."

clean:
	@rm -f $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL) $(OBJS_TEST) $(OBJS_UTEST)
	@printf "\033[1;31m%s\033[0m\n" "[libft] Object files cleaned."

fclean : clean
	@rm -f $(NAME)
	@printf "\033[1;31m%s\033[0m\n" "[libft] Cleaned successfully."

re: fclean all

%.o : %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@  -I $(INC_DIR)
	@printf "\033[1;34m|\033[0m"

.PHONY: all clean fclean re