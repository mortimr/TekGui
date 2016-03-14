/*
** my_strcmp_end.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:43:01 2016 Iulian Rotaru
** Last update Mon Feb 29 20:38:11 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	my_strcmp_end(char *end, char *str)
{
  int	i;

  i = 0;
  while (my_strlen(end) - i - 1 > 0)
    {
      if (end[my_strlen(end) - 1 - i] != str[my_strlen(str) - 1 - i])
	return (1);
      i++;
    }
  return (0);
}

void			aff_file_text_sec(t_tekgui *tekgui,
					  void **send,
					  char *t)
{
  t_text		*text;
  t_bunny_pixelarray	*pix;

  pix = (t_bunny_pixelarray*)send[0];
  text = (t_text*)send[1];
  my_blitstr(t, pix, tekgui->font, text);
  if (text->pos.x + 14 * 3 > tekgui->displayer->x + 5
      + (pix->clipable.clip_width - tekgui->body.width) / 2
      + tekgui->displayer->width)
    {
      text->pos.x += 14;
      my_blitstr("/", pix, tekgui->font, text);
      text->pos.x = tekgui->displayer->x + 5
	+ (pix->clipable.clip_width - tekgui->body.width) / 2;
      text->pos.y += 16;
    }
  else
    text->pos.x += 14;
}

void			aff_file_text_first(t_tekgui *tekgui,
					    void **send,
					    char *t)
{
  t_text		*text;
  t_bunny_pixelarray	*pix;

  pix = (t_bunny_pixelarray*)send[0];
  text = (t_text*)send[1];
  if (t[0] == '\t')
    {
      if (text->pos.x + 14 * 3 > tekgui->displayer->x + 5
	  + (pix->clipable.clip_width - tekgui->body.width) / 2
	  + tekgui->displayer->width)
	{
	  text->pos.x = tekgui->displayer->x + 5
	    + (pix->clipable.clip_width - tekgui->body.width) / 2;
	  text->pos.y += 16;
	}
      else
	text->pos.x += 14 * 3;
    }
  else
    aff_file_text_sec(tekgui, send, t);
}

int			aff_file_text_next(t_tekgui *tekgui,
					   void **send,
					   int fd)
{
  char			t[2];
  t_bunny_pixelarray	*pix;
  t_text		*text;
  char			s;

  pix = (t_bunny_pixelarray*)send[0];
  text = (t_text*)send[1];
  t[1] = 0;
  while (read(fd, &s, 1) >= 0 && text->pos.y <
	 tekgui->displayer->height - tekgui->disp_bardim.y +
	 (pix->clipable.clip_height - tekgui->body.height) / 2 +
	 tekgui->displayer->y)
    {
      t[0] = s;
      if (t[0] == '\n')
	{
	  text->pos.x = tekgui->displayer->x + 5
	    + (pix->clipable.clip_width - tekgui->body.width) / 2;
	  text->pos.y += 16;
	}
      else if (t[0] < 127)
	aff_file_text_first(tekgui, send, t);
    }
  return (0);
}

int		aff_file_text(t_tekgui *tekgui,
			      t_bunny_pixelarray *pix,
			      int fd)
{
  int		i;
  char		s;
  t_text	text;
  void		*send[2];

  i = 0;
  text.x = 5;
  text.y = 7;
  text.pos.x = tekgui->displayer->x + 5 +
    (pix->clipable.clip_width - tekgui->body.width) / 2;
  text.pos.y = tekgui->displayer->y + 5 +
    (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->disp_bardim.y;
  text.police_size = 14;
  text.fg = color_mixer(tekgui->theme[tekgui->actu_theme - 1].text.full,
			0xDD000000);
  while (i < tekgui->displayer->scroll && read(fd, &s, 1) > 0)
    {
      if (s == '\n')
	i++;
    }
  send[0] = (void*)pix;
  send[1] = (void*)&text;
  return (aff_file_text_next(tekgui, send, fd));
}
