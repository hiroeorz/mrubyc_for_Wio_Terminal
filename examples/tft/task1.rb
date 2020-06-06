puts "TFT for mruby/c"

tft = TFT.new(3)
tft.fill_screen(tft.yellow)

tft.fill_circle(170, 120, 50, tft.red)
tft.draw_pixel(4, 7, tft.cyan)
tft.draw_line(1, 1, 100, 100, tft.navy)
tft.draw_fast_h_line(0, 120, 320, tft.navy)
tft.draw_fast_v_line(160, 0, 240, tft.navy)
tft.draw_ellipse(160, 120, 50, 100, tft.red)
tft.fill_ellipse(260, 120, 50, 200, tft.red)
tft.draw_round_rect(110, 70, 1000, 100, 10, tft.black)
tft.fill_round_rect(110, 90, 100, 100, 10, tft.black)
tft.fill_triangle(110, 70, 10, 170, 210, 170, tft.maroon)

tft.set_text_color(tft.black)
tft.set_text_size(5)
tft.draw_string("Hello mruby/c!", 1, 1)

sleep 5

puts "OK complete."
while true; sleep 1; end
