/*
  ext_amg8833.cpp

  Defining extension methods of Buzzer

  Copyright (c) 2020, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"

AMG8833 amg8833;

static void class_amg8833_initialize(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  u32 result = amg8833.init();
  if (result != 0) {
    DEBUG_PRINTLN("ERR: Failed to initialize AMG8833");
    return;
  }
  
  hal_delay(100);
}

static void class_amg8833_read_pixel_temperature(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  float temps[64];
  amg8833.read_pixel_temperature(temps);
  mrbc_value array = mrbc_array_new(vm, 64);

  if (temps[0] < 0) {
    SET_NIL_RETURN();
    return;
  }
  
  for (int i; i < 64; i++) {
    mrbc_value val = mrb_float_value((mrbc_float)temps[i]);
    mrbc_array_set(&array, i, &val);
  }

  SET_RETURN(array);
}

void define_amg8833_class()
{
  mrb_class *class_amg8833;
  class_amg8833 = mrbc_define_class(0, "AMG8833", mrbc_class_object);
  mrbc_define_method(0, class_amg8833, "initialize", class_amg8833_initialize);
  mrbc_define_method(0, class_amg8833, "read_pixel_temperature", class_amg8833_read_pixel_temperature);
}
