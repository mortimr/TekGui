/*
** gui_click.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:34:39 2016 Iulian Rotaru
** Last update Mon Feb 29 20:33:44 2016 Iulian Rotaru
*/

#include "tekgui.h"

t_bunny_response	gui_click(t_bunny_event_state state,
				  t_bunny_mousebutton sym,
				  void *info)
{
  t_tekgui		*data;

  data = (t_tekgui*) info;
  if (sym == BMB_LEFT && state == GO_DOWN)
    data->l_click = 1;
  else
    data->l_click = 0;
  check_if_exit_body(data);
  check_if_exit_exit(data);
  check_if_disp_on(data);
  check_disp_select(data);
  check_button_on(data);
  check_text_focus(data);
  check_radio_on(data);
  check_cases_on(data);
  return (GO_ON);
}

int	is_there_path(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '/')
	return (0);
      i++;
    }
  return (1);
}

void	set_disp_search_pos(t_bunny_position *dim,
			    t_bunny_position *start,
			    t_bunny_pixelarray *pix,
			    t_tekgui *tekgui)
{
  start->x = (pix->clipable.clip_width - tekgui->body.width) / 2
    + tekgui->displayer->x + 2;
  start->y = (pix->clipable.clip_height - tekgui->body.height) / 2
    + tekgui->displayer->y + 2;
  dim->x = tekgui->displayer->bar.width - 4;
  dim->y = tekgui->displayer->bar.height - 4;
}

void	set_disp_save_pos(t_tekgui *tekgui,
			  t_bunny_position *start,
			  t_bunny_position *dim)
{
  tekgui->disp_bar.x = start->x;
  tekgui->disp_bar.y = start->y;
  tekgui->disp_bardim.x = dim->x - (tekgui->displayer->bar.width) / 10;
  tekgui->disp_bardim.y = dim->y;
}

void	text_dispobar_set(t_text *text,
			  t_tekgui *tekgui,
			  t_bunny_position *start)
{
  text->x = 5;
  text->y = 7;
  text->police_size = 21;
  text->fg = color_mixer(tekgui->theme[tekgui->actu_theme - 1].text.full,
			 0x99000000);
  text->pos.x = start->x + 5;
  text->pos.y = start->y + 5;
}
