/*
  ext_wio.cpp

  Defining extension methods of Wio 3G

  Copyright (c) 2019, Shin Hiroe All rights reserved

*/

#include <limits.h>
#include "libmrubyc.h"
#include "ext.h"

static void class_wio_initialize(mrb_vm *vm, mrb_value *v, int argc)
{
}


void define_wio_class()
{
  mrb_class *class_wio;
  class_wio = mrbc_define_class(0, "Wio", mrbc_class_object);

  mrbc_define_method(0, class_wio, "initialize", class_wio_initialize);
}
