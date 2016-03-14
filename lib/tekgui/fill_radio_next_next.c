/*
** fill_radio_next_next.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 14:18:25 2016 Iulian Rotaru
** Last update Mon Feb 29 12:39:29 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	fill_radio_next_next(int x, const char *extract, t_tekgui *tekgui, int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->radio[i].dim.y = my_getnbr(getter)) < 0) ||
      (tekgui->radio[i].dim.y
       + tekgui->radio[i].pos.y > tekgui->body.width))
    return (- 1);
  y = 0;
  x++;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->radio[i].nb_butt = my_getnbr(getter)) <= 0) ||
      (tekgui->radio[i].nb_butt > 5))
    return (- 1);
  x++;
  return (fill_button_radio(extract, x, tekgui, i));
}

int	fill_radio_next(int x, const char *extract, t_tekgui *tekgui, int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->radio[i].pos.y = my_getnbr(getter)) < 0) ||
      (tekgui->radio[i].pos.y > tekgui->body.height))
    return (- 1);
  y = 0;
  x++;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->radio[i].dim.x = my_getnbr(getter)) < 0) ||
      (tekgui->radio[i].dim.x
       + tekgui->radio[i].pos.x > tekgui->body.width))
    return (- 1);
  x++;
  return (fill_radio_next_next(x, extract, tekgui, i));
}

int	fill_radio(const char *extract, t_tekgui *tekgui, int i)
{
  int	x;
  int	y;
  char	getter[100];

  x = 0;
  while (extract[x] && extract[x] != ':' && x < 100)
    {
      getter[x] = extract[x];
      x++;
    }
  getter[x] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->radio[i].title = my_strdup(getter)) == NULL))
    return (- 1);
  y = 0;
  x++;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->radio[i].pos.x = my_getnbr(getter)) < 0) ||
      (tekgui->radio[i].pos.x > tekgui->body.width))
    return (- 1);
  x++;
  return (fill_radio_next(x, extract, tekgui, i));
}

int		get_radio_data(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "radio", i)) == NULL)
    return (- 1);
  while (i < tekgui->nb_radio && extract)
    {
      if (fill_radio(extract, tekgui, i) == - 1)
	return (- 1);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "radio", i);
    }
  return (0);
}

int		load_radio(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "radio", i)) == NULL)
    {
      tekgui->nb_radio = i;
      return (0);
    }
  while (extract)
    {
      i++;
      extract = bunny_ini_get_field(ini, NULL, "radio", i);
    }
  if ((tekgui->radio = bunny_malloc(sizeof(t_radio) * i)) == NULL)
    return (- 1);
  tekgui->nb_radio = i;
  if (get_radio_data(ini, tekgui) == - 1)
    return (- 1);
  return (0);
}
