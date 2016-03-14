/*
** load_case.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 25 14:20:44 2016 Iulian Rotaru
** Last update Mon Feb 29 20:35:20 2016 Iulian Rotaru
*/

#include "tekgui.h"

int		load_case(t_bunny_ini *ini, t_tekgui *tekgui)
{
  const char	*extract;
  int		i;

  i = 0;
  if ((extract = bunny_ini_get_field(ini, NULL, "case", i)) == NULL)
    {
      tekgui->nb_cases = i;
      return (0);
    }
  while (extract)
    {
      i++;
      extract = bunny_ini_get_field(ini, NULL, "case", i);
    }
  if ((tekgui->cases = bunny_malloc(sizeof(t_cases) * i)) == NULL)
    return (- 1);
  tekgui->nb_cases = i;
  if (get_cases_data(ini, tekgui) == - 1)
    return (- 1);
  return (0);
}

int	load_objects_next(t_bunny_ini *ini, t_tekgui *tekgui)
{
  if (load_area(ini, tekgui) == - 1)
    return (- 1);
  if (load_text(ini, tekgui) == - 1)
    return (- 1);
  if (load_radio(ini, tekgui) == - 1)
    return (- 1);
  if (load_case(ini, tekgui) == - 1)
    return (- 1);
  return (0);
}

int	load_objects(t_bunny_ini *ini, t_tekgui *tekgui)
{
  if (load_body(ini, tekgui) == - 1)
    return (- 1);
  if (load_builtins(ini, tekgui) == - 1)
    return (- 1);
  if (load_buttons(ini, tekgui) == - 1)
    return (- 1);
  if (load_plugins(ini, tekgui) == - 1)
    return (- 1);
  if (load_objects_next(ini, tekgui) == - 1)
    return (- 1);
  return (0);
}

void	animation_setup(t_tekgui *tekgui)
{
  char	*test;
  int	i;

  test = "TekGui !! iuGkeT";
  if (tekgui->animation == 1)
    {
      tekgui->ani->text[0] = 0;
      tekgui->ani->police = 50;
      tekgui->ani->fg = WHITE;
      tekgui->ani->bg = BLACK;
      tekgui->ani->move_speed = 10;
      tekgui->ani->invert = 0;
      tekgui->ani->epileptic = 0;
      i = 0;
      while (test[i])
	{
	  tekgui->ani->text[i] = test[i];
	  i++;
	}
      tekgui->ani->text[i] = 0;
    }
}

int		load_config()
{
  t_bunny_ini	*ini;
  const char	*extract;
  int		ram;

  if ((ini = bunny_load_ini("configuration.ini")) == NULL)
    return (- 1);
  if ((extract = bunny_ini_get_field(ini, NULL, "max_ram", 0)) == NULL)
    return (- 1);
  if ((ram = my_getnbr(extract)) < 13)
    return (- 1);
  set_max_heap_size(ram);
  return (0);
}
