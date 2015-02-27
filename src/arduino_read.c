/*
** arduino_read.c for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:42:26 2014 caudou_j
** Last update Sat Aug 16 17:36:58 2014 jerome
*/

#include	<unistd.h>
#include	<stdio.h>
#include	"lib-arduino.h"

t_return	arduino_read(t_arduino *arduino, char *data, size_t size)
{
  size_t	r_bytes;

  if ((r_bytes = read(arduino->fd, data, size)) == (size_t)-1)
    {
      perror("Error : read failed ");
      return (ERROR);
    }
  if (r_bytes == 0)
    return (FAILED);
  return (SUCCESS);
}
