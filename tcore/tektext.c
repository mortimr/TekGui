/*
** tektext.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb  9 19:07:34 2016 Iulian Rotaru
** Last update Mon Feb 29 14:19:02 2016 Iulian Rotaru
*/

#include <lapin.h>
#include "tekgui.h"

unsigned int	color_mixer(unsigned int one,
			    unsigned int add)
{
  t_color	first;
  t_color	adder;
  t_color	out;
  double	coeff;

  first.full = one;
  adder.full = add;
  coeff = adder.argb[3] / 256.0;
  out.argb[0] = adder.argb[0] * coeff + first.argb[0] * (1.0 - coeff);
  out.argb[1] = adder.argb[1] * coeff + first.argb[1] * (1.0 - coeff);
  out.argb[2] = adder.argb[2] * coeff + first.argb[2] * (1.0 - coeff);
  out.argb[3] = adder.argb[3] * coeff + first.argb[3] * (1.0 - coeff);
  return (out.full);
}

void	no_space(t_area_text *v)
{
  if (v->ptrr[(v->y + v->area[0].y) *
	      v->extract->clipable.clip_width
	      + (v->x + v->area[0].x)])
    v->ptr[(v->blit.y + (v->y)) *
	   v->pix->clipable.clip_width +
	   v->blit.x + (v->x)] = color_mixer
      (v->ptr[(v->blit.y + (v->y)) *
	      v->pix->clipable.clip_width
	      + v->blit.x + (v->x)]
       , v->ptrr[(v->y + v->area[0].y)
		 * v->extract->clipable.clip_width +
		 (v->x + v->area[0].x)]);
}

void		copy_area_tek(t_bunny_pixelarray *pix,
			      t_bunny_pixelarray *extract,
			      t_bunny_position *area)
{
  t_area_text	v;

  v.area = area;
  v.extract = extract;
  v.pix = pix;
  v.ptr = (unsigned int*) pix->pixels;
  v.ptrr = (unsigned int*) extract->pixels;
  v.blit.x = v.area[2].x;
  v.blit.y = v.area[2].y;
  v.y = 0;
  while (v.y < v.area[1].y - v.area[0].y)
    {
      v.x = 0;
      while (v.x < area[1].x - v.area[0].x)
	{
	  no_space(&v);
	  v.x++;
	}
      v.y++;
   }
}

void			tektext(t_bunny_pixelarray *out,
				const char *str,
				t_bunny_pixelarray *font_png)
{
  t_bunny_position	pos[2];
  int			i;

  i = 0;
  pos[2].x = 0;
  pos[2].y = 0;
  pos[0].y = 0;
  pos[1].y = 7;
  while (str[i])
    {
      pos[0].x = 5 * str[i];
      pos[1].x = 5 * (str[i] + 1);
      if (str[i] && str[i] != ' ')
	copy_area_tek(out, font_png, pos);
      i++;
      pos[2].x += 6;
    }
}
