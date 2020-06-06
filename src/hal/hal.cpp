/*
  hal.cpp

  mruby/c hardware abstract layer for Wio Terminal
 */

#include "hal.h"
#include "libmrubyc.h"

static TFT_eSPI *TFT = NULL;
static TFT_eSprite *spr = NULL;

extern "C" void hal_init_serial(unsigned int speed)
{
  Serial.begin(speed);
}

extern "C" void hal_write_string(char* text)
{
  Serial.print(text);
}

extern "C" void hal_delay(unsigned long t)
{
  delay(t);
}

/*********************************************
  TFT
**********************************************/

extern "C" void hal_init_tft(void) {
  if (TFT != NULL){ return; }
  TFT = new  TFT_eSPI();
  TFT->begin();
  return;
}

extern "C" void* hal_get_tft_obj(void) {
  return (void*) TFT;
}

/*********************************************
  Line Chart
**********************************************/

extern "C" void hal_init_sprite(void) {
  if (spr != NULL) { return; }
  if (TFT == NULL) { DEBUG_PRINT("ERR: plase initialize TFT before sprite initializing."); return;}
  spr = new TFT_eSprite(TFT);
  return;
}

extern "C" void* hal_get_sprite_obj(void) {
  return (void*)spr;
}
