puts "Switch for mruby/c"

switch = Switch.new
buzzer = Buzzer.new

tft = TFT.new(3)
tft.set_text_color(tft.blue)
tft.set_text_size(5)

while true
  tft.fill_screen(tft.cyan)

  if switch.pushed?(:up)
    tft.draw_string("UP", 150, 100)
    buzzer.buzz(10)
    
  elsif switch.pushed?(:down)
    tft.draw_string("DOWN", 150, 100)
    buzzer.buzz(40)
    
  elsif switch.pushed?(:left)
    tft.draw_string("LEFT", 150, 100)
    buzzer.buzz(80)

  elsif switch.pushed?(:right)
    tft.draw_string("RIGHT", 150, 100)
    buzzer.buzz(100)

  elsif switch.pushed?(:press)
    tft.draw_string("PRESS", 150, 100)
    buzzer.buzz(120)

  else
    buzzer.buzz(0)
  end

  sleep 0.1
end

