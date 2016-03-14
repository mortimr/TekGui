/*
** fill_cases_next_next_next.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 14:19:45 2016 Iulian Rotaru
** Last update Mon Feb 29 20:31:35 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	fill_cases_next_next_next(int x,
				  const char *extract,
				  t_tekgui *tekgui,
				  int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->cases[i].fct_on = my_strdup(getter)) == NULL))
    return (- 1);
  tekgui->cases[i].active = 0;
  return (0);
}

int	fill_cases_next_next(int x,
			     const char *extract,
			     t_tekgui *tekgui,
			     int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->cases[i].dim.y = my_getnbr(getter)) < 0) ||
      (tekgui->cases[i].pos.y + tekgui->cases[i].dim.y > tekgui->body.height))
    return (- 1);
  x++;
  y = 0;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->cases[i].fct_off = my_strdup(getter)) == NULL))
    return (- 1);
  x++;
  return (fill_cases_next_next_next(x, extract, tekgui, i));
}

int	fill_cases_next(int x,
			const char *extract,
			t_tekgui *tekgui,
			int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->cases[i].pos.y = my_getnbr(getter)) < 0) ||
      (tekgui->cases[i].pos.y > tekgui->body.height))
    return (- 1);
  x++;
  y = 0;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->cases[i].dim.x = my_getnbr(getter)) < 0) ||
      (tekgui->cases[i].pos.x + tekgui->cases[i].dim.x > tekgui->body.width))
    return (- 1);
  x++;
  return (fill_cases_next_next(x, extract, tekgui, i));
}

int	fill_cases(const char *extract,
		   t_tekgui *tekgui,
		   int i)
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
      ((tekgui->cases[i].name = my_strdup(getter)) == NULL))
    return (- 1);
  x++;
  y = 0;
  while (extract[x] && extract[x] != ':' && y < 100)
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->cases[i].pos.x = my_getnbr(getter)) < 0) ||
      (tekgui->cases[i].pos.x > tekgui->body.width))
    return (- 1);
  x++;
  return (fill_cases_next(x, extract, tekgui, i));
}

int		get_cases_data(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;

  i = 0;
  extract = bunny_ini_get_field(ini, NULL, "case", i);
  while (extract)
    {
      if (fill_cases(extract, tekgui, i) == - 1)
	return (- 1);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "case", i);
    }
  return (0);
}
