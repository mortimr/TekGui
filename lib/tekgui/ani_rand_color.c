/*
** ani_rand_color.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:25:58 2016 Iulian Rotaru
** Last update Sun Feb 28 12:45:00 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	ani_rand_color(t_tekgui *tekgui)
{
  if (tekgui->animation == 1)
    {
      tekgui->ani->bg = rand() | BLACK;
      tekgui->ani->fg = rand() | BLACK;
    }
}

void	ani_speed_up(t_tekgui *tekgui)
{
  if (tekgui->animation == 1)
    {
      if (tekgui->ani->move_speed < 100)
	tekgui->ani->move_speed++;
    }
}

void	ani_speed_down(t_tekgui *tekgui)
{
  if (tekgui->animation == 1)
    {
      if (tekgui->ani->move_speed > 1)
	tekgui->ani->move_speed--;
    }
}

void	ani_play_else(t_text *text, t_tekgui *tekgui)
{
  if (tekgui->ani->invert == 1)
    {
      fill_pix(tekgui->pix, invert_colors(WHITE, tekgui->ani->bg));
      text->fg = invert_colors(WHITE, tekgui->ani->fg);
    }
  else
    {
      fill_pix(tekgui->pix, tekgui->ani->bg);
      text->fg = tekgui->ani->fg;
    }
}

void	ani_play_core(t_text *text,
		      int *call,
		      int *increm,
		      t_tekgui *tekgui)
{
  text->x = 5;
  text->y = 7;
  text->police_size = tekgui->ani->police;
  text->pos.x = - my_strlen(tekgui->ani->text)
    * (text->police_size / 7) * 6 + *increm * tekgui->ani->move_speed;
  text->pos.y = tekgui->pix->clipable.clip_height / 2
    - ((text->police_size / 7) * 7) / 2;
  my_blitstr(tekgui->ani->text, tekgui->pix, tekgui->font, text);
  *increm += 1;
  if (text->pos.x > tekgui->pix->clipable.clip_width)
    {
      *call = 0;
      tekgui->on = 0;
      *increm = 0;
    }
}
