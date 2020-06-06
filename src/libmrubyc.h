/*
  libmrubyc.h

  Header file for Arduino application

  Copyright (c) 2019, Shin Hiroe All rights reserved

*/

#ifndef __LIBMRUBYC_H_
#define __LIBMRUBYC_H_

#include <Arduino.h>
#include "TFT_eSPI.h"
#include "seeed_line_chart.h"
#include "mrubyc.h"
#include "libmrubyc_config.h"

// Sensor libraries
//#include <Seeed_BMP280.h>
//#include <SHT31.h>
//#include <Seeed_SHT35.h>
//#include <seeed_bme680.h>

void mrbc_define_wio_methods(void);

#endif
