/*
** ani_play.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:26:45 2016 Iulian Rotaru
** Last update Mon Feb 29 12:23:06 2016 Iulian Rotaru
*/

#include "tekgui.h"

void		ani_play(t_tekgui *tekgui)
{
  t_text	text;
  static int	call;
  static int	increm;

  if (tekgui->animation == 1)
    {
      if (call == 0)
	{
	  call = 1;
	  tekgui->on = 5;
	}
      if (tekgui->ani->epileptic == 1)
	{
	  fill_pix(tekgui->pix, rand() | BLACK);
	  text.fg = rand() | BLACK;
	}
      else
	ani_play_else(&text, tekgui);
      ani_play_core(&text, &call, &increm, tekgui);
    }
}

unsigned int	invert_colors(unsigned int one, unsigned int two)
{
  t_color	colors[3];

  colors[0].full = one;
  colors[1].full = two;
  colors[2].argb[3] = 0xFF;
  colors[2].argb[2] = colors[0].argb[2] - colors[1].argb[2];
  colors[2].argb[1] = colors[0].argb[1] - colors[1].argb[1];
  colors[2].argb[0] = colors[0].argb[0] - colors[1].argb[0];
  return (colors[2].full);
}

void	area_preview_ani_setup(t_tekgui *tekgui,
			       t_area *area,
			       t_bunny_position *dim,
			       t_bunny_position *start)
{
  start->x = (tekgui->pix->clipable.clip_width -
	      tekgui->body.width) / 2 + area->pos.x + 5;
  start->y = (tekgui->pix->clipable.clip_height -
	      tekgui->body.height) / 2 + area->pos.y + 5;
  area->real_pos.x = start->x;
  area->real_pos.y = start->y;
  dim->x = area->dim.x - 10;
  dim->y = area->dim.y - 10;
  area->real_dim.x = dim->x;
  area->real_dim.y = dim->y;
}

void	area_preview_ani_colors(t_tekgui *tekgui,
				unsigned int *color,
				t_text *text)
{
  if (tekgui->ani->epileptic == 1)
    {
      *color = rand() | BLACK;
      text->fg = rand() | BLACK;
    }
  else
    {
      if (tekgui->ani->invert == 1)
	{
	  *color = invert_colors(WHITE, tekgui->ani->bg);
	  text->fg = invert_colors(WHITE, tekgui->ani->fg);
	}
      else
	{
	  *color = tekgui->ani->bg;
	  text->fg = tekgui->ani->fg;
	}
    }
}

void			area_preview_ani(t_tekgui *tekgui, t_area *area)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  unsigned int		color;
  t_text		text;

  if (tekgui->animation == 1)
    {
      area_preview_ani_setup(tekgui, area, &dim, &start);
      area_preview_ani_colors(tekgui, &color, &text);
      make_square(tekgui->pix, &start, &dim, color);
      text.x = 5;
      text.y = 7;
      text.police_size = tekgui->ani->police / 2;
      text.pos.x = start.x +
	(dim.x - my_strlen(tekgui->ani->text) *
	 (text.police_size / 7) * 6) / 2.0;
      text.pos.y = start.y + (dim.y - 14) / 2.0;
      my_blitstr(tekgui->ani->text, tekgui->pix, tekgui->font, &text);
    }
}
