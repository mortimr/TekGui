/*
** fade_body.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:40:09 2016 Iulian Rotaru
** Last update Mon Feb 29 20:30:32 2016 Iulian Rotaru
*/

#include "tekgui.h"

void			fade_body(t_tekgui *tekgui, t_bunny_pixelarray *pix, int mode)
{
  static unsigned int	color;
  static int		fade;
  t_bunny_position	start;
  t_bunny_position	dim;

  if (mode == 1)
    {
      fade = 0;
      color = 0;
    }
  if (mode == 0)
    {
      if (fade < 25)
	{
	  color += 0x06000000;
	  fade++;
	}
      start.x = (pix->clipable.clip_width - tekgui->body.width) / 2;
      start.y = (pix->clipable.clip_height - tekgui->body.height) / 2;
      dim.x = tekgui->body.width;
      dim.y = tekgui->body.height;
      make_square_transpa(pix, &start, &dim, color);
    }
}

void		display_text_next(void **send,
				  t_text *text,
				  t_tekgui *tekgui,
				  t_bunny_pixelarray *pix)
{
  int		i;
  struct dirent	*buff;
  DIR		*current;

  current = (DIR*)send[1];
  buff = (struct dirent*)send[0];
  i = 0;
  while (i < 8 && buff)
    {
      text->fg = color_mixer(tekgui->theme[tekgui->actu_theme - 1].text.full,
			     0xAA000000);
      if (buff->d_type == 4)
	text->fg = BLUE;
      my_blitstr(buff->d_name, pix, tekgui->font, text);
      buff = readdir(current);
      i++;
      text->pos.y += 40;
    }
}

void	set_text_display_text(t_text *text)
{
  text->x = 5;
  text->y = 7;
  text->police_size = 21;
  text->pos.x = 565;
  text->pos.y = 390;
}

int		display_text(t_tekgui *tekgui,
			     t_bunny_pixelarray *pix)
{
  DIR		*current;
  struct dirent	*buff;
  int		i;
  t_text	text;
  void		*send[2];

  if ((current = opendir(tekgui->current)) == NULL)
    return (- 1);
  if ((buff = readdir(current)) == NULL)
    return (- 1);
  i = 0;
  while (i < tekgui->scroll)
    {
      i++;
      buff = readdir(current);
    }
  i = 0;
  set_text_display_text(&text);
  send[0] = buff;
  send[1] = current;
  display_text_next(send, &text, tekgui, pix);
  closedir(current);
  return (0);
}

void	get_selection_dispbar_next(DIR *current,
				   t_tekgui *tekgui)
{
  tekgui->selection_done = 1;
  closedir(current);
}
