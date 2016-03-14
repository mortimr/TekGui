/*
** background_manager.c for background_manager in /home/rotaru_i/Coding/LibLap/gfx_tekpaint/tcore
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Jan  5 20:12:41 2016 Iulian Rotaru
** Last update Mon Feb 29 12:24:15 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	swap_it(int y, unsigned int *color)
{
  if (y % 20 == 0)
    {
      color[2] = color[1];
      color[1] = color[0];
      color[0] = color[2];
    }
}

void	swap_it_x(int y, unsigned int *color)
{
  if (y % 20 == 0)
    {
      color[2] = color[1];
      color[1] = color[0];
      color[0] = color[2];
    }
}

void		background_manager(t_bunny_pixelarray *pix)
{
  int		x;
  int		y;
  unsigned int	*ptr;
  unsigned int	color[3];

  ptr = (unsigned int*) pix->pixels;
  y = 0;
  color[0] = 0x12121212;
  color[1] = 0x09090909;
  while (y < pix->clipable.clip_height)
    {
      swap_it(y, color);
      x = 0;
      while (x < pix->clipable.clip_width)
	{
	  swap_it_x(x, color);
	  ptr[y * pix->clipable.clip_width + x] = color[0];
	  x++;
	}
      y++;
    }
}
