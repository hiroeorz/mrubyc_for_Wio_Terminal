puts "Button for mruby/c"

button = Button.new
buzzer = Buzzer.new

tft = TFT.new(3)
tft.set_text_color(tft.blue)
tft.set_text_size(5)

while true
  tft.fill_screen(tft.cyan)

  if button.pushed?(:a)
    tft.draw_string("A", 150, 100)
    buzzer.buzz(10)
    
  elsif button.pushed?(:b)
    tft.draw_string("B", 150, 100)
    buzzer.buzz(60)
    
  elsif button.pushed?(:c)
    tft.draw_string("C", 150, 100)
    buzzer.buzz(120)
    
  else
    buzzer.buzz(0)
  end

  sleep 0.1
end

puts "OK complete."
while true; sleep 1; end
