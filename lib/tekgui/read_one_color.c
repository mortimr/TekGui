/*
** read_one_color.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:43:55 2016 Iulian Rotaru
** Last update Mon Feb 29 20:39:08 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	read_one_color(t_color *color, int fd)
{
  read(fd, &color->argb[3], 1);
  read(fd, &color->argb[2], 1);
  read(fd, &color->argb[1], 1);
  read(fd, &color->argb[0], 1);
}

void	set_ratio_stuff(t_bmp *bmp,
			t_tekgui *tekgui,
			int *ratio,
			int *final)
{
  ratio[0] = 1.0;
  ratio[1] = 1.0;
  if (bmp->bmp_width > (unsigned int)(tekgui->displayer->width - 10))
    ratio[0] = bmp->bmp_width / tekgui->displayer->width + 1;
  if (bmp->bmp_height > (unsigned int)(tekgui->displayer->height
				       - tekgui->disp_bardim.y - 10))
    ratio[1] = bmp->bmp_height / tekgui->displayer->height + 1;
  *final = ratio[0];
  if (ratio[0] < ratio[1])
    *final = ratio[0];
  if (ratio[0] > ratio[1])
    *final = ratio[1];
}

void	jump_to_pix(t_bmp *bmp, int fd)
{
  char	dump;
  int	i;

  i = 0;
  while ((unsigned int)i < bmp->pos - sizeof(t_bmp))
    {
      read(fd, &dump, 1);
      i++;
    }
}

void	set_live_load_pos(t_bunny_pixelarray *pix,
			  t_bunny_position *pos,
			  t_tekgui *tekgui)
{
  pos->x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->displayer->x + 5;
  pos->y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->displayer->y + 5 + tekgui->disp_bardim.y;
}

void			live_load_first(void **sender,
					t_bunny_pixelarray *pix,
					int final,
					t_bmp *bmp)
{
  int			*posi;
  t_bunny_position	*pos;
  t_color		extracter[2];
  int			*fd;

  pos = (t_bunny_position*)sender[1];
  posi = (int*)sender[0];
  fd = (int*)sender[2];
  while ((unsigned int)posi[1] < bmp->bmp_width / (final))
    {
      read_one_color(&extracter[0], *fd);
      if ((pos->x + (int)posi[1] >= 0 && pos->y + (int)posi[0] >= 0)
	  && (pos->x + (int)posi[1] < pix->clipable.clip_width)
	  && (pos->y + (int)posi[0] < pix->clipable.clip_height))
	((unsigned int*)pix->pixels)
	  [(pos->y + (int)posi[0]) * pix->clipable.clip_width
	   + pos->x + (int)posi[1]] = extracter[0].full;
      posi[1] += 1;
      extracter[1].full = 1;
      while (extracter[1].full < (unsigned int)final)
	{
	  read_one_color(&extracter[0], *fd);
	  extracter[1].full++;
	}
    }
}
