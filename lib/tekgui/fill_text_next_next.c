/*
** fill_text_next_next.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 14:16:05 2016 Iulian Rotaru
** Last update Mon Feb 29 20:32:25 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	fill_text_next_next(int x,
			    const char *extract,
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
      ((tekgui->texter[i].fct = my_strdup(getter)) == NULL))
    return (- 1);
  tekgui->focus_text = - 1;
  return (0);
}

int	fill_text_next(int x,
		       const char *extract,
		       t_tekgui *tekgui,
		       int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] && extract[x] != ':')
    getter[y++] = extract[x++];
  getter[y] = 0;
  if ((tekgui->texter[i].dim.x = my_getnbr(getter)) <= 0)
    return (- 1);
  y = 0;
  x++;
  while (extract[x] && extract[x] != ':')
    getter[y++] = extract[x++];
  getter[y] = 0;
  if ((tekgui->texter[i].dim.y = my_getnbr(getter)) <= 0)
    return (- 1);
  x++;
  return (fill_text_next_next(x, extract, tekgui, i));
}

int	fill_text(const char *extract,
		  t_tekgui *tekgui,
		  int i)
{
  int	x;
  int	y;
  char	getter[100];

  x = 0;
  while (extract[x] && extract[x] != ':')
    {
      getter[x] = extract[x];
      x++;
    }
  getter[x] = 0;
  if ((tekgui->texter[i].pos.x = my_getnbr(getter)) < 0)
    return (- 1);
  y = 0;
  x++;
  while (extract[x] && extract[x] != ':')
    getter[y++] = extract[x++];
  getter[y] = 0;
  if ((tekgui->texter[i].pos.y = my_getnbr(getter)) < 0)
    return (- 1);
  x++;
  return (fill_text_next(x, extract, tekgui, i));
}

int		get_text_data(t_bunny_ini *ini, t_tekgui *tekgui)
{
  int		i;
  const char	*extract;

  i = 0;
  extract = bunny_ini_get_field(ini, NULL, "text", i);
  while (extract)
    {
      if (fill_text(extract, tekgui, i) == - 1)
	return (- 1);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "text", i);
    }
  return (0);
}

int		load_text(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;

  i = 0;
  extract = bunny_ini_get_field(ini, NULL, "text", i);
  while (extract)
    {
      i++;
      extract = bunny_ini_get_field(ini, NULL, "text", i);
    }
  if ((tekgui->texter = bunny_malloc(sizeof(t_texter) * i)) == NULL)
    return (- 1);
  tekgui->nb_text = i;
  if (get_text_data(ini, tekgui) == - 1)
    return (- 1);
  return (0);
}
