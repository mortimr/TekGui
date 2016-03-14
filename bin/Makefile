##
## Makefile for makefile in /home/rotaru_i/line_sender/lib/line_sender
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Wed Jan 27 23:34:11 2016 Iulian Rotaru
## Last update Sun Feb 28 14:02:46 2016 Iulian Rotaru
##

CC	= gcc

CFLAGS	+= -I../inc                        \
	   -I/home/${USER}/.froot/include \
	   -L/home/${USER}/.froot/lib     \
	   -L../lib -ltekgui               \
	   -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
	   -rdynamic \
	   -Wextra -Wall -Werror

LAPIN	= -I../inc                        \
	   -I/home/${USER}/.froot/include \
	   -L/home/${USER}/.froot/lib     \
	   -L../lib -ltekgui               \
	   -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
	   -rdynamic \
	   -Wextra -Wall -Werror

RM	= rm -rf

NAME	= tekgui

SRCS	= main.c

OBJ	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../lib/tekgui re
	$(CC) -o $(NAME) $(OBJ) $(LAPIN)

clean:
	$(RM) $(OBJ)
	make -C ../lib/tekgui clean

cclean:
	$(RM) $(OBJ)

fcclean: cclean
	$(RM) $(NAME)

fclean: cclean
	$(RM) $(NAME)
	make -C ../lib/tekgui fclean

relib:
	make -C ../lib/tekgui

re: fcclean all

.PHONY: all clean fclean re

