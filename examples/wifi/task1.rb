puts "WiFi for mruby/c"

#-----------------------------------
# Set your WiFi SSID and PASSWORD.
#-----------------------------------
SSID     = "**********"
PASSWORD = "**********"
#-----------------------------------

#
# Update farmware and install libraries.
# https://wiki.seeedstudio.com/Wio-Terminal-Network-Overview/
#

switch = Switch.new
buzzer = Buzzer.new

tft = TFT.new
tft.set_text_size(2)
tft.fill_screen(tft.black)

wifi = WiFi.new
wifi.disconnect

n = wifi.scan_networks
puts "found #{n} networks"

ssid_0 = wifi.ssid(0)
puts "SSID(0): #{ssid_0}"

all_ssid = wifi.scan_all_ssid
tft.set_text_color(tft.red)
tft.draw_string("SSID: #{all_ssid[0][:ssid]}", 0, 20)

tft.set_text_color(tft.blue)

if wifi.connect(SSID,  PASSWORD)
  tft.draw_string("IPAddress: #{wifi.local_ip}", 0, 50)
else
  tft.draw_string("connection failed.", 0, 50)
end

if wifi.connected?
  buzzer.buzz(128)
  sleep 1
  buzzer.buzz(0)
end

tft.set_text_color(tft.greenyellow)
host = "www.city.matsue.ed.jp"
port = 80

loop do
  tft.fill_rect(0, 100, tft.width, 300, tft.black)
  tft.draw_string("Connecting to #{host}", 0, 100)

  if wifi.connect_to_server(host, port)
    puts "OK connected to http server #{host}, #{port}"
  else
    puts "ERROR faild to connect to http server #{host}, #{port}"
    sleep 600
    next
  end

  wifi.write("GET /ooba-e/index.html HTTP/1.0\n\n")

  60.times do
    break if wifi.available > 0
    sleep 1
  end

  str_array = wifi.read_string().split("\n")

  str_array.each do |str|
    puts str
  end
  
  tft.draw_string(str_array[0], 0, 130)
  tft.draw_string(str_array[1], 0, 160)
  tft.draw_string(str_array[2], 0, 190)
  sleep 600
end
