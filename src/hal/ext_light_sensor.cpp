/*
  ext_light_sensor.cpp

  Defining extension methods of Buzzer

  Copyright (c) 2020, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"

static void class_light_sensor_initialize(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  pinMode(WIO_LIGHT, INPUT);
}

static void class_light_sensor_status(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int light = analogRead(WIO_LIGHT);
  SET_INT_RETURN(light);
}

void define_light_sensor_class()
{
  mrb_class *class_light_sensor;
  class_light_sensor = mrbc_define_class(0, "LightSensor", mrbc_class_object);
  mrbc_define_method(0, class_light_sensor, "initialize", class_light_sensor_initialize);
  mrbc_define_method(0, class_light_sensor, "value", class_light_sensor_status);
}
