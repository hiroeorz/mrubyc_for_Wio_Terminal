/*
  ext_wifi.cpp

  Defining extension methods of Buzzer

  Copyright (c) 2020, Shin Hiroe All rights reserved

*/

#include "libmrubyc.h"
#include "ext.h"

#define MRUBY_WIFI_STA 0

static void class_wifi_initialize(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc > 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }
}


static void class_wifi_set_mode(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int mode = GET_INT_ARG(1);


  if (MRUBY_WIFI_STA == mode) {
    WiFi.mode(WIFI_STA);
    SET_TRUE_RETURN();
  } else {
    SET_FALSE_RETURN();
  }
}

static void class_wifi_disconnect(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  WiFi.disconnect();
  hal_delay(100);
  SET_TRUE_RETURN();
}

static void class_wifi_scan_networks(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int n = WiFi.scanNetworks();
  SET_INT_RETURN(n);
}

static void class_wifi_ssid(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int i = GET_INT_ARG(1);
  const char *ssid = WiFi.SSID(i).c_str();
  mrbc_value str = mrbc_string_new_cstr(vm, ssid);
  SET_RETURN(str);
}

static void class_wifi_rssi(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 1) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  int i = GET_INT_ARG(1);
  int rssi = WiFi.RSSI(i);
  SET_INT_RETURN(rssi);
}

static void class_wifi_begin(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 2) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  uint8_t *ssid = GET_STRING_ARG(1);
  uint8_t *password = GET_STRING_ARG(2);
  WiFi.begin((const char*)ssid, (const char*)password);
  SET_TRUE_RETURN();
}

static void class_wifi_is_connected(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    SET_TRUE_RETURN();
    return;
  }

  SET_FALSE_RETURN();
}

static void class_wifi_local_ip(mrb_vm *vm, mrb_value *v, int argc)
{
  if (argc != 0) {
    DEBUG_PRINTLN("invalid argc");
    SET_NIL_RETURN();
    return;
  }

  IPAddress ip = WiFi.localIP();
  String ip_str = "";

  for (int i = 0; i < 4; i++) {
    ip_str += (i  ? "." + String(ip[i]) : String(ip[i]));
  }
  
  const char* local_ip = ip_str.c_str();
  mrbc_value str = mrbc_string_new_cstr(vm, local_ip);
  SET_RETURN(str);
}

void define_wifi_class()
{
  mrb_class *class_wifi;
  class_wifi = mrbc_define_class(0, "WiFi", mrbc_class_object);
  mrbc_define_method(0, class_wifi, "initialize", class_wifi_initialize);
  mrbc_define_method(0, class_wifi, "set_mode", class_wifi_set_mode);
  mrbc_define_method(0, class_wifi, "disconnect", class_wifi_disconnect);
  mrbc_define_method(0, class_wifi, "scan_networks", class_wifi_scan_networks);
  mrbc_define_method(0, class_wifi, "ssid", class_wifi_ssid);
  mrbc_define_method(0, class_wifi, "rssi", class_wifi_rssi);
  mrbc_define_method(0, class_wifi, "begin", class_wifi_begin);
  mrbc_define_method(0, class_wifi, "connected?", class_wifi_is_connected);
  mrbc_define_method(0, class_wifi, "local_ip", class_wifi_local_ip);
}
