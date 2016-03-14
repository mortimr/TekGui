/*
** get_displayer_data_next.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 14:05:51 2016 Iulian Rotaru
** Last update Mon Feb 29 20:32:45 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	get_displayer_data_next(int count, t_bunny_ini *ini, t_tekgui *tekgui)
{
  if (count == 5)
    {
      tekgui->disp = 1;
      if ((tekgui->displayer = bunny_malloc(sizeof(t_displayer))) == NULL)
	return (- 1);
      if (read_displayer_data(ini, tekgui) == - 1)
	return (- 1);
    }
  else
    {
      tekgui->disp = 1;
      if ((tekgui->displayer = bunny_malloc(sizeof(t_displayer))) == NULL)
	return (- 1);
      if (empty_displayer_data(ini, tekgui) == - 1)
	return (- 1);
    }
  return (0);
}

int		get_displayer_data(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;
  int		count;

  i = 0;
  count = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "displayer", i)) == NULL)
    return (- 1);
  while (extract)
    {
      if ((my_strcmp_start("size:", extract) == 0)
	  || (my_strcmp_start("pos:", extract) == 0))
	count++;
      if (my_strcmp_start("bar:", extract) == 0)
	count++;
      if (my_strcmp_start("barpos:", extract) == 0)
	count++;
      if (my_strcmp_start("fct:", extract) == 0)
	count++;
      i++;
      extract = bunny_ini_get_field(ini, NULL, "displayer", i);
    }
  return (get_displayer_data_next(count, ini, tekgui));
}

int	load_builtins(t_bunny_ini *ini, t_tekgui *tekgui)
{
  if (bunny_ini_get_field(ini, NULL, "displayer", 0) != NULL)
    if (get_displayer_data(ini, tekgui) == - 1)
      return (- 1);
  return (0);
}

int	fill_button_next_next(int x, const char *extract, t_tekgui *tekgui, int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] != ':' && extract[x])
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->button[i].height = my_getnbr(getter)) <= 0) ||
      (tekgui->button[i].height + tekgui->button[i].y > tekgui->body.height))
    return (- 1);
  x++;
  y = 0;
  while (extract[x])
    getter[y++] = extract[x++];
  getter[y] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->button[i].para = my_strdup(getter)) == NULL))
    return (- 1);
  return (0);
}

int	fill_button_next(int x, const char *extract, t_tekgui *tekgui, int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[x] != ':' && extract[x])
    getter[y++] = extract[x++];
  getter[y] = 0;
  x++;
  if (((tekgui->button[i].y = my_getnbr(getter)) < 0) ||
      (tekgui->button[i].y > tekgui->body.height))
    return (- 1);
  y = 0;
  while (extract[x] != ':' && extract[x])
    getter[y++] = extract[x++];
  getter[y] = 0;
  if (((tekgui->button[i].width = my_getnbr(getter)) <= 0) ||
      (tekgui->button[i].width + tekgui->button[i].x > tekgui->body.width))
    return (- 1);
  x++;
  return (fill_button_next_next(x, extract, tekgui, i));
}
