/*
** display_exit_new.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:39:13 2016 Iulian Rotaru
** Last update Mon Feb 29 12:31:45 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	display_exit_new(t_text *text,
			 t_tekgui *tekgui,
			 t_bunny_position *dim,
			 t_bunny_position *start)
{
  text->pos.x = start->x +
    (tekgui->body.width / 7 - my_strlen("YES") * 21) / 2;
  text->pos.y = start->y + 21 / 2;
  tekgui->ex_button[0].x = start->x;
  tekgui->ex_button[0].y = start->y;
  tekgui->ex_size[0].x = dim->x;
  tekgui->ex_size[0].y = dim->y;
}

void	display_exit_box_end(t_bunny_position *start,
			     t_bunny_position *dim,
			     t_tekgui *tekgui,
			     t_text *text)
{
  start->x += tekgui->body.width / 7 * 2;
  tekgui->ex_button[1].x = start->x;
  tekgui->ex_button[1].y = start->y;
  tekgui->ex_size[1].x = dim->x;
  tekgui->ex_size[1].y = dim->y;
  text->pos.x = start->x +
    (tekgui->body.width / 7 - my_strlen("YES") * 21) / 2;

}

void		display_exit_box_core(t_tekgui *tekgui,
				      t_bunny_pixelarray *pix,
				      t_bunny_position *start,
				      t_bunny_position *dim)
{
  unsigned int	col;
  t_text	text;

  display_exit_box_pos_next(start, dim, tekgui, &col);
  make_square(pix, start, dim, col);
  display_exit_second_pos(start, dim, &col, tekgui);
  make_square(pix, start, dim, col);
  set_exit_message(&text, tekgui, dim, start);
  my_blitstr("Are you sure you want to exit ?", pix, tekgui->font, &text);
  display_exit_pos_again(start, dim, tekgui, &col);
  display_exit_new(&text, tekgui, dim, start);
  make_square(pix, start, dim, col);
  my_blitstr("YES", pix, tekgui->font, &text);
  display_exit_box_end(start, dim, tekgui, &text);
  make_square(pix, start, dim, col);
  my_blitstr("NO", pix, tekgui->font, &text);
}

void			display_exit_box(t_tekgui *tekgui,
					 t_bunny_pixelarray *pix,
					 int mode)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  static unsigned int	color;
  static char		fade;

  if (mode == 0)
    {
      color = 0;
      fade = 0;
    }
  else if (mode == 1)
    {
      display_exit_box_pos(&start, &dim, tekgui, pix);
      if (fade < 25)
	{
	  color += 0x06000000;
	  fade++;
	}
      make_square_transpa(pix, &start, &dim, color);
      display_exit_box_core(tekgui, pix, &start, &dim);
    }
}

int	load_menu_bmp(t_tekgui *tekgui)
{
  if ((tekgui->searcher[0] =
       load_bitmap("../textures/ask_menu.bmp")) == NULL)
    return (- 1);
  if ((tekgui->searcher[1] =
       load_bitmap("../textures/ask_menu_bis.bmp")) == NULL)
    return (- 1);
  return (0);
}
