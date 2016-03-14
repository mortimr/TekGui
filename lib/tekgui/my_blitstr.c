/*
** my_blitstr.c for liblap in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb  2 17:31:01 2016 Iulian Rotaru
** Last update Mon Feb 29 12:56:25 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	ratio_setter(int *ratio, t_text *text)
{
  *ratio = text->police_size / 7;
  if (*ratio == 0)
    *ratio = 1;
}

void			my_blitnbr(int nb,
				   t_bunny_pixelarray *pix,
				   t_bunny_pixelarray *text_pix,
				   t_text *text)
{
  t_bunny_position	pos[2];
  int			i;
  int			ratio;
  static int		j;
  int			tmp;

  ratio_setter(&ratio, text);
  tmp = nb;
  while (tmp / 10 > 0)
    {
      j++;
      tmp = tmp / 10;
    }
  i = 0;
  set_start_nb(pos, text, ratio, j);
  while (i <= j)
    {
      pos[0].x = text->x * ((nb % 10) + 48);
      pos[1].x = text->x * ((nb % 10) + 49);
      copy_area(pix, text_pix, pos, text);
      pos[2].x -= ratio * 6;
      i++;
      nb = nb / 10;
    }
  j = 0;
}

void	main_under_boucle(t_area_text *v)
{
  while (v->x < v->area[1].x - v->area[0].x)
    {
      v->i = 0;
      while (v->i < v->ratio)
	{
	  if (v->ptrr[(v->y + v->area[0].y) *
		      v->extract->clipable.clip_width +
		      (v->x + v->area[0].x)])
	    v->ptr[(v->blit.y + (v->y) * (v->ratio) + v->j) *
		   v->pix->clipable.clip_width +
		   v->blit.x + (v->x) * (v->ratio) + v->i]
	      = color_mixer(v->ptr[(v->blit.y + (v->y) * (v->ratio) + v->j) *
				   v->pix->clipable.clip_width +
				   v->blit.x + (v->x) * (v->ratio) + v->i],
			    v->text->fg);
	  v->i++;
	}
      v->x++;
    }
}

void	main_boucle(t_area_text *v)
{
  while (v->y < v->area[1].y - v->area[0].y)
    {
      v->j = 0;
      while (v->j < v->ratio)
	{
	  v->x = 0;
	  main_under_boucle(v);
	  v->j++;
	}
      v->y++;
    }
}

void		copy_area(t_bunny_pixelarray *pix,
			  t_bunny_pixelarray *extract,
			  t_bunny_position *area,
			  t_text *text)
{
  t_area_text	v;

  v.text = text;
  v.ratio = v.text->police_size / 7;
  if (v.ratio == 0)
    v.ratio = 1;
  v.ptr = (unsigned int*) pix->pixels;
  v.ptrr = (unsigned int*) extract->pixels;
  v.blit.x = area[2].x;
  v.blit.y = area[2].y;
  v.y = 0;
  v.pix = pix;
  v.extract = extract;
  v.area = area;
  main_boucle(&v);
}

int	ps(t_bunny_position *pos, t_text *text)
{
  pos[2].x = text->pos.x;
  pos[2].y = text->pos.y;
  pos[0].y = 0;
  pos[1].y = text->y;
  return (1);
}

void			my_blitstr(char *str,
				   t_bunny_pixelarray *pix,
				   t_bunny_pixelarray *text_pix,
				   t_text *text)
{
  t_bunny_position	pos[2];
  int			i;
  int			ratio;

  ps(pos, text);
  if ((ratio = text->police_size / 7) && !(i = 0) && ratio == 0)
    ratio = 1;
  while (str[i])
    {
      pos[0].x = text->x * str[i];
      pos[1].x = text->x * (str[i] + 1);
      if ((str[i] != '\n' && str[i] > '\n' &&
	   pos[2].x >= 0 && pos[2].x < pix->clipable.clip_width)
	  && (pos[2].x + 6 * ratio >= 0 &&
	      pos[2].x + 6 * ratio < pix->clipable.clip_width))
	copy_area(pix, text_pix, pos, text);
      else if (str[i] == '\n')
	{
	  pos[2].y += 10 * ratio;
	  pos[2].x = text->pos.x - 6 * ratio;
	}
      i++;
      pos[2].x += 6 * ratio;
    }
}
