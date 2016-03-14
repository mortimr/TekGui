/*
** check_disp_select.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:33:37 2016 Iulian Rotaru
** Last update Mon Feb 29 12:25:24 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	check_disp_select(t_tekgui *data)
{
  int	i;

  i = 0;
  while (i < 8 && data->on == 2)
    {
      if ((bunny_get_mouse_position()->x > 560
	   && bunny_get_mouse_position()->x < 1310) &&
	  (bunny_get_mouse_position()->y > 380 + 40 * i
	   && bunny_get_mouse_position()->y < 420 + 40 * i) &&
	  data->l_click == 1)
	{
	  if ((unsigned int)(i + 1) <= data->nb_files)
	    data->search_select = i;
	}
      i++;
    }
}

void	check_button_on(t_tekgui *data)
{
  void	(*fct)(t_tekgui*);
  int	i;

  i = 0;
  while (i < data->nb_buttons && data->l_click == 1 && data->on == 0)
    {
      if ((bunny_get_mouse_position()->x >
	   (data->pix->clipable.clip_width - data->body.width)
	   / 2 + data->button[i].x) &&
	  (bunny_get_mouse_position()->x <
	   (data->pix->clipable.clip_width - data->body.width)
	   / 2 + data->button[i].x + data->button[i].width) &&
	  (bunny_get_mouse_position()->y >
	   (data->pix->clipable.clip_height - data->body.height)
	   / 2 + data->button[i].y) &&
	  (bunny_get_mouse_position()->y <
	   (data->pix->clipable.clip_height - data->body.height)
	   / 2 + data->button[i].y + data->button[i].height))
	{
	  if ((fct = tekfunction(data->button[i].para)) != NULL)
	    fct(data);
	}
      i++;
    }
}

void	check_text_focus(t_tekgui *data)
{
  int	i;

  i = 0;
  while (i < data->nb_text && data->l_click == 1 && data->on == 0)
    {
      if ((bunny_get_mouse_position()->x >
	   (data->pix->clipable.clip_width - data->body.width)
	   / 2 + data->texter[i].pos.x)
	  && (bunny_get_mouse_position()->x <
	      (data->pix->clipable.clip_width - data->body.width)
	      / 2 + data->texter[i].pos.x + data->texter[i].dim.x)
	  && (bunny_get_mouse_position()->y >
	      (data->pix->clipable.clip_height - data->body.height)
	      / 2 + data->texter[i].pos.y)
	  && (bunny_get_mouse_position()->y <
	      (data->pix->clipable.clip_height - data->body.height)
	      / 2 + data->texter[i].pos.y + data->texter[i].dim.y))
	data->focus_text = i;
      i++;
    }
}

void	check_radio_on(t_tekgui *data)
{
  int	i;
  int	j;

  i = 0;
  while (i < data->nb_radio && data->l_click == 1 && data->on == 0)
    {
      j = 0;
      while (j < data->radio[i].nb_butt)
	{
	  if ((bunny_get_mouse_position()->x >
	       data->radio[i].butt_realpos[j].x - 13) &&
	      (bunny_get_mouse_position()->x <
	       data->radio[i].butt_realpos[j].x + 13) &&
	      (bunny_get_mouse_position()->y >
	       data->radio[i].butt_realpos[j].y - 13) &&
	      (bunny_get_mouse_position()->y <
	       data->radio[i].butt_realpos[j].y + 13))
	    {
	      data->radio[i].selected = j;
	    }
	  j++;
	}
      i++;
    }
}

void	check_cases_on(t_tekgui *data)
{
  int	i;

  i = 0;
  while (i < data->nb_cases && data->l_click == 1 && data->on == 0)
    {
      if ((bunny_get_mouse_position()->x > data->cases[i].real_pos.x) &&
	  (bunny_get_mouse_position()->x < data->cases[i].real_pos.x + 26) &&
	  (bunny_get_mouse_position()->y > data->cases[i].real_pos.y) &&
	  (bunny_get_mouse_position()->y < data->cases[i].real_pos.y + 26))
	{
	  if (data->cases[i].active == 0)
	    data->cases[i].active = 1;
	  else
	    data->cases[i].active = 0;
	}
      i++;
    }
}
