/*
** get_base_nb.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Feb 28 12:24:49 2016 Iulian Rotaru
** Last update Mon Feb 29 12:41:36 2016 Iulian Rotaru
*/

#include "tekgui.h"

unsigned int	get_base_nb(char *base, char c)
{
  int		i;

  i = 0;
  while (base[i])
    {
      if (c == base[i])
	return (i);
      i++;
    }
  return (0);
}

unsigned int	my_get_hexa(char *nb)
{
  int		i;
  int		start;
  int		multi;
  unsigned int	out;
  char		*base;

  base = "0123456789ABCDEF";
  start = 0;
  multi = 1;
  if (my_strcmp_start("0x", nb) == 0)
    start = 2;
  i = my_strlen(nb) - 1;
  out = 0;
  while (i >= start)
    {
      out += get_base_nb(base, nb[i]) * multi;
      i--;
      multi *= 16;
    }
  return (out);
}

void	ani_change_fg(t_tekgui *tekgui)
{
  if (tekgui->animation == 1)
    {
      tekgui->ani->fg = my_get_hexa
	(tekgui->texter[(int)tekgui->focus_text].text);
      tekgui->texter[(int)tekgui->focus_text].text[0] = 0;
    }
}

void	ani_change_bg(t_tekgui *tekgui)
{
  if (tekgui->animation == 1)
    {
      tekgui->ani->bg = my_get_hexa
	(tekgui->texter[(int)tekgui->focus_text].text);
      tekgui->texter[(int)tekgui->focus_text].text[0] = 0;
    }
}

void	typing_next(uint32_t unicode,
		    t_tekgui *tekgui,
		    int i)
{
  void	(*fct)(t_tekgui*);

  if (unicode != 8 && unicode != 13)
    {
      tekgui->texter[(int)tekgui->focus_text].text[i] = unicode;
      tekgui->texter[(int)tekgui->focus_text].text[i + 1] = 0;
    }
  else if (my_strlen(tekgui->texter[(int)tekgui->focus_text].text) > 0 &&
	   unicode == 8)
    tekgui->texter[(int)tekgui->focus_text].text[i - 1] = 0;
  else if (unicode == 13 &&
	   my_strlen(tekgui->texter[(int)tekgui->focus_text].text) > 0)
    {
      if ((fct = tekfunction
	   (tekgui->texter[(int)tekgui->focus_text].fct)) != NULL)
	fct(tekgui);
    }
}
