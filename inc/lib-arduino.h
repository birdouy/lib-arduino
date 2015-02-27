/*
** lib-arduino.h for lib-arduino in /home/caudou_j/Documents/projets/arduino/lib-arduino/inc
**
** Made by caudou_j
** Login   <caudou_j@epitech.net>
**
** Started on  Wed May 14 16:43:25 2014 caudou_j
** Last update Sat May 31 23:13:21 2014 caudou_j
*/

#ifndef LIBARDUINO_H_
# define LIBARDUINO_H_

# include	"types.h"
# include	<stdlib.h>
# include	<termios.h>

# define	ARDUINO_READ_BUFFER_SIZE	1024
# define	ARDUINO_PACKET_SIZE		5
# define	ARDUINO_DEVNAME_BUFFER_SIZE	128
# define	ARDUINO_MAGIC_NUMBER_1		0x12
# define	ARDUINO_MAGIC_NUMBER_2		0x21

# define	ARDUINO_VERBOSE

typedef enum	e_arduino_digital_pin
  {
    DIGITAL_PIN_0 = 0,
    DIGITAL_PIN_1,
    DIGITAL_PIN_2,
    DIGITAL_PIN_3,
    DIGITAL_PIN_4,
    DIGITAL_PIN_5,
    DIGITAL_PIN_6,
    DIGITAL_PIN_7,
    DIGITAL_PIN_8,
    DIGITAL_PIN_9,
    DIGITAL_PIN_10,
    DIGITAL_PIN_11,
    DIGITAL_PIN_12,
    DIGITAL_PIN_13
  }		digital_pin;

typedef enum	e_arduino_analog_pin
  {
    ANALOG_PIN_0 = 0,
    ANALOG_PIN_1,
    ANALOG_PIN_2,
    ANALOG_PIN_3,
    ANALOG_PIN_4,
    ANALOG_PIN_5
  }		analog_pin;

typedef enum	e_packet_type
  {
    SET_DIGITAL_PIN_MODE = 0,
    SET_DIGITAL_PIN_STATE,
    GET_DIGITAL_PIN_STATE,
    GET_ANALOG_PIN_VALUE
  }		t_packet_type;

typedef enum	e_pin_state
  {
    LOW = 0,
    HIGH,
    NO_PIN_STATE
  }		t_pin_state;

typedef enum	e_pin_mode
  {
    INPUT = 0,
    OUTPUT,
    INPUT_PULLUP,
    NO_PIN_MODE
  }		t_pin_mode;

typedef struct	s_arduino
{
  int		fd;
  char		device[ARDUINO_DEVNAME_BUFFER_SIZE];
  analog_pin	max_analog_pin;
  digital_pin	max_digital_pin;
}		t_arduino;

/*
** arduino init and close
*/
t_return	arduino_init(t_arduino *arduino, const char *device, speed_t baud_rate);
t_return	arduino_close(t_arduino *arduino);

/*
** arduino tools
*/
t_return	arduino_read(t_arduino *arduino, char *data, size_t size);
t_return	arduino_write(t_arduino *arduino, const char *data, size_t size);
t_return	arduino_send_packet(t_arduino *arduino, t_packet_type command,
				    digital_pin pin, char value);

/*
** arduino's pin setters
*/
t_return	arduino_set_digital_pin_mode(t_arduino *arduino, digital_pin pin, t_pin_mode pin_mode);
t_return	arduino_set_digital_pin_state(t_arduino *arduino, digital_pin pin, t_pin_state pin_state);

/*
** arduino's pin getters
*/
t_return	arduino_get_analog_pin_value(t_arduino *arduino, analog_pin pin, int *value);
t_return	arduino_get_digital_pin_state(t_arduino *arduino, digital_pin pin, t_pin_state *pin_state);

#endif /* !LIBARDUINO_H_ */
