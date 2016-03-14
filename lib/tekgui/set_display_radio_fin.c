/*
** set_display_radio_fin.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:49:36 2016 Iulian Rotaru
** Last update Mon Feb 29 20:40:14 2016 Iulian Rotaru
*/

#include "tekgui.h"

void			set_display_radio_fin(void **sender, int i)
{
  t_tekgui		*tekgui;
  t_bunny_position	*start;
  t_bunny_position	*dim;
  t_bunny_pixelarray	*pix;

  dim = (t_bunny_position*)sender[3];
  pix = (t_bunny_pixelarray*)sender[0];
  start = (t_bunny_position*)sender[2];
  tekgui = (t_tekgui*)sender[1];
  start->x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->radio[i].pos.x;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->radio[i].pos.y;
  dim->x = tekgui->radio[i].dim.x;
  dim->y = tekgui->radio[i].dim.y;
}

void			disp_rad_final(void **sender, int i)
{
  t_tekgui		*tekgui;
  t_bunny_position	*start;
  t_bunny_position	*dim;
  t_bunny_pixelarray	*pix;
  int			*j;
  unsigned int		color;

  dim = (t_bunny_position*)sender[3];
  pix = (t_bunny_pixelarray*)sender[0];
  start = (t_bunny_position*)sender[2];
  j = (int*)sender[5];
  tekgui = (t_tekgui*)sender[1];
  *j = 0;
  while (*j < tekgui->radio[i].nb_butt)
    {
      dim->y += tekgui->radio[i].butt_dim[*j].y;
      *j += 1;
    }
  color = BLACK;
  make_square_empty(pix, start, dim, color);
}

void			display_radio_set(t_tekgui *tekgui,
					  t_bunny_pixelarray *pix,
					  int i)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  unsigned int		color;
  t_text		text;
  int			j;
  void			*sender[6];

  sender[0] = (void*)pix;
  sender[1] = (void*)tekgui;
  sender[2] = (void*)&start;
  sender[3] = (void*)&dim;
  sender[4] = (void*)&text;
  sender[5] = (void*)&j;
  display_radio_first(sender, i, &color);
  make_square(pix, &start, &dim, color);
  display_radio_sec(sender, i);
  my_blitstr(tekgui->radio[i].title, pix, tekgui->font, &text);
  display_radio_boucle(sender, i);
  set_display_radio_fin(sender, i);
  disp_rad_final(sender, i);
}

void	display_radio_button(t_tekgui *tekgui,
			     t_bunny_pixelarray *pix)
{
  int	i;

  i = 0;
  while (i < tekgui->nb_radio)
    {
      display_radio_set(tekgui, pix, i);
      i++;
    }
}

void			display_cases_set_frist(void **sender,
						unsigned int *color,
						int i)
{
  t_bunny_position	*start;
  t_bunny_position	*dim;
  t_bunny_pixelarray	*pix;
  t_tekgui		*tekgui;

  pix = (t_bunny_pixelarray*)sender[0];
  tekgui = (t_tekgui*)sender[1];
  start = (t_bunny_position*)sender[2];
  dim = (t_bunny_position*)sender[3];
  start->x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->cases[i].pos.x;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->cases[i].pos.y;
  dim->x = tekgui->cases[i].dim.x;
  dim->y = tekgui->cases[i].dim.y;
  *color = BLACK;
}
