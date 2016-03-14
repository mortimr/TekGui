/*
** tekfunction.c for tekgui in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb  9 19:02:13 2016 Iulian Rotaru
** Last update Sun Feb 28 11:44:07 2016 Iulian Rotaru
*/

#include <dlfcn.h>
#include "tekgui.h"

void	*tekfunction(const char *funcname)
{
  void	*handle;
  void	*fct;

  if ((handle = dlopen(NULL, RTLD_NOW)) == NULL)
    {
      return (NULL);
    }
  if ((fct = dlsym(handle, funcname)) == NULL)
    {
      dlclose(handle);
      return (NULL);
    }
  dlclose(handle);
  return (fct);
}
