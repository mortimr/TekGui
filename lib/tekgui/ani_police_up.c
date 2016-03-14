/*
** ani_police_up.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:24:40 2016 Iulian Rotaru
** Last update Mon Feb 29 20:27:19 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	ani_police_up(t_tekgui *tekgui)
{
  if (tekgui->animation == 1 && tekgui->ani->police < 150)
    tekgui->ani->police += 7;
}

void	ani_police_down(t_tekgui *tekgui)
{
  if (tekgui->animation == 1 && tekgui->ani->police - 7 > 7)
    tekgui->ani->police -= 7;
}

void	fill_pix(t_bunny_pixelarray *pix, unsigned int color)
{
  int	i;

  i = 0;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height)
    {
      ((unsigned int*)pix->pixels)[i] = color;
      i++;
    }
}

void		area_show_speed(t_tekgui *tekgui, t_area *area)
{
  t_text	text;

  if (tekgui->animation == 1)
    {
      text.x = 5;
      text.y = 7;
      text.police_size = 21;
      text.pos.x = (tekgui->pix->clipable.clip_width
		    - tekgui->body.width) / 2 + area->pos.x + 5;
      text.pos.y = (tekgui->pix->clipable.clip_height
		    - tekgui->body.height) / 2 + area->pos.y + 5;
      text.fg = tekgui->theme[tekgui->actu_theme - 1].text.full;
      my_blitnbr(tekgui->ani->move_speed,
		 tekgui->pix, tekgui->font, &text);
    }
}

void		area_show_police(t_tekgui *tekgui, t_area *area)
{
  t_text	text;

  if (tekgui->animation == 1)
    {
      text.x = 5;
      text.y = 7;
      text.police_size = 21;
      text.pos.x = (tekgui->pix->clipable.clip_width
		    - tekgui->body.width) / 2 + area->pos.x + 5;
      text.pos.y = (tekgui->pix->clipable.clip_height
		    - tekgui->body.height) / 2 + area->pos.y + 5;
      text.fg = tekgui->theme[tekgui->actu_theme - 1].text.full;
      my_blitnbr(tekgui->ani->police,
		 tekgui->pix, tekgui->font, &text);
    }
}
