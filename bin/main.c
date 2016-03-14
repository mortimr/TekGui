/*
** main.c for  in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb  2 12:03:02 2016 Iulian Rotaru
** Last update Tue Mar  1 14:52:03 2016 Iulian Rotaru
*/

#include <dlfcn.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include "tekgui.h"

int	main(int argc, char **argv)
{
  t_tekgui		*tekgui;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;

  (void)argc;
  if (argc != 2)
    return (1);
  if ((win = bunny_start(1920, 1080, 1, "TekGui")) == NULL)
    return (1);
  if ((pix = bunny_new_pixelarray(1920, 1080)) == NULL)
    return (1);
  if ((tekgui = tekgui_load(argv[1])) == NULL)
    return (1);
  if (tekgui_loop(win, pix, tekgui) == 1)
    return (1);
  return (0);
}
