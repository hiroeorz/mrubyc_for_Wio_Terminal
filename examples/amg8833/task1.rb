# coding: utf-8
puts "AMG8833 for mruby/c"

$tft = TFT.new
$tft.fill_screen($tft.darkcyan)
$tft.set_text_size(3)

def main
  amg8833 = AMG8833.new
  
  while true
    temps = amg8833.read_pixel_temperature
    draw_tharmal_map(temps)
    draw_max_min(temps)
  end
end

puts "OK."

########################################################
# local methods
########################################################

def draw_max_min(temps)
  $tft.fill_rect(15 * 8 + 10, 30, 200, 200, $tft.darkcyan)
  $tft.set_text_color($tft.white)
  $tft.draw_string("MAX: #{temps.max}", 15 * 8 + 10, 30)
  $tft.draw_string("MIN: #{temps.min}", 15 * 8 + 10, 60)
end

def draw_tharmal_map(temps)
  unit_size = 15

  (0 .. 63).each do |i|
    x = i % 8
    y = 7 - (i / 8) # GROVEソケットが下に来るように持つと並び順が下からになるので逆にする.
    temp = temps[i]
    $tft.fill_rect(unit_size * x, unit_size * y, unit_size, unit_size, color(temp))
  end
end

def color(temp)
  return $tft.blue   if temp < 29
  return $tft.green  if temp < 30
  return $tft.yellow if temp < 31
  return 0xfd00      if temp < 32
  return $tft.red
end

########################################################
# main method
########################################################

main()
