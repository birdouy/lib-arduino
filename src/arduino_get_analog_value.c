/*
** arduino_get_analog_value.c for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:42:41 2014 caudou_j
** Last update Tue May 27 23:20:02 2014 caudou_j
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"lib-arduino.h"

t_return	arduino_get_analog_pin_value(t_arduino *arduino, analog_pin pin, int *value)
{
  char		packet[ARDUINO_PACKET_SIZE + 1];

  if (pin > ANALOG_PIN_5)
    {
      fprintf(stderr, "Warning : invalid analog pin number. [%d, %d]\n",
	      ANALOG_PIN_0, arduino->max_analog_pin);
      return (FAILED);
    }
#ifdef ARDUINO_VERBOSE
  printf("Get analog pin %d value\n", pin);
#endif
  if (arduino_send_packet(arduino, GET_ANALOG_PIN_VALUE, pin, -1) == ERROR)
    return (ERROR);
  memset(packet, 0, ARDUINO_PACKET_SIZE);

  if (tcflush(arduino->fd, TCIOFLUSH) == -1)
    {
      fprintf(stderr, "Arduino Error : tcflush failed\n");
      return (ERROR);
    }
  if (arduino_read(arduino, packet, ARDUINO_PACKET_SIZE) == ERROR)
    return (ERROR);
  if (value != NULL)
    *value = atoi(packet);
  else
    printf("%d\n", atoi(packet));
  return (SUCCESS);
}
