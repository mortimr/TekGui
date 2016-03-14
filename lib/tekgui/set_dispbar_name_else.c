/*
** set_dispbar_name_else.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:35:33 2016 Iulian Rotaru
** Last update Mon Feb 29 20:39:24 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	set_dispbar_name_else(t_tekgui *tekgui, char *file)
{
  int	i;

  i = 0;
  while (tekgui->displayer->bar.search[i])
    {
      file[i] = tekgui->displayer->bar.search[i];
      i++;
    }
  file[i] = 0;
}

void	set_dispbar_name(t_tekgui *tekgui, char *file)
{
  int	i;
  int	j;

  if (is_there_path(tekgui->displayer->bar.search) == 0)
    {
      i = 0;
      j = 0;
      while (tekgui->displayer->bar.search[i])
	{
	  if (tekgui->displayer->bar.search[i] == '/')
	    j = - 1;
	  else
	    file[j] = tekgui->displayer->bar.search[i];
	  i++;
	  j++;
	}
      file[j] = 0;
    }
  else
    set_dispbar_name_else(tekgui, file);
}

void	display_search_next_pos(t_bunny_pixelarray *pix,
				t_bunny_position *start,
				t_bunny_position *dim,
				t_tekgui *tekgui)
{
  start->x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->displayer->x + 2 + (dim->x / 10) * 9;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->displayer->y + 4;
  dim->x = (tekgui->displayer->bar.width) / 10;
  dim->y = tekgui->displayer->bar.height - 8;
  tekgui->disp_butt.x = start->x;
  tekgui->disp_butt.y = start->y;
  tekgui->disp_dim.x = dim->x;
  tekgui->disp_dim.y = dim->y;
}

void			display_search_dispbar(t_tekgui *tekgui,
					       t_bunny_pixelarray *pix)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  unsigned int		color;
  t_text		text;
  char			file[100];

  set_disp_search_pos(&dim, &start, pix, tekgui);
  set_disp_save_pos(tekgui, &start, &dim);
  text_dispobar_set(&text, tekgui, &start);
  if (tekgui->displayer->bar.focus == 1)
    color = 0xCCCCCCCC;
  else
    color = color_mixer(tekgui->theme[tekgui->actu_theme - 1].one.full,
			0x77FFFFFF);
  make_square(pix, &start, &dim, color);
  set_dispbar_name(tekgui, file);
  my_blitstr(file, pix, tekgui->font, &text);
  display_search_next_pos(pix, &start, &dim, tekgui);
  color = tekgui->theme[tekgui->actu_theme - 1].two.full;
  make_square(pix, &start, &dim, color);
  text.police_size = 14;
  text.pos.x = start.x + (dim.x - my_strlen("FILE") * 10) / 2;
  text.pos.y = start.y + (dim.y - 14) / 2;
  text.fg = tekgui->theme[tekgui->actu_theme - 1].text.full;
  my_blitstr("FILE", pix, tekgui->font, &text);
}

void			display_displayer(t_tekgui *tekgui,
					  t_bunny_pixelarray *pix)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  unsigned int		color;

  start.x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->displayer->x - 1;
  start.y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->displayer->y - 1;
  dim.x = tekgui->displayer->width + 2;
  dim.y = tekgui->displayer->height + 2;
  color = 0x21212121;
  make_square(pix, &start, &dim, color);
  start.x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->displayer->x;
  start.y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->displayer->y;
  dim.x = tekgui->displayer->width;
  dim.y = tekgui->displayer->height;
  color = tekgui->theme[tekgui->actu_theme - 1].two.full;
  make_square(pix, &start, &dim, color);
  display_search_dispbar(tekgui, pix);
}
