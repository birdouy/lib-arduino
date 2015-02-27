#include <Arduino.h>

void setup();
void set_digital_pin_mode(char pin, char mode);
void set_digital_pin_state(char pin, char state);
void get_digital_pin_state(char pin);
void get_analog_pin_value(char pin);
void exec_packet(char *data);
void loop();
#line 1 "src/arduino_control.ino"
typedef enum e_command
{
  SET_DIGITAL_PIN_MODE = 0,
  SET_DIGITAL_PIN_STATE,
  GET_DIGITAL_PIN_STATE,
  GET_ANALOG_PIN_VALUE
} command;

void setup() {
  Serial.begin(9600);
}

void set_digital_pin_mode(char pin, char mode)
{
  //Serial.println("Set digital pin mode");
  if (mode == 0)
    pinMode(pin, INPUT);
  else if (mode == 2)
    pinMode(pin, INPUT_PULLUP);
  else if (mode == 1)
    pinMode(pin, OUTPUT);
}

void set_digital_pin_state(char pin, char state)
{
  //Serial.println("Set digital pin state");
  if (state == 0)
    digitalWrite(pin, LOW);
  else if (state == 1)
    digitalWrite(pin, HIGH);
}

void get_digital_pin_state(char pin)
{
  //Serial.println("read digital value ...");
  Serial.print(digitalRead(pin));
}

void get_analog_pin_value(char pin)
{
  Serial.println(analogRead(pin), DEC);
}

void exec_packet(char *data)
{
  if (data[0] != 0x12 || data[1] != 0x21)
  {
    Serial.println("Wrong magic number");
    return ;
  }
  switch (data[2])
  {
    case SET_DIGITAL_PIN_MODE:
      set_digital_pin_mode(data[3], data[4]);
    break;
    case SET_DIGITAL_PIN_STATE:
      set_digital_pin_state(data[3], data[4]);
    break;
    case GET_DIGITAL_PIN_STATE:
      get_digital_pin_state(data[3]);
    break;
    case GET_ANALOG_PIN_VALUE:
      get_analog_pin_value(data[3]);
    break;
    default:
      Serial.println("Unknwon command :(");
  }
}

void loop() {
  char data[5];
  char r_bytes;
  
  if (Serial.available() >= 5)
  {
    r_bytes = 0;
    while (r_bytes < 5)
    {
        data[r_bytes] = Serial.read();
        r_bytes = r_bytes + 1;
    }
    exec_packet(data);
  }
}
