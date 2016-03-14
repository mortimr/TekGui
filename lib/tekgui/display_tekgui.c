/*
** display_tekgui.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb  2 22:03:53 2016 Iulian Rotaru
** Last update Thu Feb 25 17:50:57 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	tekgui_display_sec(t_bunny_pixelarray *pix, t_tekgui *tekgui)
{
  int	i;
  void	(*fct)(t_tekgui*, t_area*);

  i = 0;
  (void)pix;
  if (tekgui->nb_areas > 0)
    {
      while (i < tekgui->nb_areas)
	{
	  if ((fct = tek_area_fct(tekgui->area[i].fct)) != NULL)
	    fct(tekgui, &tekgui->area[i]);
	  i++;
	}
    }
}

void	tekgui_display_core(t_bunny_pixelarray *pix, t_tekgui *tekgui)
{
  if (tekgui->on == 5)
    ani_play(tekgui);
  else
    {
      display_body(tekgui, pix);
      tekgui_display_first(pix, tekgui);
      display_area(tekgui, pix);
      tekgui_display_sec(pix, tekgui);
      if (tekgui->on == 1)
	{
	  display_exit_box(tekgui, pix, 1);
	}
      else
	display_exit_box(tekgui, pix, 0);
      display_buttons(tekgui, pix);
      display_text_field(tekgui, pix);
      display_radio_button(tekgui, pix);
      display_cases_button(tekgui, pix);
    }
}

void	tekgui_display(t_bunny_pixelarray *pix,
		       t_tekgui *tekgui)
{
  if (pix != NULL && tekgui != NULL)
    {
      if (tekgui->pix == NULL)
	tekgui->pix = pix;
      background_manager(pix);
      if (tekgui->on != - 1)
	tekgui_display_core(pix, tekgui);
    }
}
