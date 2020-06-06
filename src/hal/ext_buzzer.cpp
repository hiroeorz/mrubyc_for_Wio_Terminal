/*
  ext_buzzer.cpp

  Defining extension methods of Buzzer

  Copyright (c) 2020, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"

static void class_buzzer_initialize(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc > 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  pinMode(WIO_BUZZER, OUTPUT);
}

static void class_buzzer_buzz(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int val = GET_INT_ARG(1);
  analogWrite(WIO_BUZZER, val);
  SET_TRUE_RETURN();
}

void define_buzzer_class()
{
  mrb_class *class_buzzer;
  class_buzzer = mrbc_define_class(0, "Buzzer", mrbc_class_object);
  mrbc_define_method(0, class_buzzer, "initialize", class_buzzer_initialize);
  mrbc_define_method(0, class_buzzer, "buzz", class_buzzer_buzz);
}
