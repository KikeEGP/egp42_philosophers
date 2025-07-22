# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 10:52:16 by enrgil-p          #+#    #+#              #
#    Updated: 2025/07/22 11:10:24 by enrgil-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =
SOURCES =

#libft forbidden in this project
OBJECTS = $(SOURCES:.c=.o)

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
SANIT_FLAG = -fsanitize=address
PTHREAD_FLAG = -pthread
