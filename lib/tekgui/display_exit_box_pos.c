/*
** display_exit_box_pos.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:38:20 2016 Iulian Rotaru
** Last update Fri Feb 26 15:06:37 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	display_exit_box_pos(t_bunny_position *start,
			     t_bunny_position *dim,
			     t_tekgui *tekgui,
			     t_bunny_pixelarray *pix)
{
  start->x = (pix->clipable.clip_width - tekgui->body.width) / 2;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2;
  dim->x = tekgui->body.width;
  dim->y = tekgui->body.height;
}

void	display_exit_box_pos_next(t_bunny_position *start,
				  t_bunny_position *dim,
				  t_tekgui *tekgui,
				  unsigned int *col)
{
  start->x = start->x + dim->x / 4;
  start->y = start->y + dim->y / 4;
  dim->x = tekgui->body.width / 2;
  dim->y = tekgui->body.height / 2;
  *col = tekgui->theme[tekgui->actu_theme - 1].one.full;
}

void	display_exit_second_pos(t_bunny_position *start,
				t_bunny_position *dim,
				unsigned int *col,
				t_tekgui *tekgui)
{
  start->x = start->x + 2;
  start->y = start->y + 2;
  dim->x = tekgui->body.width / 2 - 4;
  dim->y = tekgui->body.height / 2 - 4;
  *col = tekgui->theme[tekgui->actu_theme - 1].two.full;
}

void	set_exit_message(t_text *text,
			 t_tekgui *tekgui,
			 t_bunny_position *dim,
			 t_bunny_position *start)
{
  text->x = 5;
  text->y = 7;
  text->police_size = 21;
  text->fg = tekgui->theme[tekgui->actu_theme - 1].text.full;
  text->pos.x = start->x +
    (dim->x - (my_strlen("Are you sure you want to exit ?") - 1) * 21) / 2;
  text->pos.y = start->y + (dim->y + 7 * 4) / 2 - dim->y / 5;
}

void	display_exit_pos_again(t_bunny_position *start,
			       t_bunny_position *dim,
			       t_tekgui *tekgui,
			       unsigned int *col)
{
  start->x = tekgui->body.width / 4 + tekgui->body.width / 7;
  start->y = start->y +
    (dim->y + 7 * 4) / 2 - dim->y / 5 + tekgui->body.height / 5;
  dim->x = tekgui->body.width / 7;
  dim->y = tekgui->body.height / 2 / 10;
  *col = tekgui->theme[tekgui->actu_theme - 1].one.full;
}
