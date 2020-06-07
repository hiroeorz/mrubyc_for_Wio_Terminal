puts "Switch for mruby/c"

emitter = IREmitter.new
button = Button.new
switch = Switch.new

tft = TFT.new
tft.set_text_color(tft.blue)
tft.set_text_size(3)

while true
  tft.fill_screen(tft.orange)

  if button.pushed?(:a)
    emitter.send_sony(0xa90, 12)
    tft.draw_string("Power", 10, 100); sleep 1

  elsif button.pushed?(:b)
    emitter.send_sony(0x490, 12)
    tft.draw_string("Volume UP", 10, 100); sleep 1

  elsif button.pushed?(:c)
    emitter.send_sony(0xc90, 12)
    tft.draw_string("Volume DOWN", 10, 100); sleep 1

  elsif switch.pushed?(:up)    
    emitter.send_sony(0x90, 12)
    tft.draw_string("Channel UP", 10, 100); sleep 1
    
  elsif switch.pushed?(:down)
    emitter.send_sony(0x890, 12)
    tft.draw_string("Channel DOWN", 10, 100); sleep 1
    
  elsif switch.pushed?(:left)
    emitter.send_sony(0x99a, 12)
    tft.draw_string("Pause", 10, 100); sleep 1

  elsif switch.pushed?(:right)
    emitter.send_sony(0x59a, 12)
    tft.draw_string("Play", 10, 100); sleep 1

  elsif switch.pushed?(:press)
    emitter.send_sony(0x19a, 12)
    tft.draw_string("Stop", 10, 100); sleep 1

  end

end

