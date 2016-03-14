/*
** display_body.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:30:54 2016 Iulian Rotaru
** Last update Mon Feb 29 12:28:45 2016 Iulian Rotaru
*/

#include "tekgui.h"

void			display_body(t_tekgui *tekgui, t_bunny_pixelarray *pix)
{
  t_bunny_position	start;
  t_bunny_position	dim;
  t_text		text;
  static int		fade;
  static int		reset;

  if (tekgui->actu_theme != reset)
    fade = 0;
  reset = tekgui->actu_theme;
  display_body_next(tekgui, &start, &dim, pix);
  make_square(pix, &start, &dim,
	      tekgui->theme[tekgui->actu_theme - 1].one.full);
  dim.y = 50;
  make_square(pix, &start, &dim,
	      tekgui->theme[tekgui->actu_theme - 1].two.full);
  display_body_next_next(tekgui, &start, &dim, pix);
  make_square(pix, &start, &dim, RED);
  display_body_text(tekgui, &text, pix);
  my_blitstr(tekgui->body.title, pix, tekgui->font, &text);
  display_body_text_next(tekgui, &text, pix, &start);
  my_blitstr("x", pix, tekgui->font, &text);
  display_faded_theme(&fade, &text, pix, tekgui);
}

int	check_exit(t_tekgui *tekgui, t_bunny_pixelarray *pix)
{
  if ((bunny_get_mouse_position()->x >
       (pix->clipable.clip_width -tekgui->body.width)
       / 2 + tekgui->body.width + tekgui->body.exit[0].x) &&
      (bunny_get_mouse_position()->x <
       (pix->clipable.clip_width - tekgui->body.width)
       / 2 + tekgui->body.width + tekgui->body.exit[0].x +
       tekgui->body.exit[1].x) &&
      (bunny_get_mouse_position()->y <
       (pix->clipable.clip_height - tekgui->body.height)
       / 2 - tekgui->body.exit[0].y) &&
      (bunny_get_mouse_position()->y >
       (pix->clipable.clip_height - tekgui->body.height)
       / 2 - (tekgui->body.exit[1].y + tekgui->body.exit[0].y)) &&
      (tekgui->l_click == 1))
    return (EXIT_ON_SUCCESS);
  return (0);
}

int	check_key(t_tekgui *tekgui, t_bunny_pixelarray *pix)
{
  if (check_exit(tekgui, pix) == EXIT_ON_SUCCESS)
    return (EXIT_ON_SUCCESS);
  return (0);
}

void	disp_scroll_up(t_tekgui *tekgui)
{
  if (tekgui->disp == 1)
    {
      if (tekgui->displayer->scroll > 0)
	tekgui->displayer->scroll--;
    }
}

void	disp_scroll_down(t_tekgui *tekgui)
{
  if (tekgui->disp == 1)
    tekgui->displayer->scroll++;
}
