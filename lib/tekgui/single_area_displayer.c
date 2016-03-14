/*
** single_area_displayer.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:45:56 2016 Iulian Rotaru
** Last update Mon Feb 29 20:40:45 2016 Iulian Rotaru
*/

#include "tekgui.h"

void			single_area_displayer(t_tekgui *tekgui,
					      t_area *area,
					      t_bunny_pixelarray *pix)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  unsigned int		color;

  start.x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + area->pos.x;
  start.y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + area->pos.y;
  dim.x = area->dim.x;
  dim.y = area->dim.y;
  color = tekgui->theme[tekgui->actu_theme - 1].two.full;
  make_square(pix, &start, &dim, color);
}

void	display_area(t_tekgui *tekgui,
		     t_bunny_pixelarray *pix)
{
  int	i;

  i = 0;
  while (i < tekgui->nb_areas)
    {
      single_area_displayer(tekgui, &tekgui->area[i], pix);
      i++;
    }
}

void			set_single_text_first(void **sender,
					      int x,
					      unsigned int *color)
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	*start;
  t_bunny_position	*dim;
  t_tekgui		*tekgui;

  pix = (t_bunny_pixelarray*)sender[0];
  tekgui = (t_tekgui*)sender[1];
  dim = (t_bunny_position*)sender[2];
  start = (t_bunny_position*)sender[3];
  start->x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->texter[x].pos.x;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->texter[x].pos.y;
  dim->x = tekgui->texter[x].dim.x;
  dim->y = tekgui->texter[x].dim.y;
  *color = color_mixer(tekgui->theme[tekgui->actu_theme - 1].two.full,
		       0x33000000);
}

void			set_single_text_sec(void **sender,
					    int x,
					    unsigned int *color)
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	*start;
  t_bunny_position	*dim;
  t_tekgui		*tekgui;

  pix = (t_bunny_pixelarray*)sender[0];
  tekgui = (t_tekgui*)sender[1];
  dim = (t_bunny_position*)sender[2];
  start = (t_bunny_position*)sender[3];
  start->x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->texter[x].pos.x + 2;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->texter[x].pos.y + 2;
  dim->x = tekgui->texter[x].dim.x - 4;
  dim->y = tekgui->texter[x].dim.y - 4;
  if (x == tekgui->focus_text)
    *color = color_mixer(tekgui->theme[tekgui->actu_theme - 1].two.full,
			 0x77FFFFFF);
  else
    *color = color_mixer(tekgui->theme[tekgui->actu_theme - 1].two.full,
			 0x33FFFFFF);
}

void			set_single_text_third(void **sender)
{
  t_text		*text;
  t_tekgui		*tekgui;
  t_bunny_position	*start;

  text = (t_text*)sender[4];
  tekgui = (t_tekgui*)sender[1];
  start = (t_bunny_position*)sender[3];
  text->x = 5;
  text->y = 7;
  text->police_size = 21;
  text->pos.x = start->x + 2;
  text->pos.y = start->y + 4;
  text->fg = color_mixer(tekgui->theme[tekgui->actu_theme - 1].text.full,
			 0xAA000000);
}
