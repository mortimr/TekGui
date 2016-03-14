/*
** live_load_boucle.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:44:52 2016 Iulian Rotaru
** Last update Mon Feb 29 12:48:31 2016 Iulian Rotaru
*/

#include "tekgui.h"

void			live_load_boucle(int *posi,
					 t_bunny_position *pos,
					 t_bmp *bmp,
					 void **send)
{
  void			*sender[3];
  t_color		extracter;
  int			*final;
  t_bunny_pixelarray	*pix;
  int			*fd;
  int			i;

  pix = (t_bunny_pixelarray*)send[0];
  fd = (int*)send[2];
  final = (int*)send[1];
  while (posi[0] > 0)
    {
      posi[1] = 0;
      sender[0] = posi;
      sender[1] = pos;
      sender[2] = fd;
      live_load_first(sender, pix, *final, bmp);
      posi[0] -= 1;
      i = bmp->bmp_width;
      while ((unsigned int)i < bmp->bmp_width * (*final))
	{
	  read_one_color(&extracter, *fd);
	  i++;
	}
    }
}

int			live_load_bitmap(t_tekgui *tekgui,
					 t_bunny_pixelarray *pix,
					 int fd)
{
  t_bmp			bmp;
  int			ratio[2];
  int			final;
  int			posi[2];
  void			*send[3];
  t_bunny_position	pos;

  if ((unsigned int)read(fd, &bmp, sizeof(t_bmp)) < sizeof(t_bmp))
    return (1);
  set_ratio_stuff(&bmp, tekgui, ratio, &final);
  if (final == 0)
    final = 1;
  jump_to_pix(&bmp, fd);
  set_live_load_pos(pix, &pos, tekgui);
  posi[1] = 0;
  posi[0] = bmp.bmp_height / (final);
  send[0] = pix;
  send[1] = &final;
  send[2] = &fd;
  live_load_boucle(posi, &pos, &bmp, send);
  return (0);
}

void		display_img_text(t_tekgui *tekgui, t_bunny_pixelarray *pix)
{
  t_text	text;
  int		fd;

  if ((fd = open(tekgui->displayer->bar.search, O_RDONLY)) > 0)
    {
      if (my_strcmp_end(".bmp", tekgui->displayer->bar.search) == 0)
	{
	  if (live_load_bitmap(tekgui, pix, fd) == 1)
	    {
	      text.x = 5;
	      text.y = 7;
	      text.police_size = 21;
	      text.fg = tekgui->theme[tekgui->actu_theme - 1].text.full;
	      text.pos.x = (pix->clipable.clip_width - tekgui->body.width)
		/ 2 + tekgui->displayer->x + 5;
	      text.pos.y = (pix->clipable.clip_height - tekgui->body.height)
		/ 2 + tekgui->displayer->y + 5 + tekgui->disp_bardim.y;
	      my_blitstr("Can't load file !", pix, tekgui->font, &text);
	    }
	}
      else
	aff_file_text(tekgui, pix, fd);
      close(fd);
    }
}

void			display_one_button(t_button *button,
					   t_tekgui *tekgui,
					   t_bunny_pixelarray *pix)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  unsigned int		color;
  t_text		text;

  start.x = (pix->clipable.clip_width - tekgui->body.width) / 2 + button->x;
  start.y = (pix->clipable.clip_height - tekgui->body.height) / 2 + button->y;
  dim.x = button->width;
  dim.y = button->height;
  color = color_mixer(tekgui->theme[tekgui->actu_theme - 1].one.full,
		      0x55000000);
  make_square(pix, &start, &dim, color);
  text.x = 5;
  text.y = 7;
  text.police_size = 14;
  text.pos.x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + button->x + ((button->width - my_strlen(button->name) * 14) / 2);
  text.pos.y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + button->y - 7 + button->height / 2;
  text.fg = tekgui->theme[tekgui->actu_theme - 1].text.full;
  my_blitstr(button->name, pix, tekgui->font, &text);
}

void	display_buttons(t_tekgui *tekgui,
			t_bunny_pixelarray *pix)
{
  int	i;

  i = 0;
  while (i < tekgui->nb_buttons)
    {
      display_one_button(&tekgui->button[i], tekgui, pix);
      i++;
    }
}
