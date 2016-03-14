/*
** typing.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Feb 28 12:27:18 2016 Iulian Rotaru
** Last update Mon Feb 29 14:18:11 2016 Iulian Rotaru
*/

#include "tekgui.h"

t_bunny_response	typing(uint32_t unicode,
			       void *data)
{
  t_tekgui		*tekgui;
  int			i;

  i = 0;
  tekgui = (t_tekgui*)data;
  if (tekgui->focus_text != - 1 && tekgui->on == 0 && tekgui->nb_text != 0)
    {
      while (tekgui->texter[(int)tekgui->focus_text].text[i])
	i++;
      if (my_strlen(tekgui->texter[(int)tekgui->focus_text].text) < 1000)
	{
	  typing_next(unicode, tekgui, i);
	}
    }
  return (GO_ON);
}

int	tekgui_loop(t_bunny_window *win, t_bunny_pixelarray *pix, t_tekgui *tekgui)
{
  if ((win == NULL) || (pix == NULL) || (tekgui == NULL))
    return (1);
  tekgui->win = win;
  tekgui->pix = pix;
  bunny_set_move_response((t_bunny_move) mouse_move);
  bunny_set_loop_main_function((t_bunny_loop)loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_set_click_response((t_bunny_click) gui_click);
  bunny_set_text_response((t_bunny_type) typing);
  bunny_loop(tekgui->win, 60, tekgui);
  return (0);
}
