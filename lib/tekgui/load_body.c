/*
** load_body.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 13:58:08 2016 Iulian Rotaru
** Last update Mon Feb 29 12:50:01 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	load_body(t_bunny_ini *ini, t_tekgui *tekgui)
{
  if (bunny_ini_get_field(ini, NULL, "body", 0) == NULL)
    return (- 1);
  if (check_body(ini) == 1)
    return (- 1);
  if (load_body_data(ini, tekgui) == - 1)
    return (- 1);
  if (load_theme_data(ini, tekgui) == - 1)
    return (- 1);
  if ((tekgui->font = bunny_load_pixelarray("../textures/font.png")) == NULL)
    return (- 1);
  return (0);
}

int	fill_displayer_size(const char *extract,
			    t_tekgui *tekgui)
{
  char	getter[100];
  int	i;
  int	j;

  i = 0;
  while (extract[i] != ':' && extract[i] && i < 100)
    i++;
  if (extract[i] == '\0')
    return (- 1);
  j = 0;
  i++;
  while (extract[i] != ':' && extract[i] && j < 100)
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->displayer->width = my_getnbr(getter)) <= 0)
    return (- 1);
  j = 0;
  i++;
  while (extract[i] != ':' && extract[i] && j < 100)
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->displayer->height = my_getnbr(getter)) <= 0)
    return (- 1);
  tekgui->displayer->scroll = 0;
  return (0);
}

int	fill_displayer_pos(const char *extract,
			   t_tekgui *tekgui)
{
  char	getter[10];
  int	i;
  int	j;

  i = 0;
  while (extract[i] != ':' && extract[i])
    i++;
  if (extract[i] == '\0')
    return (- 1);
  j = 0;
  i++;
  while (extract[i] != ':' && extract[i])
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->displayer->x = my_getnbr(getter)) <= 0)
    return (- 1);
  j = 0;
  i++;
  while (extract[i] != ':' && extract[i])
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->displayer->y = my_getnbr(getter)) <= 0)
    return (- 1);
  return (0);
}

int	fill_displayer_bar(const char *extract,
			   t_tekgui *tekgui)
{
  char	getter[10];
  int	i;
  int	j;

  i = 0;
  while (extract[i] != ':' && extract[i])
    i++;
  if (extract[i] == '\0')
    return (- 1);
  j = 0;
  i++;
  while (extract[i] != ':' && extract[i])
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->displayer->bar.width = my_getnbr(getter)) <= 0)
    return (- 1);
  j = 0;
  i++;
  while (extract[i] != ':' && extract[i])
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->displayer->bar.height = my_getnbr(getter)) <= 0)
    return (- 1);
  return (0);
}

int	fill_displayer_barpos_next(t_tekgui *tekgui)
{
  int	i;

  i = 0;
  while (i < 100)
    tekgui->displayer->bar.search[i++] = 0;
  tekgui->search_select = - 1;
  tekgui->displayer->bar.focus = 0;
  return (0);
}
