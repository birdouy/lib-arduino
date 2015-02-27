/*
** arduino_close.c for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:42:35 2014 caudou_j
** Last update Wed May 14 16:42:36 2014 caudou_j
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"lib-arduino.h"

t_return	arduino_close(t_arduino *arduino)
{
  if (close(arduino->fd) == -1)
    {
      perror("Warning : close failed ");
      return (FAILED);
    }
  return (SUCCESS);
}
