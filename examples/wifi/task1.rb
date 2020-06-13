puts "WiFi for mruby/c"

#-----------------------------------
# Set your WiFi SSID and PASSWORD.
#-----------------------------------
SSID     = "90324BD2D660-5G"
PASSWORD = "2215004388619"
#-----------------------------------

#
# Update farmware and install libraries.
# https://wiki.seeedstudio.com/Wio-Terminal-Network-Overview/
#

switch = Switch.new
buzzer = Buzzer.new

tft = TFT.new
tft.set_text_size(2)
tft.fill_screen(tft.cyan)

wifi = WiFi.new
wifi.disconnect
puts "wifi disconnected"

n = wifi.scan_networks
puts "found #{n} networks"

ssid_0 = wifi.ssid(0)
puts "SSID(0): #{ssid_0}"

all_ssid = wifi.scan_all_ssid
tft.set_text_color(tft.orange)
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

host = "192.168.3.10"
port = 8080

while true
  if wifi.connect_to_server(host, port)
    puts "OK connected to http server #{host}, #{port}"
  else
    puts "ERROR faild to connect to http server #{host}, #{port}"
  end

  wifi.write("GET /index.html HTTP/1.1\n\n")
  puts "OK wifi is available."

  60.times do
    break if wifi.available > 0
    sleep 1
  end

  str = wifi.read_string()
  puts str
  sleep 5
end

loop do; end
