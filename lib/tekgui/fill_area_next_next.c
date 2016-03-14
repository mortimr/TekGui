/*
** fill_area_next_next.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 14:14:16 2016 Iulian Rotaru
** Last update Mon Feb 29 12:33:58 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	fill_area_next_next(int x, const char *extract,
			    t_tekgui *tekgui,
			    int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] && extract[x] != ':')
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->area[i].dim.y = my_getnbr(getter)) <= 0) ||
      (tekgui->area[i].dim.y + tekgui->area[i].pos.y > tekgui->body.height))
    return (- 1);
  x++;
  y = 0;
  while (extract[x] && extract[x] != ':')
    getter[y++] = extract[x++];
  getter[y] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->area[i].fct = my_strdup(getter)) == NULL))
    return (- 1);
  return (0);
}

int	fill_area_next(int x, const char *extract,
		       t_tekgui *tekgui,
		       int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] && extract[x] != ':')
    getter[y++] = extract[x++];
  getter[y] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->area[i].pos.y = my_getnbr(getter)) < 0))
    return (- 1);
  x++;
  y = 0;
  while (extract[x] && extract[x] != ':')
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->area[i].dim.x = my_getnbr(getter)) <= 0) ||
      (tekgui->area[i].dim.x + tekgui->area[i].pos.x > tekgui->body.width))
    return (- 1);
  x++;
  return (fill_area_next_next(x, extract, tekgui, i));
}

int	fill_area(const char *extract, t_tekgui *tekgui, int i)
{
  int	x;
  int	y;
  char	getter[100];

  x = 0;
  y = 0;
  while (extract[x] && extract[x] != ':')
    {
      getter[x] = extract[x];
      x++;
    }
  getter[x] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->area[i].name = my_strdup(getter)) == NULL))
    return (- 1);
  x++;
  y = 0;
  while (extract[x] && extract[x] != ':')
    getter[y++] = extract[x++];
  getter[y] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->area[i].pos.x = my_getnbr(getter)) < 0))
    return (- 1);
  x++;
  return (fill_area_next(x, extract, tekgui, i));
}

int		get_area_data(t_bunny_ini *ini, t_tekgui *tekgui)
{
  int		i;
  const char	*extract;

  i = 0;
  extract = bunny_ini_get_field(ini, NULL, "area", i);
  while (i < tekgui->nb_areas)
    {
      if (fill_area(extract, tekgui, i) == - 1)
	return (- 1);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "area", i);
    }
  return (0);
}

int		load_area(t_bunny_ini *ini, t_tekgui *tekgui)
{
  int		i;
  const char	*extract;

  i = 0;
  extract = bunny_ini_get_field(ini, NULL, "area", i);
  while (extract)
    {
      i++;
      extract = bunny_ini_get_field(ini, NULL, "area", i);
    }
  tekgui->nb_areas = i;
  if ((tekgui->area = bunny_malloc(sizeof(t_area) * i)) == NULL)
    return (- 1);
  if (get_area_data(ini, tekgui) == - 1)
    return (- 1);
  return (0);
}
