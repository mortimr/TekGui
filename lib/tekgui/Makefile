##
## Makefile for tekgui in /home/rotaru_i
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Tue Feb  2 18:05:04 2016 Iulian Rotaru
## Last update Mon Feb 29 20:36:37 2016 Iulian Rotaru
##

CC	= gcc

LIB	= ar rcv

CFLAGS	+= -I../../inc                    	\
	   -I/home/${USER}/.froot/include 	\
	   -L/home/${USER}/.froot/lib     	\
	   -llapin -lsfml-audio			\
	   -lsfml-graphics			\
	   -lsfml-window			\
	   -lsfml-system			\
	   -lstdc++ -ldl -lm 			\
	   -rdynamic 				\
	   -Wall -Wextra -Werror

RM	= rm -rf

NAME	= libtekgui.a

SRCS	= loader.c 				\
	  typing.c				\
	  tekline.c 				\
	  read_bmp.c 				\
	  ani_play.c 				\
	  fade_body.c 				\
	  load_body.c 				\
	  multi_key.c				\
	  my_getnbr.c 				\
	  load_case.c 				\
	  gui_click.c 				\
	  my_blitstr.c 				\
	  fill_button.c 			\
	  make_square.c 			\
	  color_mixer.c 			\
	  get_base_nb.c				\
	  tek_area_fct.c			\
	  display_body.c 			\
	  my_strcmp_end.c 			\
	  ani_police_up.c 			\
	  my_bunny_blit.c 			\
	  loop_next_next.c			\
	  read_one_color.c 			\
	  display_tekgui.c 			\
	  alloc_the_butt.c 			\
	  ani_rand_color.c 			\
	  my_strcmp_start.c 			\
	  default_theming.c 			\
	  display_exit_new.c 			\
	  live_load_boucle.c 			\
	  disp_clear_search.c 			\
	  check_disp_select.c 			\
	  display_body_next.c 			\
	  background_manager.c 			\
	  get_exit_body_next.c 			\
	  ../../tcore/tektext.c 		\
	  fill_area_next_next.c 		\
	  fill_text_next_next.c 		\
	  display_radio_first.c 		\
	  ../../tcore/tekpixel.c 		\
	  display_exit_box_pos.c 		\
	  fill_radio_next_next.c 		\
	  set_single_text_buff.c 		\
	  fill_displayer_barpos.c 		\
	  set_dispbar_name_else.c 		\
	  get_selection_dispbar.c 		\
	  single_area_displayer.c 		\
	  set_display_radio_fin.c 		\
	  display_cases_set_sec.c 		\
	  get_displayer_data_next.c 		\
	  ../../tcore/tekfunction.c 		\
	  fill_cases_next_next_next.c

OBJ	= $(SRCS:.c=.o)

all: $(NAME)
	@echo -e "\033[3;34m"
	@echo -e "//=========================\\\\\\\\\n||=========================||\n||Done building libtekgui.a||\n||=========================||\n\\\\\\\\=========================//"
	@echo -e " \033[0m"

$(NAME): $(OBJ)
	$(LIB) -o $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ..

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
