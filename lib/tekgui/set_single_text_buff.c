/*
** set_single_text_buff.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:46:43 2016 Iulian Rotaru
** Last update Mon Feb 29 20:40:31 2016 Iulian Rotaru
*/

#include "tekgui.h"

void			set_single_text_buff(void **sender,
					     int *buffer,
					     int x)
{
  t_text		*text;
  t_tekgui		*tekgui;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*start;

  text = (t_text*)sender[4];
  tekgui = (t_tekgui*)sender[1];
  pix = (t_bunny_pixelarray*)sender[0];
  start = (t_bunny_position*)sender[3];
  if (x == tekgui->focus_text && *buffer < 25)
    {
      text->x = 5;
      text->y = 7;
      text->police_size = 21;
      text->pos.x = start->x + my_strlen(tekgui->texter[x].text) * 6 * 3;
      text->pos.y = start->y + 4;
      text->fg = color_mixer(tekgui->theme[tekgui->actu_theme - 1].text.full,
			     0xAA000000);
      my_blitstr("|", pix, tekgui->font, text);
      *buffer += 1;
    }
  if (x == tekgui->focus_text && *buffer >= 25)
    *buffer += 1;
  if (*buffer == 50)
    *buffer = 0;
}

void			display_single_text_field(t_tekgui *tekgui,
						  t_bunny_pixelarray *pix,
						  int x)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  t_text		text;
  static int		buffer;
  unsigned int		color;
  void			*sender[5];

  sender[0] = pix;
  sender[1] = tekgui;
  sender[2] = &dim;
  sender[3] = &start;
  sender[4] = &text;
  set_single_text_first(sender, x, &color);
  make_square(pix, &start, &dim, color);
  set_single_text_sec(sender, x, &color);
  make_square(pix, &start, &dim, color);
  set_single_text_third(sender);
  my_blitstr(tekgui->texter[x].text, pix, tekgui->font, &text);
  set_single_text_buff(sender, &buffer, x);
}

void	display_text_field(t_tekgui *tekgui,
			   t_bunny_pixelarray *pix)
{
  int	i;

  i = 0;
  while (i < tekgui->nb_text)
    {
      display_single_text_field(tekgui, pix, i);
      i++;
    }
}

void			tekcircle(t_bunny_pixelarray *pix,
				  double radius,
				  t_bunny_position *pos,
				  unsigned int color)
{
  double		x;
  t_bunny_position	blit;
  t_color		useless;

  useless.full = color;
  x = 0.0;
  while (x < 360.0)
    {
      blit.x = cos((x * M_PI) / 180) * radius + pos->x;
      blit.y = sin((x * M_PI) / 180) * radius + pos->y;
      tekpixel(pix, &blit, &useless);
      x += 0.1;
    }
}

void			tekcircle_full(t_bunny_pixelarray *pix,
				       double radius,
				       t_bunny_position *pos,
				       unsigned int color)
{
  double		x;
  t_bunny_position	blit;
  t_color		useless;
  int			y;

  useless.full = color_mixer(color, 0x99887766);
  y = 0.0;
  while (y < radius)
    {
      x = 0.0;
      while (x < 360.0)
	{
	  blit.x = cos((x * M_PI) / 180) * y + pos->x;
	  blit.y = sin((x * M_PI) / 180) * y + pos->y;
	  tekpixel(pix, &blit, &useless);
	  x += 0.1;
	}
      y += 1.0;
    }
}
