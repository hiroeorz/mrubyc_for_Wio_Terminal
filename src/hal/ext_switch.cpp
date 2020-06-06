/*
  ext_switch.cpp

  Defining extension methods of Buzzer

  Copyright (c) 2020, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"

static void class_switch_initialize(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc > 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
}

static void class_switch_status(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int keyNo = GET_INT_ARG(1);
  int key = 0;
  
  switch(keyNo) {
    case 0: { key = WIO_5S_UP; break; }
    case 1: { key = WIO_5S_DOWN; break; }
    case 2: { key = WIO_5S_LEFT; break; }
    case 3: { key = WIO_5S_RIGHT; break; }
    case 4: { key = WIO_5S_PRESS; break; }
  }
  
  bool status = (digitalRead(key) == LOW);

  if (status) {
    SET_TRUE_RETURN();
  } else {
    SET_FALSE_RETURN();
  }
}

void define_switch_class()
{
  mrb_class *class_switch;
  class_switch = mrbc_define_class(0, "Switch", mrbc_class_object);
  mrbc_define_method(0, class_switch, "initialize", class_switch_initialize);
  mrbc_define_method(0, class_switch, "status", class_switch_status);
}
