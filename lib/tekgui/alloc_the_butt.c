/*
** alloc_the_butt.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 14:17:12 2016 Iulian Rotaru
** Last update Thu Feb 25 14:34:14 2016 Iulian Rotaru
*/

#include "tekgui.h"

int	alloc_the_butt(t_tekgui *tekgui, int i)
{
  if ((tekgui->radio[i].butt_pos =
       bunny_malloc(sizeof(t_bunny_position) *
		    tekgui->radio[i].nb_butt)) == NULL)
    return (- 1);
  if ((tekgui->radio[i].butt_realpos =
       bunny_malloc(sizeof(t_bunny_position) *
		    tekgui->radio[i].nb_butt)) == NULL)
    return (- 1);
  if ((tekgui->radio[i].butt_dim =
       bunny_malloc(sizeof(t_bunny_position) *
		    tekgui->radio[i].nb_butt)) == NULL)
    return (- 1);
  if ((tekgui->radio[i].butt_titles =
       bunny_malloc(sizeof(char*) *
		    tekgui->radio[i].nb_butt)) == NULL)
    return (- 1);
  if ((tekgui->radio[i].butt_fct =
       bunny_malloc(sizeof(char*) *
		    tekgui->radio[i].nb_butt)) == NULL)
    return (- 1);
  return (0);
}

int	fill_button_radio_next_next_next(const char *extract,
					 int *j,
					 t_tekgui *tekgui,
					 int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[j[1]] && extract[j[1]] != ':' && y < 100)
    getter[y++] = extract[j[1]++];
  getter[y] = 0;
  if ((my_strlen(getter) == 0) ||
      ((tekgui->radio[i].butt_fct[j[0]] = my_strdup(getter)) == NULL))
    return (- 1);
  j[1]++;
  return (0);
}

int	fill_button_radio_next_next(const char *extract,
				    int *j,
				    t_tekgui *tekgui,
				    int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[j[1]] && extract[j[1]] != ':' && y < 100)
    getter[y++] = extract[j[1]++];
  getter[y] = 0;
  if (((tekgui->radio[i].butt_dim[j[0]].x = my_getnbr(getter)) < 0) ||
      (tekgui->radio[i].butt_pos[j[0]].x +
       tekgui->radio[i].butt_dim[j[0]].x > tekgui->body.width))
    return (- 1);
  j[1]++;
  y = 0;
  while (extract[j[1]] && extract[j[1]] != ':' && y < 100)
    getter[y++] = extract[j[1]++];
  getter[y] = 0;
  if (((tekgui->radio[i].butt_dim[j[0]].y = my_getnbr(getter)) < 0) ||
      (tekgui->radio[i].butt_pos[j[0]].y +
       tekgui->radio[i].butt_dim[j[0]].y > tekgui->body.height))
    return (- 1);
  j[1]++;
  return (fill_button_radio_next_next_next(extract, j, tekgui, i));
}

int	fill_button_radio_next(const char *extract, int *j, t_tekgui *tekgui, int i)
{
  int	y;
  char	getter[100];

  y = 0;
  while (extract[j[1]] && extract[j[1]] != ':' && y < 100)
    getter[y++] = extract[j[1]++];
  getter[y] = 0;
  if ((tekgui->radio[i].butt_pos[j[0]].x = my_getnbr(getter)) < 0)
    return (- 1);
  j[1]++;
  y = 0;
  while (extract[j[1]] && extract[j[1]] != ':' && y < 100)
    getter[y++] = extract[j[1]++];
  getter[y] = 0;
  if ((tekgui->radio[i].butt_pos[j[0]].y = my_getnbr(getter)) < 0)
    return (- 1);
  j[1]++;
  return (fill_button_radio_next_next(extract, j, tekgui, i));
}

int	fill_button_radio(const char *extract, int x, t_tekgui *tekgui, int i)
{
  int	j[2];
  int	y;
  char	getter[100];

  if (alloc_the_butt(tekgui, i) == - 1)
    return (- 1);
  j[1] = x;
  j[0] = 0;
  while (j[0] < tekgui->radio[i].nb_butt)
    {
      y = 0;
      while (extract[j[1]] && extract[j[1]] != ':' && y < 100)
	getter[y++] = extract[j[1]++];
      getter[y] = 0;
      if ((my_strlen(getter) == 0) ||
	  ((tekgui->radio[i].butt_titles[j[0]] = my_strdup(getter)) == NULL))
	return (- 1);
      j[1]++;
      if (fill_button_radio_next(extract, j, tekgui, i) == - 1)
	return (- 1);
      j[0]++;
    }
  tekgui->radio[i].selected = - 1;
  return (0);
}
