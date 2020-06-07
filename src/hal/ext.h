/*
  ext.cpp

  Header file for  extension methods

  Copyright (c) 2019, Shin Hiroe All rights reserved

*/

#ifndef __EXT_H_
#define __EXT_H_

#include "value.h"

bool mrbc_trans_cppbool_value(mrbc_vtype tt);

void define_tft_class(void);
void define_line_chart_class(void);
void define_buzzer_class(void);
void define_button_class(void);
void define_switch_class(void);
void define_light_sensor_class(void);
void define_ir_emitter_class(void);

#endif
