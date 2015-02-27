/*
** arduino_get_digital_state.c for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:42:31 2014 caudou_j
** Last update Tue May 27 23:14:38 2014 caudou_j
*/

#include	<unistd.h>
#include	<termios.h>
#include	<stdio.h>
#include	"lib-arduino.h"

t_return	arduino_get_digital_pin_state(t_arduino *arduino, digital_pin pin,
						t_pin_state *pin_state)
{
  char		packet[ARDUINO_PACKET_SIZE];

  if (pin > DIGITAL_PIN_13)
    {
      fprintf(stderr, "Warning : invalid digital pin number. [%d, %d]\n",
	      DIGITAL_PIN_0, arduino->max_digital_pin);
      return (FAILED);
    }
#ifdef ARDUINO_VERBOSE
  printf("Get digital pin %d state\n", pin);
#endif

  if (tcflush(arduino->fd, TCIOFLUSH) == -1)
    {
      fprintf(stderr, "Arduino Error : tcflush failed\n");
      return (ERROR);
    }
  if (arduino_send_packet(arduino, GET_DIGITAL_PIN_STATE, pin, -1) == ERROR)
    return (ERROR);
  if (arduino_read(arduino, packet, 1) == ERROR)
    return (ERROR);
  printf("PIN STATE GET VALUE ========> %c \n", *packet);
  if (*packet == '0')
    *pin_state = LOW;
  else if (*packet == '1')
    *pin_state = HIGH;
  else
    *pin_state = NO_PIN_STATE;
  return (SUCCESS);
}
