/*
  ext.cpp

  Defining extension methods

  Copyright (c) 2019, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"
#include "wio_mrb_lib.c"

bool mrbc_trans_cppbool_value(mrbc_vtype tt)
{
  if (tt == MRBC_TT_TRUE) {
    return true;
  }

  return false;
}


void mrbc_define_wio_methods(void)
{
  define_tft_class();
  define_line_chart_class();
  define_buzzer_class();
  define_button_class();
  define_switch_class();
  define_light_sensor_class();
  
  // mrblib以下のrubyソースから生成したバイトコードを読み込む.
  // src/hal/wio_mrb_lib.c
  extern const uint8_t mruby_wio_code[];

  if (NULL == mrbc_create_task(mruby_wio_code, 0)) {
    hal_write_string((char *)"!!! wio bytecode load error\n");
  }

  mrbc_run();
}
