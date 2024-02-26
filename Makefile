NAME= pipex.a
SRC= ./srcs/search_path.c ./srcs/utils.c ./pipex.c \
	./srcs/ft_split.c ./srcs/ft_strchr.c ./srcs/ft_strlen.c \
	./srcs/ft_strlcpy.c ./srcs/ft_putstr_fd.c ./srcs/ft_putendl_fd.c \
	./srcs/ft_putchar_fd.c ./srcs/ft_strlcat.c ./srcs/ft_strjoin.c ./srcs/ft_strncmp.c

FLAGS= gcc -Wextra -Werror -Wall
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)

$(NAME):	$(OBJ)
	@clear
	@echo "\n\033[33m"****************\\nCompiling... Patience is a virtue!\\n🛠️⏳😊\\n****************\\n"\033[0m\n"
# @make -sC ./libft/
# @make bonus -sC ./libft/
# @cp libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@clear
	@echo "\n\033[32m"****************\\nCongratulations! Everything compiles!\\n🎉🚀😄\\n****************\\n"\033[0m\n"
	@$(FLAGS) $(SRC) -o pipex

all: $(NAME)

clean:
	@clear
	@echo "\n\033[31m"--------------\\n¡Oops! Archivos eliminados...\\n¡Pero aún estamos bien!\\n------------------\\n"\033[0m\n"
	@rm -f $(OBJ)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf pipex

re: fclean all

.PHONY: all clean re 