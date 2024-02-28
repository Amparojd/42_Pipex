NAME= pipex.a
SRC= ./srcs/search_path.c ./srcs/utils.c ./pipex.c \
	./srcs/ft_split.c ./srcs/ft_strchr.c ./srcs/ft_strlen.c \
	./srcs/ft_strlcpy.c \
	./srcs/string_output.c ./srcs/ft_strlcat.c ./srcs/ft_strjoin.c ./srcs/ft_strncmp.c

FLAGS= gcc -Wextra -Werror -Wall
OBJ=$(SRC:.c=.o)

$(NAME):	$(OBJ)
	@clear
	@echo "\n\033[33m"🛠️⏳ Compiling... Patience is a virtue! 😊⏳🛠️"\033[0m"
	@sleep 3
	@ar -rc $(NAME) $(OBJ)
	@clear
	@echo "\n\033[32m"✨🎉 Compilation successful! All set to go! 🚀✨"\033[0m\n"
	@$(FLAGS) $(SRC) -o pipex

all: $(NAME)

clean:
	@clear
	@echo "\n\033[34m"🧹🧽 Cleaning up... Bye-bye, files! 📂👋"\033[0m\n"
	@rm -f $(OBJ)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf pipex

re: fclean all

.PHONY: all clean fclean re 