/*
** multi_key.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Feb 28 12:15:13 2016 Iulian Rotaru
** Last update Mon Feb 29 12:54:23 2016 Iulian Rotaru
*/

#include "tekgui.h"

void		multi_key(t_tekgui *tekgui)
{
  static char	theme;

  if (theme == 0 && bunny_get_keyboard()[BKS_T] == 1 &&
      bunny_get_keyboard()[BKS_LCONTROL] == 1)
    {
      theme = 1;
      if (tekgui->nb_theme == tekgui->actu_theme)
	tekgui->actu_theme = 1;
      else
	tekgui->actu_theme++;
    }
  if (theme == 1 && bunny_get_keyboard()[BKS_T] == 0)
    theme = 0;
}

int	key_next_next(t_bunny_event_state state,
		      t_bunny_keysym sym,
		      t_tekgui *tekgui)
{
  if (state == GO_DOWN && sym == BKS_DOWN &&
      tekgui->on == 0 && tekgui->disp == 1)
    tekgui->displayer->scroll++;
  if (state == GO_DOWN && sym == BKS_UP &&
      tekgui->on == 0 && tekgui->disp == 1)
    {
      if (tekgui->displayer->scroll > 0)
	{
	  tekgui->displayer->scroll--;
	}
    }
  return (GO_ON);
}

int	key_next(t_bunny_event_state state,
		 t_bunny_keysym sym,
		 t_tekgui *tekgui)
{
  if (state == GO_DOWN && sym == BKS_UP && tekgui->on == 2)
    {
      if (tekgui->scroll > 0)
	{
	  tekgui->scroll--;
	  if (tekgui->move == 0)
	    tekgui->move = 1;
	  else
	    tekgui->move = 0;
	}
    }
  return (key_next_next(state, sym, tekgui));
}

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *data)
{
  t_tekgui		*tekgui;

  tekgui = (t_tekgui*)data;
  if (state == GO_DOWN && sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  multi_key(tekgui);
  if (state == GO_DOWN && sym == BKS_DOWN && tekgui->on == 2)
    {
      if (tekgui->nb_files > 8 &&
	  tekgui->nb_files - tekgui->scroll > 8)
	{
	  tekgui->scroll++;
	  if (tekgui->move == 0)
	    tekgui->move = 1;
	  else
	    tekgui->move = 0;
	}
    }
  return (key_next(state, sym, tekgui));
}

int		check_file_nb(t_tekgui *tekgui)
{
  DIR		*current;
  struct dirent	*buff;
  int		i;

  i = 0;
  if ((current = opendir(tekgui->current)) == NULL)
    return (- 1);
  buff = readdir(current);
  while (buff)
    {
      i++;
      buff = readdir(current);
    }
  tekgui->nb_files = i;
  closedir(current);
  return (0);
}
