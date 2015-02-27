/*
** arduino_init.c for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino/src
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:42:46 2014 caudou_j
** Last update Sat May 24 18:44:48 2014 caudou_j
*/

#include	<string.h>
#include	<termios.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"lib-arduino.h"

static t_return		arduino_init_termios(t_arduino *arduino, speed_t baud_rate)
{
  struct termios	toptions;

  if (tcgetattr(arduino->fd, &toptions) == -1)
    {
      perror("lib-arduino : tcgetattr failed ");
      return (ERROR);
    }
  (void)cfsetispeed(&toptions, baud_rate);
  (void)cfsetospeed(&toptions, baud_rate);
  toptions.c_cflag &= ~HUPCL;
  toptions.c_cflag &= ~PARENB;
  toptions.c_cflag &= ~CSTOPB;
  toptions.c_cflag &= ~CSIZE;
  toptions.c_cflag |= CS8;
  toptions.c_lflag |= ICANON;
  if (tcsetattr(arduino->fd, TCSANOW, &toptions) == -1)
    {
      perror("lib-arduino Error : tcsetattr failed ");
      return (ERROR);
    }
  return (SUCCESS);
}

static void	arduino_init_prepare(t_arduino *arduino, const char *device)
{
  arduino->max_analog_pin = ANALOG_PIN_5;
  arduino->max_digital_pin = DIGITAL_PIN_13;
  memcpy(arduino->device, device, strlen(device) + 1);
}

t_return	arduino_init(t_arduino *arduino, const char *device, speed_t baud_rate)
{
  int		time_wait;

  arduino_init_prepare(arduino, device);
  if ((arduino->fd = open(device, O_RDWR)) == -1)
    {
      perror("lib-arduino Error : open failed ");
      return (ERROR);
    }
  time_wait = 3;
  while ((time_wait = sleep(time_wait)) != 0)
    ;
  if (arduino_init_termios(arduino, baud_rate) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
