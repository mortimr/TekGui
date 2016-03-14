/*
** loader.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb  2 20:29:39 2016 Iulian Rotaru
** Last update Mon Feb 29 12:48:47 2016 Iulian Rotaru
*/

#include "tekgui.h"

t_tekgui	*tekgui_load(const char *file)
{
  t_bunny_ini	*ini;
  t_tekgui	*tekgui;

  if ((ini = bunny_load_ini(file)) == NULL)
    return (NULL);
  if (load_config() == - 1)
    return (NULL);
  if ((tekgui = bunny_malloc(sizeof(t_tekgui))) == NULL)
    return (NULL);
  if (load_objects(ini, tekgui) == - 1)
    return (NULL);
  animation_setup(tekgui);
  tekgui->on = 0;
  tekgui->move = 0;
  tekgui->scroll = 0;
  tekgui->selection_done = 0;
  if ((tekgui->current = my_strdup(".")) == NULL)
    return (NULL);
  return (tekgui);
}

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
