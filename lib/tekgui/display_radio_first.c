/*
** display_radio_first.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:48:04 2016 Iulian Rotaru
** Last update Mon Feb 29 20:29:55 2016 Iulian Rotaru
*/

#include "tekgui.h"

void			display_radio_first(void **sender,
					    int i,
					    unsigned int *color)
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
    + tekgui->radio[i].pos.x;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->radio[i].pos.y;
  dim->x = tekgui->radio[i].dim.x;
  dim->y = tekgui->radio[i].dim.y;
  *color = color_mixer(tekgui->theme[tekgui->actu_theme - 1].one.full,
		       0x66000000);
}

void			display_radio_sec(void **sender, int i)
{
  t_tekgui		*tekgui;
  t_bunny_position	*start;
  t_text		*text;
  t_bunny_position	*dim;

  tekgui = (t_tekgui*)sender[1];
  start = (t_bunny_position*)sender[2];
  dim = (t_bunny_position*)sender[3];
  text = (t_text*)sender[4];
  text->x = 5;
  text->y = 7;
  text->fg = tekgui->theme[tekgui->actu_theme - 1].text.full;
  text->police_size = 21;
  text->pos.x = start->x + (dim->x - my_strlen(tekgui->radio[i].title) * 3 * 5)
    / 2;
  text->pos.y = start->y + (dim->y - 21) / 2;
}

void			set_circle_radio(void **sender,
					 double *radius,
					 int i,
					 unsigned int *color)
{
  t_tekgui		*tekgui;
  t_bunny_position	*start;
  int			*j;
  t_bunny_pixelarray	*pix;

  pix = (t_bunny_pixelarray*)sender[0];
  tekgui = (t_tekgui*)sender[1];
  start = (t_bunny_position*)sender[2];
  j = (int*)sender[5];
  *radius = 13.0;
  start->x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->radio[i].butt_pos[*j].x + (int)*radius + 5;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->radio[i].butt_pos[*j].y
    + (tekgui->radio[i].butt_dim[*j].y - (int)*radius) / 2;
  tekgui->radio[i].butt_realpos[*j].x = start->x;
  tekgui->radio[i].butt_realpos[*j].y = start->y;
  *color = color_mixer(tekgui->theme[tekgui->actu_theme - 1].one.full,
		       0x66000000);
}

void			set_disp_boucle_text(void **sender, int i)
{
  t_text		*text;
  t_tekgui		*tekgui;
  t_bunny_position	*start;
  t_bunny_pixelarray	*pix;
  int			*j;

  j = (int*)sender[5];
  pix = (t_bunny_pixelarray*)sender[0];
  start = (t_bunny_position*)sender[2];
  text = (t_text*)sender[4];
  tekgui = (t_tekgui*)sender[1];
  text->pos.x = start->x + (tekgui->radio[i].butt_dim[*j].x
			    - my_strlen(tekgui->radio[i].butt_titles[*j])
			    * 3 * 5) / 2;
  text->pos.y =(pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->radio[i].butt_pos[*j].y
    + (tekgui->radio[i].butt_dim[*j].y - 21) / 2 - 10;
}

void			display_radio_boucle(void **sender, int i)
{
  double		radius;
  int			*j;
  t_bunny_pixelarray	*pix;
  t_tekgui		*tekgui;
  t_bunny_position	*start;
  unsigned int		color;
  t_text		*text;

  text = (t_text*)sender[4];
  pix = (t_bunny_pixelarray*)sender[0];
  tekgui = (t_tekgui*)sender[1];
  start = (t_bunny_position*)sender[2];
  j = (int*)sender[5];
  *j = 0;
  while (*j < tekgui->radio[i].nb_butt)
    {
      set_circle_radio(sender, &radius, i, &color);
      if (tekgui->radio[i].selected != *j)
	tekcircle(pix, radius, start, color);
      else
	tekcircle_full(pix, radius, start, color);
      set_disp_boucle_text(sender, i);
      my_blitstr(tekgui->radio[i].butt_titles[*j], pix, tekgui->font, text);
      *j += 1;
    }
}
