puts "WiFi for mruby/c"

#-----------------------------------
# Set your WiFi SSID and PASSWORD.
#-----------------------------------
SSID     = "************"
PASSWORD = "************"
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

loop do; end
