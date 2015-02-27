/*
** arduino_set_digital_state.c for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:41:44 2014 caudou_j
** Last update Sat May 24 20:11:15 2014 jerome
*/

#include	<unistd.h>
#include	<stdio.h>
#include	"lib-arduino.h"

t_return	arduino_set_digital_pin_state(t_arduino *arduino, digital_pin pin,
					      t_pin_state pin_state)
{
  if (pin > DIGITAL_PIN_13)
    {
      fprintf(stderr, "Warning : invalid digital pin number. [%d, %d]\n",
	      DIGITAL_PIN_0, arduino->max_digital_pin);
      return (FAILED);
    }
#ifdef ARDUINO_VERBOSE
  printf("Set digital pin %d to state %d\n", pin, pin_state);
#endif
if (arduino_send_packet(arduino, SET_DIGITAL_PIN_STATE, pin, pin_state) == ERROR)
  return (ERROR);
return (SUCCESS);
}
