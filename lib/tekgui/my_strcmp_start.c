/*
** my_strcmp_start.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 13:53:32 2016 Iulian Rotaru
** Last update Mon Feb 29 13:08:41 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	my_strcmp_start(const char *small, const char *big)
{
  int	i;

  i = 0;
  while (small[i] && big[i])
    {
      if (small[i] != big[i])
	return (1);
      i++;
    }
  if (small[i])
    return (1);
  return (0);
}

int		check_body_title(t_bunny_ini *ini)
{
  const char	*extract;
  int		i;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "body", i)) == NULL)
    return (- 1);
  while (extract)
    {
      if (my_strcmp_start("title:", extract) == 0)
	return (0);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "body", i);
    }
  return (1);
}

int		check_body_exit(t_bunny_ini *ini)
{
  const char	*extract;
  int		i;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "body", i)) == NULL)
    return (- 1);
  while (extract)
    {
      if (my_strcmp_start("exit:", extract) == 0)
	if (check_body_title(ini) == 0)
	  return (0);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "body", i);
    }
  return (1);
}

int		check_body(t_bunny_ini *ini)
{
  const char	*extract;
  int		i;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "body", i)) == NULL)
    return (- 1);
  while (extract)
    {
      if (my_strcmp_start("size:", extract) == 0)
	if (check_body_exit(ini) == 0)
	  return (0);
      i++;
      extract = bunny_ini_get_field(ini, NULL, "body", i);
    }
  return (1);
}

int	get_size_body(const char *extract, t_tekgui *tekgui)
{
  char	getter[10];
  int	i;
  int	j;

  i = 0;
  while (extract[i] && extract[i] != ':')
    i++;
  if (extract[i] != ':')
    return (- 1);
  i++;
  j = 0;
  while (extract[i] && extract[i] != ':')
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->body.width = my_getnbr(getter)) <= 0)
    return (- 1);
  j = 0;
  i++;
  while (extract[i] && extract[i] != ':')
    getter[j++] = extract[i++];
  getter[j] = 0;
  if ((tekgui->body.height = my_getnbr(getter)) <= 0)
    return (- 1);
  return (0);
}
