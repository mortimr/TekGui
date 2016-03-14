/*
** read_bmp.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb 16 16:20:25 2016 Iulian Rotaru
** Last update Mon Feb 29 20:38:39 2016 Iulian Rotaru
*/

#include <lapin.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "tekgui.h"

void			read_colors(t_bmp *bmp,
				    t_bunny_pixelarray *pix,
				    int fd)
{
  t_bunny_position	pos;
  t_color		color;

  pos.y = bmp->bmp_height - 1;
  while (pos.y >= 0)
    {
      pos.x = 0;
      while ((unsigned int)pos.x < bmp->bmp_width)
	{
	  read(fd, &color.argb[3], 1);
	  read(fd, &color.argb[2], 1);
	  read(fd, &color.argb[1], 1);
	  read(fd, &color.argb[0], 1);
	  tekpixel(pix, &pos, &color);
	  pos.x++;
	}
      pos.y--;
    }
}

t_bunny_pixelarray	*bmp_way(int fd)
{
  t_bmp			bmp;
  t_bunny_pixelarray	*pix;
  char			asshole;
  unsigned int		i;

  i = 0;
  if ((read(fd, &bmp, sizeof(t_bmp)) < 0))
    return (NULL);
  if (bmp.bmp_width > 1550 || bmp.bmp_height > 872)
    return (NULL);
  if (bmp.ndbpp != 32)
    return (NULL);
  while (i < bmp.pos - sizeof(t_bmp) && read(fd, &asshole, 1) > 0)
    i++;
  if ((pix = bunny_new_pixelarray(bmp.bmp_width, bmp.bmp_height)) == NULL)
    return (NULL);
  read_colors(&bmp, pix, fd);
  return (pix);
}

t_bunny_pixelarray	*load_bitmap(char *file)
{
  int			fd;

  if ((fd = open(file, O_RDONLY)) < 0)
    return (NULL);
  return (bmp_way(fd));
}
