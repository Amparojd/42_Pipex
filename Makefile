# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 19:46:44 by marvin            #+#    #+#              #
#    Updated: 2024/02/29 21:29:05 by ampjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex
SRC_DIR = ./src
SRC= search_path.c utils.c pipex.c

OBJS = $(addprefix $(SRC_DIR)/,  $(SRC:.c=.o))

CC = gcc
CFLAGS= -Wall -Wextra -Werror
AR = ar
ARGFAGS = rcs
RM = rm -rf

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)


all: $(NAME)
$(NAME):	$(OBJS)
	@clear
	@echo "\n\033[33m"🛠️⏳ Compiling... Patience is a virtue! 😊⏳🛠️"\033[0m"
	@sleep 3
	@make -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@clear
	@echo "\n\033[32m"✨🎉 Compilation successful! All set to go! 🚀✨"\033[0m\n"

	

clean:
	@clear
	$(RM) $(OBJS) $(LIBFT_A)
	@clear
	@echo "\n\033[34m"🧹🧽 Cleaning up... Bye-bye, files! 📂👋"\033[0m\n"
	@sleep 2
	

fclean: clean
		$(RM) $(NAME) $(OBJS)
		make -C $(LIBFT_DIR) fclean

re: fclean all
	@make all

.PHONY: all clean fclean re 