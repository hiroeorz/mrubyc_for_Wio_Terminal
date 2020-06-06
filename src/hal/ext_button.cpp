/*
  ext_button.cpp

  Defining extension methods of Buzzer

  Copyright (c) 2020, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"

static void class_button_initialize(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc > 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  pinMode(WIO_KEY_A, INPUT_PULLUP);
  pinMode(WIO_KEY_B, INPUT_PULLUP);
  pinMode(WIO_KEY_C, INPUT_PULLUP);
}

static void class_button_status(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int keyNo = GET_INT_ARG(1);
  int key = 0;
  
  switch(keyNo) {
    case 0: { key = WIO_KEY_A; break; }
    case 1: { key = WIO_KEY_B; break; }
    case 2: { key = WIO_KEY_C; break; }
  }
  
  bool status = (digitalRead(key) == LOW);

  if (status) {
    SET_TRUE_RETURN();
  } else {
    SET_FALSE_RETURN();
  }
}

void define_button_class()
{
  mrb_class *class_button;
  class_button = mrbc_define_class(0, "Button", mrbc_class_object);
  mrbc_define_method(0, class_button, "initialize", class_button_initialize);
  mrbc_define_method(0, class_button, "status", class_button_status);
}
