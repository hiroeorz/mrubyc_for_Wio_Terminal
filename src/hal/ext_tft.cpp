/*
  ext_tft.cpp

  Defining extension methods of TFT

  Copyright (c) 2020, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"
#include "hal.h"

extern TFT_eSPI tft;

static void class_tft_initialize(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc > 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  tft.begin();
  long rotate = 3;
  
  if (argc == 1) {
    rotate = GET_INT_ARG(1);
  }
  
  tft.setRotation(rotate);
}

static void class_tft_fill_screen(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  long color = GET_INT_ARG(1);
  tft.fillScreen(color);
  SET_NIL_RETURN();
}

static void class_tft_draw_string(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 3) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  uint8_t *str = GET_STRING_ARG(1);
  int posX = GET_INT_ARG(2);
  int posY = GET_INT_ARG(3);

  tft.drawString((const char*)str, posX, posY);
  SET_TRUE_RETURN();
}

static void class_tft_set_text_color(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int color = GET_INT_ARG(1);
  tft.setTextColor(color);
  SET_TRUE_RETURN();
}

static void class_tft_set_text_size(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int size = GET_INT_ARG(1);
  tft.setTextSize(size);
  SET_TRUE_RETURN();
}

static void class_tft_draw_rect(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 5) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int pos1 = GET_INT_ARG(1);
  int pos2 = GET_INT_ARG(2);
  int pos3 = GET_INT_ARG(3);
  int pos4 = GET_INT_ARG(4);
  int color = GET_INT_ARG(5);

  tft.drawRect(pos1, pos2, pos3, pos4, color);
  SET_TRUE_RETURN();
}

static void class_tft_fill_rect(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 5) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int pos1 = GET_INT_ARG(1);
  int pos2 = GET_INT_ARG(2);
  int pos3 = GET_INT_ARG(3);
  int pos4 = GET_INT_ARG(4);
  int color = GET_INT_ARG(5);

  tft.fillRect(pos1, pos2, pos3, pos4, color);
  SET_TRUE_RETURN();
}

static void class_tft_draw_circle(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 4) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int pos1 = GET_INT_ARG(1);
  int pos2 = GET_INT_ARG(2);
  int pos3 = GET_INT_ARG(3);
  int color = GET_INT_ARG(4);

  tft.drawCircle(pos1, pos2, pos3, color);
  SET_TRUE_RETURN();
}

static void class_tft_fill_circle(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 4) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int pos1 = GET_INT_ARG(1);
  int pos2 = GET_INT_ARG(2);
  int pos3 = GET_INT_ARG(3);
  int color = GET_INT_ARG(4);

  tft.fillCircle(pos1, pos2, pos3, color);
  SET_TRUE_RETURN();
}

static void class_tft_draw_pixel(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 3) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int x = GET_INT_ARG(1);
  int y = GET_INT_ARG(2);
  int color = GET_INT_ARG(3);

  tft.drawPixel(x, y, color);
  SET_TRUE_RETURN();
}

static void class_tft_draw_line(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 5) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int sx = GET_INT_ARG(1);
  int sy = GET_INT_ARG(2);
  int ex = GET_INT_ARG(3);
  int ey = GET_INT_ARG(4);
  int color = GET_INT_ARG(5);

  tft.drawLine(sx, sy, ex, ey, color);
  SET_TRUE_RETURN();
}

static void class_tft_draw_fast_h_line(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 4) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int x = GET_INT_ARG(1);
  int y = GET_INT_ARG(2);
  int w = GET_INT_ARG(3);
  int color = GET_INT_ARG(4);

  tft.drawFastHLine(x, y, w, color);
  SET_TRUE_RETURN();
}

static void class_tft_draw_fast_v_line(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 4) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int x = GET_INT_ARG(1);
  int y = GET_INT_ARG(2);
  int w = GET_INT_ARG(3);
  int color = GET_INT_ARG(4);

  tft.drawFastVLine(x, y, w, color);
  SET_TRUE_RETURN();
}

static void class_tft_draw_ellipse(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 5) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int x0 = GET_INT_ARG(1);
  int y0 = GET_INT_ARG(2);
  int rx = GET_INT_ARG(3);
  int ry = GET_INT_ARG(3);
  int color = GET_INT_ARG(4);

  tft.drawEllipse(x0, y0, rx, ry, color);
  SET_TRUE_RETURN();
}

static void class_tft_fill_ellipse(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 5) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int x0 = GET_INT_ARG(1);
  int y0 = GET_INT_ARG(2);
  int rx = GET_INT_ARG(3);
  int ry = GET_INT_ARG(3);
  int color = GET_INT_ARG(4);

  tft.fillEllipse(x0, y0, rx, ry, color);
  SET_TRUE_RETURN();
}

static void class_tft_draw_round_rect(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 6) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int x = GET_INT_ARG(1);
  int y = GET_INT_ARG(2);
  int w = GET_INT_ARG(3);
  int h = GET_INT_ARG(3);
  int r = GET_INT_ARG(4); // corner radius
  int color = GET_INT_ARG(5);

  tft.drawRoundRect(x, y, w, h, r, color);
  SET_TRUE_RETURN();
}

static void class_tft_fill_round_rect(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 6) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int x = GET_INT_ARG(1);
  int y = GET_INT_ARG(2);
  int w = GET_INT_ARG(3);
  int h = GET_INT_ARG(3);
  int r = GET_INT_ARG(4); // corner radius
  int color = GET_INT_ARG(5);

  tft.fillRoundRect(x, y, w, h, r, color);
  SET_TRUE_RETURN();
}

static void class_tft_draw_triangle(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 7) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int x0 = GET_INT_ARG(1);
  int y0 = GET_INT_ARG(2);
  int x1 = GET_INT_ARG(3);
  int y1 = GET_INT_ARG(4);
  int x2 = GET_INT_ARG(5);
  int y2 = GET_INT_ARG(6);
  int color = GET_INT_ARG(7);

  tft.drawTriangle(x0, y0, x1, y1, x2, y2, color);
  SET_TRUE_RETURN();
}

static void class_tft_fill_triangle(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 7) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int x0 = GET_INT_ARG(1);
  int y0 = GET_INT_ARG(2);
  int x1 = GET_INT_ARG(3);
  int y1 = GET_INT_ARG(4);
  int x2 = GET_INT_ARG(5);
  int y2 = GET_INT_ARG(6);
  int color = GET_INT_ARG(7);

  tft.fillTriangle(x0, y0, x1, y1, x2, y2, color);
  SET_TRUE_RETURN();
}

static void class_tft_width(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int width = tft.width();
  SET_INT_RETURN(width);
}

void define_tft_class()
{
  mrb_class *class_tft;
  class_tft = mrbc_define_class(0, "TFT", mrbc_class_object);

  mrbc_define_method(0, class_tft, "initialize", class_tft_initialize);
  mrbc_define_method(0, class_tft, "fill_screen", class_tft_fill_screen);
  mrbc_define_method(0, class_tft, "draw_string", class_tft_draw_string);
  mrbc_define_method(0, class_tft, "set_text_color", class_tft_set_text_color);
  mrbc_define_method(0, class_tft, "set_text_size", class_tft_set_text_size);
  mrbc_define_method(0, class_tft, "draw_rect", class_tft_draw_rect);
  mrbc_define_method(0, class_tft, "fill_rect", class_tft_fill_rect);
  mrbc_define_method(0, class_tft, "draw_circle", class_tft_draw_circle);
  mrbc_define_method(0, class_tft, "fill_circle", class_tft_fill_circle);
  mrbc_define_method(0, class_tft, "draw_pixel", class_tft_draw_pixel);
  mrbc_define_method(0, class_tft, "draw_line", class_tft_draw_line);
  mrbc_define_method(0, class_tft, "draw_fast_h_line", class_tft_draw_fast_h_line);
  mrbc_define_method(0, class_tft, "draw_fast_v_line", class_tft_draw_fast_v_line);
  mrbc_define_method(0, class_tft, "draw_ellipse", class_tft_draw_ellipse);
  mrbc_define_method(0, class_tft, "fill_ellipse", class_tft_fill_ellipse);
  mrbc_define_method(0, class_tft, "draw_round_rect", class_tft_draw_round_rect);
  mrbc_define_method(0, class_tft, "fill_round_rect", class_tft_fill_round_rect);
  mrbc_define_method(0, class_tft, "draw_triangle", class_tft_draw_triangle);
  mrbc_define_method(0, class_tft, "fill_triangle", class_tft_fill_triangle);
  mrbc_define_method(0, class_tft, "width", class_tft_width);
}
