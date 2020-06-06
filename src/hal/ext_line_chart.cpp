/*
  ext_line_chart.cpp

  Defining extension methods of TFT

  Copyright (c) 2020, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"
#include "hal.h"

TFT_eSPI tft; 
#define max_size 50 //maximum size of data
doubles data; //Initilising a doubles type to store data
TFT_eSprite spr = TFT_eSprite(&tft);  // Sprite

static void class_line_chart_initialize(mrb_vm *vm, mrb_value *v, int argc)
{
  tft.begin();
  tft.setRotation(3);
  spr.createSprite(TFT_HEIGHT, TFT_WIDTH);
}

static void class_line_chart_draw(mrb_vm *vm, mrb_value *v, int argc)
{
  spr.fillSprite(TFT_WHITE);

  if (data.size() == max_size) {
    data.pop(); //this is used to remove the first read variable
  }
  
  data.push(0.01 * random(1, 10)); //read variables and store in data

  //Settings for the line graph title
  auto header =  text(0, 0)
    .value("test")
    .align(center)
    .valign(vcenter)
    .width(tft.width())
    .thickness(3);
 
  header.height(header.font_height() * 2);
  header.draw(); //Header height is the twice the height of the font

  //Settings for the line graph
  auto content = line_chart(20, header.height()); //(x,y) where the line graph begins
  content
    .height(tft.height() - header.height() * 1.5) //actual height of the line chart
    .width(tft.width() - content.x() * 2) //actual width of the line chart
    .based_on(0.0) //Starting point of y-axis, must be a float
    .show_circle(false) //drawing a cirle at each point, default is on.
    .value(data) //passing through the data to line graph
    .color(TFT_PURPLE) //Setting the color for the line
    .draw();
  
  spr.pushSprite(0, 0);
  DEBUG_PRINT("------------- draw -------------");
  SET_TRUE_RETURN();
}

void define_line_chart_class()
{
  mrb_class *class_line_chart;
  class_line_chart = mrbc_define_class(0, "LineChart", mrbc_class_object);

  mrbc_define_method(0, class_line_chart, "initialize", class_line_chart_initialize);
  mrbc_define_method(0, class_line_chart, "draw", class_line_chart_draw);
}
