.PHONY: mrbc

TARGET=~/Documents/Arduino/libraries/mrubyc_for_Wio_cell_lib

MRBC=mrbc
SRC=./mrblib/*.rb
RUBY_OUTPUT=./mrblib/wio_mrb_lib.rb
OUTPUT=./src/hal/wio_mrb_lib.c

mrbc:
	cat $(SRC) > $(RUBY_OUTPUT)

	$(MRBC) -E -Bmruby_wio_code -o $(OUTPUT) $(RUBY_OUTPUT) && \
		sed -i -e 's/extern const uint8_t mruby_wio_code\[\];//g' $(OUTPUT)

	rm -f $(RUBY_OUTPUT) $(OUTPUT).tmp

clean:
	rm -rf $(OUTPUT) $(RUBY_OUTPUT) $(OUTPUT).tmp
