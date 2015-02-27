/*
** arduino_write.c for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:41:37 2014 caudou_j
** Last update Wed May 14 16:41:38 2014 caudou_j
*/

#include	<unistd.h>
#include	<stdio.h>
#include	"lib-arduino.h"

t_return	arduino_write(t_arduino *arduino, const char *data, size_t size)
{
  size_t	w_bytes;

  w_bytes = 0;
  while ((w_bytes = write(arduino->fd, data + w_bytes, size - w_bytes)) != size)
    if (w_bytes == (size_t)-1)
      {
	perror("Error : write failed ");
	return (ERROR);
      }
  return (SUCCESS);
}

t_return	arduino_send_packet(t_arduino *arduino, t_packet_type command,
				    digital_pin pin, char value)
{
  char		packet[ARDUINO_PACKET_SIZE + 1];
  int		size;

  if ((size = snprintf(packet, ARDUINO_PACKET_SIZE + 1, "%c%c%c%c%c",
		       ARDUINO_MAGIC_NUMBER_1, ARDUINO_MAGIC_NUMBER_2,
		       command, pin, value)) == -1)
    {
      fprintf(stderr, "Error : snprintf failed\n");
      return (ERROR);
    }
  if (arduino_write(arduino, packet, size) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
