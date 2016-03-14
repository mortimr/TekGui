/*
** fill_button.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 14:07:54 2016 Iulian Rotaru
** Last update Mon Feb 29 12:35:57 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	fill_button(const char *extract, t_tekgui *tekgui, int i)
{
  int	x;
  int	y;
  char	getter[100];

  x = 0;
  y = 0;
  while (extract[x] != ':' && extract[x])
    {
      getter[x] = extract[x];
      x++;
    }
  getter[x] = 0;
  x++;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->button[i].name = my_strdup(getter)) == NULL))
    return (- 1);
  while (extract[x] != ':' && extract[x])
    getter[y++] = extract[x++];
  getter[y] = 0;
  x++;
  if (((tekgui->button[i].x = my_getnbr(getter)) < 0) ||
      (tekgui->button[i].x > tekgui->body.width))
    return (- 1);
  return (fill_button_next(x, extract, tekgui, i));
}

int		load_buttons_next(t_bunny_ini *ini, t_tekgui *tekgui)
{
  int		i;
  const char	*extract;

  i = 0;
  extract = bunny_ini_get_field(ini, NULL, "button", i);
  while (extract)
    {
      if (fill_button(extract, tekgui, i) == - 1)
	return (- 1);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "button", i);
    }
  return (0);
}

int		load_buttons(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "button", i)) == NULL)
    {
      tekgui->nb_buttons = 0;
      return (0);
    }
  while (extract)
    {
      i++;
      extract = bunny_ini_get_field(ini, NULL, "button", i);
    }
  if ((tekgui->button = bunny_malloc(sizeof(t_button) * i)) == NULL)
    return (- 1);
  tekgui->nb_buttons = i;
  return (load_buttons_next(ini, tekgui));
}

int	my_strcmp(const char *one, const char *two)
{
  int	i;

  i = 0;
  while (one[i] && two[i])
    {
      if (one[i] != two[i])
	return (1);
      i++;
    }
  if (one[i] != two[i])
    return (1);
  return (0);
}

int		load_plugins(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;

  i = 0;
  extract = bunny_ini_get_field(ini, NULL, "plugin", i);
  tekgui->animation = 0;
  while (extract)
    {
      if (my_strcmp("animation", extract) == 0)
	{
	  tekgui->animation = 1;
	  if ((tekgui->ani = bunny_malloc(sizeof(t_ani))) == NULL)
	    return (- 1);
	}
      i++;
      extract = bunny_ini_get_field(ini, NULL, "plugin", i);
    }
  return (0);
}
