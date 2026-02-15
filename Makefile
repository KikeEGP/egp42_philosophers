# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 10:52:16 by enrgil-p          #+#    #+#              #
#    Updated: 2026/02/15 19:19:58 by enrgil-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES =	main.c utils.c parse.c create_symposium.c\
		mutex_init_and_destroy.c philos_create_and_destroy.c\
		clean_functions.c threads_routines.c routines_utils.c\
		time_manage.c

#libft forbidden in this project

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3
SANIT_FLAG = -fsanitize=address
PTHREAD_FLAG = -pthread

CC = cc
RM = rm -f


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(PTHREAD_FLAG) $(OBJECTS) -o $(NAME)
	$(info CREATED $(NAME))

fsanitize: $(NAME)
	$(CC) $(CFLAGS) $(SANIT_FLAG) $(PTHREAD_FLAG) $(OBJECTS) -o $(NAME)
	$(info CREATED $(NAME) WITH FSANITIZE)

clean:
	$(RM) $(OBJECTS)
	$(info REMOVED OBJECTS)

compclean: all clean

fclean: clean
	$(RM) $(NAME)
	$(info REMOVED $(NAME)) 

re: fclean all

.PHONY: all clean fclean re fsanitize compclean
