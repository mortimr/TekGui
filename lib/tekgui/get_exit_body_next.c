/*
** get_exit_body_next.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 13:55:56 2016 Iulian Rotaru
** Last update Mon Feb 29 20:33:03 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	get_exit_body_next(const char *extract,
			   t_tekgui *tekgui, int i)
{
  char	getter[10];
  int	j;

  i++;
  j = 0;
  while (extract[i] && extract[i] != ':')
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->body.exit[1].x = my_getnbr(getter)) <= 0)
    return (- 1);
  i++;
  j = 0;
  while (extract[i] && extract[i] != ':')
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->body.exit[1].y = my_getnbr(getter)) <= 0)
    return (- 1);
  return (0);
}

int	get_exit_body(const char *extract, t_tekgui *tekgui)
{
  char	getter[10];
  int	i;
  int	j;

  i = 0;
  while (extract[i] && extract[i] != ':' && i < 100)
    i++;
  if (extract[i] != ':')
    return (- 1);
  i++;
  j = 0;
  while (extract[i] && extract[i] != ':' && j < 100)
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->body.exit[0].x = my_getnbr(getter)) >= 0)
    return (- 1);
  i++;
  j = 0;
  while (extract[i] && extract[i] != ':' && j < 100)
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->body.exit[0].y = my_getnbr(getter)) >= 0)
    return (- 1);
  return (get_exit_body_next(extract, tekgui, i));
}

char	*my_strdup(char *test)
{
  char	*dest;
  int	i;

  if ((dest = bunny_malloc(sizeof(char) * my_strlen(test))) == NULL)
    return (NULL);
  i = 0;
  while (test[i])
    {
      dest[i] = test[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

int	get_title_body(const char *extract, t_tekgui *tekgui)
{
  char	getter[100];
  int	i;
  int	j;

  i = 0;
  while (extract[i] && extract[i] != ':' && i < 100)
    i++;
  if (extract[i] != ':')
    return (- 1);
  i++;
  j = 0;
  while (extract[i] && j < 100)
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->body.title = my_strdup(getter)) == NULL)
    return (- 1);
  return (0);
}

int		load_body_data(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "body", i)) == NULL)
    return (- 1);
  while (extract)
    {
      if (my_strcmp_start("size:", extract) == 0)
	if (get_size_body(extract, tekgui) == - 1)
	  return (- 1);
      if (my_strcmp_start("exit:", extract) == 0)
	if (get_exit_body(extract, tekgui) == - 1)
	  return (- 1);
      if (my_strcmp_start("title:", extract) == 0)
	if (get_title_body(extract, tekgui) == - 1)
	  return (- 1);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "body", i);
    }
  return (0);
}
