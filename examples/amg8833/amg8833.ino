#include <libmrubyc.h>
#include "mrblib.c"

extern const uint8_t code[];

#define MEMSIZE (1024*40)
static uint8_t mempool[MEMSIZE];

void setup() {
  mrbc_init(mempool, MEMSIZE);
  mrbc_define_wio_methods();

  if (NULL == mrbc_create_task(code, 0)) {
    Serial.println("!!! mrbc_create_task error");
    return;
  }
}

void loop() {
  Serial.println("--- running mruby/c ---");
  mrbc_run();
}
