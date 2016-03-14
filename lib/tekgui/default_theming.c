/*
** default_theming.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 13:57:08 2016 Iulian Rotaru
** Last update Mon Feb 29 12:28:05 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	default_theming(t_bunny_ini *ini, t_tekgui *tekgui)
{
  (void)ini;
  tekgui->nb_theme = 1;
  tekgui->actu_theme = 1;
  if ((tekgui->theme = bunny_malloc(sizeof(t_theme))) == NULL)
    return (- 1);
  tekgui->theme[0].one.full = 0x66666666;
  tekgui->theme[0].two.full = 0x77777777;
  tekgui->theme[0].text.full = 0xFFBBBBBB;
  tekgui->theme[0].name = my_strdup("Basic");
  return (0);
}

int	fill_theme_next(const char *extract, t_tekgui *tekgui, int x, int i)
{
  int	j;
  char	getter[100];

  j = 0;
  while (extract[i] != ':' && extract[i] && j < 100)
    getter[j++] = extract[i++];
  getter[j] = 0;
  if (my_strlen(getter) == 0)
    return (- 1);
  tekgui->theme[x].two.full = my_getunbr(getter);
  i++;
  j = 0;
  while (extract[i] != ':' && extract[i] && j < 100)
    getter[j++] = extract[i++];
  getter[j] = 0;
  if (my_strlen(getter) == 0)
    return (- 1);
  tekgui->theme[x].text.full = my_getunbr(getter);
  return (0);
}

int	fill_theme(const char *extract, t_tekgui *tekgui, int x)
{
  char	getter[100];
  int	i;
  int	j;

  i = 0;
  while (extract[i] != ':' && extract[i] && i < 100)
    {
      getter[i] = extract[i];
      i++;
    }
  getter[i] = 0;
  if ((tekgui->theme[x].name = my_strdup(getter)) == NULL)
    return (- 1);
  i++;
  j = 0;
  while (extract[i] != ':' && extract[i] && j < 100)
    getter[j++] = extract[i++];
  getter[j] = 0;
  if (my_strlen(getter) == 0)
    return (- 1);
  tekgui->theme[x].one.full = my_getunbr(getter);
  i++;
  return (fill_theme_next(extract, tekgui, x, i));
}

int		get_themes(t_bunny_ini *ini, t_tekgui *tekgui, int i)
{
  int		x;
  const char	*extract;

  (void)i;
  x = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "theme", x)) == NULL)
    return (- 1);
  while (extract)
    {
      if (fill_theme(extract, tekgui, x) == - 1)
	return (- 1);
      x++;
      extract = bunny_ini_get_field(ini, NULL, "theme", x);
    }
  return (0);
}

int		load_theme_data(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "theme", i)) == NULL)
    return (default_theming(ini, tekgui));
  while (extract)
    {
      i++;
      extract = bunny_ini_get_field(ini, NULL, "theme", i);
    }
  if ((tekgui->theme = bunny_malloc(sizeof(t_theme) * i)) == NULL)
    return (- 1);
  tekgui->nb_theme = i;
  tekgui->actu_theme = 1;
  return (get_themes(ini, tekgui, i));
}
