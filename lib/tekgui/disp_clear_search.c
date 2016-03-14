/*
** disp_clear_search.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:32:43 2016 Iulian Rotaru
** Last update Fri Feb 26 15:22:33 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	disp_clear_search(t_tekgui *tekgui)
{
  if (tekgui->disp == 1)
    tekgui->displayer->bar.search[0] = 0;
}

void	disp_search_urandom(t_tekgui *tekgui)
{
  char	*urandom;
  int	i;

  i = 0;
  urandom = "/dev/urandom";
  if (tekgui->disp == 1)
    {
      while (urandom[i])
	{
	  tekgui->displayer->bar.search[i] = urandom[i];
	  i++;
	}
      tekgui->displayer->bar.search[i] = 0;
    }
}

void	check_if_exit_body(t_tekgui *data)
{
  if ((data->l_click == 1 && data->on == 1) &&
      (bunny_get_mouse_position()->x >
       data->ex_button[0].x && bunny_get_mouse_position()->x <
       data->ex_button[0].x + data->ex_size[0].x) &&
      (bunny_get_mouse_position()->y >
       data->ex_button[0].y && bunny_get_mouse_position()->y <
       data->ex_button[0].y + data->ex_size[0].y))
    data->on = - 1;
}

void	check_if_exit_exit(t_tekgui *data)
{
  if ((data->l_click == 1 && data->on == 1) &&
      (bunny_get_mouse_position()->x > data->ex_button[1].x
       && bunny_get_mouse_position()->x < data->ex_button[1].x
       + data->ex_size[1].x) &&
      (bunny_get_mouse_position()->y > data->ex_button[1].y
       && bunny_get_mouse_position()->y < data->ex_button[1].y
       + data->ex_size[1].y))
    data->on = 0;
}

void	check_if_disp_on(t_tekgui *data)
{
  if ((data->l_click == 1 && data->on == 0 && data->disp == 1) &&
      (bunny_get_mouse_position()->x > data->disp_butt.x
       && bunny_get_mouse_position()->x < data->disp_butt.x
       + data->disp_dim.x) &&
      (bunny_get_mouse_position()->y > data->disp_butt.y
       && bunny_get_mouse_position()->y < data->disp_butt.y
       + data->disp_dim.y))
    data->on = 2;
  else if ((data->l_click == 1 && data->on == 2) &&
	   (bunny_get_mouse_position()->x > 1366
	    && bunny_get_mouse_position()->x < 1406) &&
	   (bunny_get_mouse_position()->y > 295
	    && bunny_get_mouse_position()->y < 326))
    {
      data->on = 0;
      fade_body(NULL, NULL, 1);
      data->scroll = 0;
    }
}
