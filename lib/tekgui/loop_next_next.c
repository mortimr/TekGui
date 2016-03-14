/*
** loop_next_next.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Feb 28 12:21:38 2016 Iulian Rotaru
** Last update Mon Feb 29 12:51:35 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	loop_next_next(t_tekgui *tekgui)
{
  tekgui_display(tekgui->pix, tekgui);
  if (tekgui->on == 2)
    {
      if (search_box(tekgui, tekgui->pix) == - 1)
	return (EXIT_ON_ERROR);
      if (tekgui->selection_done == 1)
	{
	  tekgui->selection_done = 0;
	  if (assembling_dispbar(tekgui) == - 1)
	    return (EXIT_ON_ERROR);
	  if (tekgui->selection_done == 2)
	    {
	      tekgui->on = 0;
	      tekgui->displayer->scroll = 0;
	    }
	}
    }
  bunny_blit(&tekgui->win->buffer, &tekgui->pix->clipable, NULL);
  bunny_display(tekgui->win);
  return (GO_ON);
}

int	loop_next(t_tekgui *tekgui)
{
  int	i;
  void	(*fct)(t_tekgui*);

  i = 0;
  while (i < tekgui->nb_cases)
    {
      if (tekgui->cases[i].active == 0)
	{
	  if ((fct = tekfunction(tekgui->cases[i].fct_off)) != NULL)
	    fct(tekgui);
	}
      else
	{
	  if ((fct = tekfunction(tekgui->cases[i].fct_on)) != NULL)
	    fct(tekgui);
	}
      i++;
    }
  return (loop_next_next(tekgui));
}

t_bunny_response	loop(void *data)
{
  t_tekgui		*tekgui;
  int			i;
  void			(*fct)(t_tekgui*);

  tekgui = (t_tekgui*) data;
  if (check_key(tekgui, tekgui->pix) == EXIT_ON_SUCCESS)
    tekgui->on = 1;
  if (check_file_nb(tekgui) == - 1)
    return (EXIT_ON_ERROR);
  i = 0;
  while (i < tekgui->nb_radio)
    {
      if (tekgui->radio[i].selected != - 1)
	{
	  if ((fct = tekfunction
	       (tekgui->radio[i].butt_fct
		[(int)tekgui->radio[i].selected])) != NULL)
	    fct(tekgui);
	}
      i++;
    }
  return (loop_next(tekgui));
}

t_bunny_response	mouse_move(const t_bunny_position *move,
				   void *data)
{
  (void)move;
  (void)data;
  return (GO_ON);
}

void	ani_text_changer(t_tekgui *tekgui)
{
  int	i;

  i = 0;
  if (tekgui->animation == 1)
    {
      while (tekgui->texter[(int)tekgui->focus_text].text[i])
	{
	  tekgui->ani->text[i] = tekgui->texter[(int)tekgui->focus_text].text[i];
	  i++;
	}
      tekgui->ani->text[i] = 0;
      tekgui->texter[(int)tekgui->focus_text].text[0] = 0;
    }
}
