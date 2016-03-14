##
## Makefile for tekgui in /home/rotaru_i/Coding/Liblap/gfx_tekgui
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Wed Feb 24 12:54:20 2016 Iulian Rotaru
## Last update Wed Feb 24 12:55:15 2016 Iulian Rotaru
##

all:
	make -C ./lib/tekgui

clean:
	make -C ./lib/tekgui clean

fclean:
	make -C ./lib/tekgui fclean

re:
	make -C ./lib/tekgui re

.PHONY: all clean fclean re
