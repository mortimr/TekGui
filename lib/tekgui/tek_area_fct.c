/*
** tek_area_fct.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Feb 28 12:16:39 2016 Iulian Rotaru
** Last update Sun Feb 28 12:17:33 2016 Iulian Rotaru
*/

#include "tekgui.h"

void	*tek_area_fct(const char *funcname)
{
  void	*handle;
  void	(*fct)(t_tekgui*, t_area*);

  if ((handle = dlopen(NULL, RTLD_NOW)) == NULL)
    return (NULL);
  if ((fct = dlsym(handle, funcname)) == NULL)
    {
      dlclose(handle);
      return (NULL);
    }
  dlclose(handle);
  return (fct);
}

void	ani_invert_colors_on(t_tekgui *tekgui)
{
  if (tekgui->animation == 1)
    tekgui->ani->invert = 1;
}

void	ani_invert_colors_off(t_tekgui *tekgui)
{
  if (tekgui->animation == 1)
    tekgui->ani->invert = 0;
}

void	ani_epileptic_off(t_tekgui *tekgui)
{
  if (tekgui->animation == 1)
    tekgui->ani->epileptic = 0;
}

void	ani_epileptic_on(t_tekgui *tekgui)
{
  if (tekgui->animation == 1)
    tekgui->ani->epileptic = 1;
}
