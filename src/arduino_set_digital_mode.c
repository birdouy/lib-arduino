/*
** arduino_set_digital_mode.c for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:42:52 2014 caudou_j
** Last update Wed May 14 16:42:53 2014 caudou_j
*/

#include	<stdio.h>
#include	"lib-arduino.h"

t_return	arduino_set_digital_pin_mode(t_arduino *arduino, digital_pin pin, t_pin_mode pin_mode)
{
  if (pin > DIGITAL_PIN_13)
    {
      fprintf(stderr, "Warning : invalid digital pin number. [%d, %d]\n",
	      DIGITAL_PIN_0, arduino->max_digital_pin);
      return (FAILED);
    }
#ifdef ARDUINO_VERBOSE
printf("Set digital pin %d to mode %d\n", pin, pin_mode);
#endif
  if (arduino_send_packet(arduino, SET_DIGITAL_PIN_MODE, pin, pin_mode) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
