/*
** display_body_next.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:29:57 2016 Iulian Rotaru
** Last update Mon Feb 29 12:29:26 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	display_body_next(t_tekgui *tekgui,
			  t_bunny_position *start,
			  t_bunny_position *dim,
			  t_bunny_pixelarray *pix)
{
  start->x = (pix->clipable.clip_width - tekgui->body.width) / 2;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2;
  dim->x = tekgui->body.width;
  dim->y = tekgui->body.height;
}

void	display_body_next_next(t_tekgui *tekgui,
			       t_bunny_position *start,
			       t_bunny_position *dim,
			       t_bunny_pixelarray *pix)
{
  (void)pix;
  start->x = start->x + tekgui->body.exit[0].x + tekgui->body.width;
  dim->y = tekgui->body.exit[1].y;
  start->y = start->y - tekgui->body.exit[0].y - dim->y;
  dim->x = tekgui->body.exit[1].x;
}

void	display_body_text(t_tekgui *tekgui,
			  t_text *text,
			  t_bunny_pixelarray *pix)
{
  text->x = 5;
  text->y = 7;
  text->police_size = 28;
  text->fg = tekgui->theme[tekgui->actu_theme - 1].text.full;
  text->pos.y = (pix->clipable.clip_height - tekgui->body.height)
    / 2 + (50 - text->police_size / 7 * 7) / 2;
  text->pos.x = (pix->clipable.clip_width - tekgui->body.width)
    / 2 + (tekgui->body.width / 2) - ((my_strlen(tekgui->body.title) / 2)
				      * (6 * text->police_size / 7));
}

void	display_body_text_next(t_tekgui *tekgui,
			       t_text *text,
			       t_bunny_pixelarray *pix,
			       t_bunny_position *start)
{
  (void)pix;
  text->police_size = 35;
  text->fg = BLACK;
  text->pos.y = start->y + (tekgui->body.exit[1].y + tekgui->body.exit[0].y);
  text->pos.x = start->x + (tekgui->body.exit[1].x - text->police_size / 7 * 6)
    / 2;
}

void		display_faded_theme(int *fade,
				    t_text *text,
				    t_bunny_pixelarray *pix,
				    t_tekgui *tekgui)
{
  t_color	tmp;

  text->pos.y = 0;
  text->pos.x = 0;
  tmp.full = tekgui->theme[tekgui->actu_theme - 1].one.full;
  if (*fade < 50)
    tmp.argb[3] = tekgui->theme[tekgui->actu_theme - 1].one.argb[3];
  else
    tmp.argb[3] = tekgui->theme[tekgui->actu_theme - 1].one.argb[3]
      - (((*fade - 50) / 25.0) *
	 tekgui->theme[tekgui->actu_theme - 1].one.argb[3]);
  text->fg = tmp.full;
  if (*fade < 75)
    {
      my_blitstr(tekgui->theme[tekgui->actu_theme - 1].name,
		 pix, tekgui->font, text);
      *fade += 1;
    }
}
