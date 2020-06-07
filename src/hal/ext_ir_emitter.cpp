/*
  ext_ir_emitter.cpp

  Defining extension methods of Infrared Emitter

  Copyright (c) 2020, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"

IRsend irSend;

static void class_ir_emitter_send_sony(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 2) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  uint32_t data = GET_INT_ARG(1);
  int bits = GET_INT_ARG(2);
  irSend.send(SONY, data, bits);
  SET_TRUE_RETURN();
}

void define_ir_emitter_class()
{
  mrb_class *class_ir_emitter;
  class_ir_emitter = mrbc_define_class(0, "IREmitter", mrbc_class_object);
  mrbc_define_method(0, class_ir_emitter, "send_sony", class_ir_emitter_send_sony);
}
