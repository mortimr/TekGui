/*
** tekline.c for tekline in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Nov 15 14:30:23 2015 Iulian Rotaru
** Last update Mon Feb 29 14:17:20 2016 Iulian Rotaru
*/

#include <lapin.h>
#include "tekgui.h"

int	abso(int nb)
{
  if (nb < 0)
    return (-nb);
  else
    return (nb);
}

void	tmpline(t_bunny_position *coord,
		double *x,
		double *y,
		double *len)
{
  *x = coord[0].x;
  *y = coord[0].y;
  if (abso(coord[1].y - coord[0].y) >=
      abso(coord[1].x - coord[0].x))
    *len = abs(coord[1].y - coord[0].y);
  else
    *len = abs(coord[1].x - coord[0].x);
  if (((coord[1].x - *x) / *len) < 0)
    *x -= 0.5;
  else
    *x += 0.5;
  if (((coord[1].y - *y) / *len) < 0)
    *y -= 0.5;
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *coord,
				t_color *color)
{
  t_bunny_position	pos;
  double		coef_x;
  double		coef_y;
  double		x;
  double		y;
  double		len;
  int			i;

  i = 0;
  tmpline(coord, &x, &y, &len);
  coef_x = (coord[1].x - x) / len;
  coef_y = (coord[1].y - y) / len;
  while (i <= len)
    {
      pos.x = x;
      pos.y = y;
      tekpixel(pix, &pos, color);
      x += coef_x;
      y += coef_y;
      i++;
    }
}
