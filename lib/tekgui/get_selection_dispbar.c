/*
** get_selection_dispbar.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 17:41:53 2016 Iulian Rotaru
** Last update Mon Feb 29 12:46:57 2016 Iulian Rotaru
*/

#include "tekgui.h"

int		get_selection_dispbar(t_tekgui *tekgui)
{
  int		i;
  DIR		*current;
  struct dirent	*buff;

  if ((current = opendir(tekgui->current)) == NULL)
    return (- 1);
  i = 0;
  if ((buff = readdir(current)) == NULL)
    return (- 1);
  while (i < tekgui->scroll)
    {
      if ((buff = readdir(current)) == NULL)
	return (- 1);
      i++;
    }
  i = 0;
  while (i < tekgui->search_select && buff)
    {
      buff = readdir(current);
      i++;
    }
  if ((tekgui->displayer->bar.auto_fill = my_strdup(buff->d_name)) == NULL)
    return (- 1);
  get_selection_dispbar_next(current, tekgui);
  return (0);
}

int				search_box(t_tekgui *tekgui,
					   t_bunny_pixelarray *pix)
{
  static int			loader;
  static t_bunny_position	pos;

  if (loader == 0)
    {
      if (load_menu_bmp(tekgui) == - 1)
	return (- 1);
      loader++;
      pos.x = (pix->clipable.clip_width -
	       tekgui->searcher[(int)tekgui->move]->clipable.clip_width) / 2;
      pos.y = (pix->clipable.clip_height -
	       tekgui->searcher[(int)tekgui->move]->clipable.clip_height) / 2;
    }
  fade_body(tekgui, pix, 0);
  my_bunny_blit_theme(pix, tekgui->searcher[(int)tekgui->move], &pos, tekgui);
  if (display_text(tekgui, pix) == - 1)
    return (- 1);
  if (tekgui->search_select != - 1)
    {
      if (get_selection_dispbar(tekgui) == - 1)
	return (- 1);
      tekgui->search_select = -1;
    }
  return (0);
}

int	assembling_dispbar_next_else(t_tekgui *tekgui,
				     char *mix)
{
  bunny_free(tekgui->current);
  tekgui->current = mix;
  tekgui->selection_done = 0;
  tekgui->scroll = 0;
  return (0);
}

int	assembling_dispbar_next(t_tekgui *tekgui,
				char *mix)
{
  int	i;

  if (opendir(mix) == NULL)
    {
      i = 0;
      while (i < 1024)
	tekgui->displayer->bar.search[i++] = 0;
      i = 0;
      while (my_strlen(mix) < 1000 && mix[i])
	{
	  tekgui->displayer->bar.search[i] = mix[i];
	  i++;
	}
      bunny_free(mix);
      tekgui->selection_done = 2;
      bunny_free(tekgui->current);
      if ((tekgui->current = my_strdup(".")) == NULL)
	return (- 1);
      tekgui->scroll = 0;
      fade_body(NULL, NULL, 1);
    }
  else
    assembling_dispbar_next_else(tekgui, mix);
  return (0);
}

int	assembling_dispbar(t_tekgui *tekgui)
{
  char	*mix;
  int	i;
  int	j;

  if ((mix =
       bunny_malloc(sizeof(char) *
		    (my_strlen(tekgui->current)
		     + my_strlen(tekgui->displayer->bar.auto_fill)
		     + 2))) == NULL)
    return (- 1);
  i = 0;
  while (tekgui->current[i])
    {
      mix[i] = tekgui->current[i];
      i++;
    }
  mix[i++] = '/';
  j = 0;
  while (tekgui->displayer->bar.auto_fill[j])
    mix[i++] = tekgui->displayer->bar.auto_fill[j++];
  mix[i] = 0;
  if (assembling_dispbar_next(tekgui, mix) == - 1)
    return (- 1);
  bunny_free(tekgui->displayer->bar.auto_fill);
  return (0);
}
