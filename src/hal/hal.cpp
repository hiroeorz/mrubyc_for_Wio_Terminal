/*
  hal.cpp

  mruby/c hardware abstract layer for Wio Terminal
 */

#include "hal.h"
#include "libmrubyc.h"

extern "C" void hal_init_serial(unsigned int speed)
{
  Serial.begin(speed);
}

extern "C" void hal_write_string(char* text)
{
  Serial.print(text);
}

extern "C" void hal_delay(unsigned long t)
{
  delay(t);
}
