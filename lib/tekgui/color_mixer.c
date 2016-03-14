/*
** color_mixer.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:52:56 2016 Iulian Rotaru
** Last update Fri Feb 26 22:49:28 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	set_start_nb(t_bunny_position *pos, t_text *text, int ratio, int j)
{
  pos[2].x = text->pos.x + (ratio * 6 * j);
  pos[2].y = text->pos.y;
  pos[0].y = 0;
  pos[1].y = text->y;
}
