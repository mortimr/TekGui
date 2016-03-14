/*
** display_cases_set_sec.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:50:45 2016 Iulian Rotaru
** Last update Mon Feb 29 12:29:52 2016 Iulian Rotaru
*/

#include "tekgui.h"

void			display_cases_set_sec(void **sender)
{
  t_bunny_position	*start;
  t_bunny_position	*dim;

  start = (t_bunny_position*)sender[2];
  dim = (t_bunny_position*)sender[3];
  start->x += 10;
  start->y = start->y + (dim->y - 26) / 2;
  dim->x = 26;
  dim->y = 26;
}

void			display_cases_set_final(void **sender, int i)
{
  t_tekgui		*tekgui;
  t_text		*text;
  t_bunny_position	*start;

  tekgui = (t_tekgui*)sender[1];
  text = (t_text*)sender[4];
  start = (t_bunny_position*)sender[2];
  tekgui->cases[i].real_pos.x = start->x;
  tekgui->cases[i].real_pos.y = start->y;
  text->x = 5;
  text->y = 7;
  text->police_size = 21;
  text->fg = tekgui->theme[tekgui->actu_theme - 1].text.full;
  text->pos.y = start->y;
  text->pos.x = start->x + 26 + 10;
}

void			display_cases_set(t_tekgui *tekgui,
					  t_bunny_pixelarray *pix,
					  int i)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  t_text		text;
  unsigned int		color;
  void			*sender[5];

  sender[0] = (void*)pix;
  sender[1] = (void*)tekgui;
  sender[2] = (void*)&start;
  sender[3] = (void*)&dim;
  sender[4] = (void*)&text;
  display_cases_set_frist(sender, &color, i);
  make_square_empty(pix, &start, &dim, color);
  display_cases_set_sec(sender);
  if (tekgui->cases[i].active == 0)
    make_square_empty(pix, &start, &dim, color);
  else
    make_square_cross(pix, &start, &dim, color);
  display_cases_set_final(sender, i);
  my_blitstr(tekgui->cases[i].name, pix, tekgui->font, &text);
}

void	display_cases_button(t_tekgui *tekgui,
			     t_bunny_pixelarray *pix)
{
  int	i;

  i = 0;
  while (i < tekgui->nb_cases)
    {
      display_cases_set(tekgui, pix, i);
      i++;
    }
}

void	tekgui_display_first(t_bunny_pixelarray *pix,
			     t_tekgui *tekgui)
{
  if (tekgui->disp == 1)
    {
      display_displayer(tekgui, pix);
      if (my_strlen(tekgui->displayer->bar.search) > 0)
	display_img_text(tekgui, pix);
    }
}
