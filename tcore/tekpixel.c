/*
** tekpixel.c for tekpixel in /home/rotaru_i/Coding/LibLap/gfx_fdf2/tcore
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Dec 19 12:28:03 2015 Iulian Rotaru
** Last update Wed Feb 10 09:09:54 2016 Iulian Rotaru
*/

#include <lapin.h>

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  unsigned int	the_x;
  unsigned int	*ptr;

  if ((pos->x >= 0 && pos->x < pix->clipable.clip_width) &&
      (pos->y >= 0 && pos->y < pix->clipable. clip_height))
    {
      ptr = (unsigned int*)pix->pixels;
      the_x = pix->clipable.clip_width;
      ptr[(the_x * (pos->y)) + pos->x] = color->full;
    }
}
