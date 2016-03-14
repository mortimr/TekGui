/*
** make_square.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:27:33 2016 Iulian Rotaru
** Last update Mon Feb 29 12:53:32 2016 Iulian Rotaru
*/

#include "tekgui.h"

void		make_square(t_bunny_pixelarray *pix,
			    t_bunny_position *start,
			    t_bunny_position *dim,
			    unsigned int color)
{
  int		x;
  int		y;
  unsigned int	*ptr;

  y = 0;
  ptr = (unsigned int*)pix->pixels;
  while (y < dim->y)
    {
      x = 0;
      while (x < dim->x)
	{
	  if ((y + start->y >= 0 && y + start->y <
	       pix->clipable.clip_height) &&
	      (x + start->x >= 0 && x + start->x <
	       pix->clipable.clip_width))
	    ptr[(y + start->y) *
		pix->clipable.clip_width + x + start->x] = color;
	  x++;
	}
      y++;
    }
}

void		make_square_empty(t_bunny_pixelarray *pix,
				  t_bunny_position *start,
				  t_bunny_position *dim,
				  unsigned int color)
{
  int		x;
  int		y;
  unsigned int	*ptr;

  y = 0;
  ptr = (unsigned int*)pix->pixels;
  while (y < dim->y)
    {
      x = 0;
      while (x < dim->x)
	{
	  if ((y + start->y >= 0 && y + start->y <
	       pix->clipable.clip_height) &&
	      (x + start->x >= 0 && x + start->x <
	       pix->clipable.clip_width))
	    if ((y < 2) || (x < 2) || (x > dim->x - 3) ||
		(y > dim->y - 3))
	      ptr[(y + start->y) *
		  pix->clipable.clip_width + x + start->x] = color;
	  x++;
	}
      y++;
    }
}

void			cross_maker(unsigned int color,
				    t_bunny_position *start,
				    t_bunny_position *dim,
				    t_bunny_pixelarray *pix)
{
  t_color		tmp;
  t_bunny_position	pos[2];

  tmp.full = color;
  pos[0].x = start->x;
  pos[0].y = start->y;
  pos[1].x = start->x + dim->x;
  pos[1].y = start->y + dim->y;
  tekline(pix, pos, &tmp);
  pos[0].x = start->x;
  pos[0].y = start->y + dim->y;
  pos[1].x = start->x + dim->x;
  pos[1].y = start->y;
  tekline(pix, pos, &tmp);
}

void		make_square_cross(t_bunny_pixelarray *pix,
				  t_bunny_position *start,
				  t_bunny_position *dim,
				  unsigned int color)
{
  int		x;
  int		y;
  unsigned int	*ptr;

  y = 0;
  ptr = (unsigned int*)pix->pixels;
  while (y < dim->y)
    {
      x = 0;
      while (x < dim->x)
	{
	  if ((y + start->y >= 0 && y + start->y <
	       pix->clipable.clip_height) &&
	      (x + start->x >= 0 && x + start->x <
	       pix->clipable.clip_width))
	    if ((y < 2) || (x < 2) || (x > dim->x - 3) ||
		(y > dim->y - 3))
	      ptr[(y + start->y) *
		  pix->clipable.clip_width + x + start->x] = color;
	  x++;
	}
      y++;
    }
  cross_maker(color, start, dim, pix);
}

void		make_square_transpa(t_bunny_pixelarray *pix,
				    t_bunny_position *start,
				    t_bunny_position *dim,
				    unsigned int color)
{
  int		x;
  int		y;
  unsigned int	*ptr;

  y = 0;
  ptr = (unsigned int*)pix->pixels;
  while (y < dim->y)
    {
      x = 0;
      while (x < dim->x)
	{
	  if ((y + start->y >= 0 && y + start->y <
	       pix->clipable.clip_height) &&
	      (x + start->x >= 0 && x + start->x <
	       pix->clipable.clip_width))
	    ptr[(y + start->y) *
		pix->clipable.clip_width + x + start->x]
	      = color_mixer(ptr[(y + start->y) *
				pix->clipable.clip_width
				+ x + start->x], color);
	  x++;
	}
      y++;
    }
}
