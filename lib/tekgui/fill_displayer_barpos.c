/*
** fill_displayer_barpos.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 14:04:28 2016 Iulian Rotaru
** Last update Mon Feb 29 12:38:37 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	fill_displayer_barpos(const char *extract, t_tekgui *tekgui)
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
  if ((tekgui->displayer->bar.x = my_getnbr(getter)) < 0)
    return (- 1);
  j = 0;
  i++;
  while (extract[i] != ':' && extract[i])
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->displayer->bar.y = my_getnbr(getter)) < 0)
    return (- 1);
  return (fill_displayer_barpos_next(tekgui));
}

int	fill_displayer_fct(const char *extract, t_tekgui *tekgui)
{
  int	i;
  int	j;
  char	getter[100];

  i = 0;
  while (extract[i] != ':')
    i++;
  i++;
  j = 0;
  while (extract[i])
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->displayer->fct = my_strdup(getter)) == NULL))
    return (- 1);
  return (0);
}

int	read_displayer_data_next(const char *extract, t_tekgui *tekgui)
{
  if ((my_strcmp_start("pos:", extract) == 0) &&
      (fill_displayer_pos(extract, tekgui) == - 1))
    return (- 1);
  if ((my_strcmp_start("size:", extract) == 0) &&
      (fill_displayer_size(extract, tekgui) == - 1))
    return (- 1);
  if ((my_strcmp_start("bar:", extract) == 0) &&
      (fill_displayer_bar(extract, tekgui) == - 1))
    return (- 1);
  if ((my_strcmp_start("barpos:", extract) == 0) &&
      (fill_displayer_barpos(extract, tekgui) == - 1))
    return (- 1);
  if ((my_strcmp_start("fct:", extract) == 0) &&
      (fill_displayer_fct(extract, tekgui) == - 1))
    return (- 1);
  return (0);
}

int		read_displayer_data(t_bunny_ini *ini, t_tekgui *tekgui)
{
  int		i;
  const char	*extract;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "displayer", i)) == NULL)
    return (- 1);
  while (extract)
    {
      if (read_displayer_data_next(extract, tekgui) == - 1)
	return (- 1);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "displayer", i);
    }
  return (0);
}

int	empty_displayer_data(t_bunny_ini *ini, t_tekgui *tekgui)
{
  (void)ini;
  tekgui->displayer->x = tekgui->body.width / 15;
  tekgui->displayer->y = tekgui->body.height / 15;
  tekgui->displayer->width = tekgui->body.width / 2;
  tekgui->displayer->height = tekgui->body.height / 2;
  if ((tekgui->displayer->fct = my_strdup("displayer")) == NULL)
    return (- 1);
  tekgui->displayer->bar.x = 0;
  tekgui->displayer->bar.y = 0;
  tekgui->displayer->bar.width = tekgui->displayer->width;
  tekgui->displayer->bar.height = 50;
  return (0);
}
