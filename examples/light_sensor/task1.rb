puts "Switch for mruby/c"

light_sensor = LightSensor.new
buzzer = Buzzer.new

tft = TFT.new(3)
tft.set_text_color(tft.blue)
tft.set_text_size(3)

label = ""

while true
  tft.fill_screen(tft.cyan)
  val = light_sensor.value

  label = "LIGHT: #{val}"
  tft.draw_string(label, 50, 100)

  buzzer_val = val.to_f * (256.0 / 1000.0)
  buzzer.buzz(buzzer_val.to_i)

  sleep 0.3
end
