class WiFi

  def scan_all_ssid(try_count = 10)
    n = try_count

    while n > 0
      ssid_count = scan_networks

      if ssid_count < 1
        sleep 0.5
        n -= 1
        next
      end
      
      ssid_array = []
    
      (ssid_count - 1).times do |i|
        ssid_array << {ssid: ssid(i), rssi: rssi(i)}
      end

      return ssid_array
    end

    return []
  end

  def connect(ssid, password, try_count = 60)
    self.begin(ssid, password)
    n = try_count
    
    while true
      sleep 1
      return true if connected?
      n -= 1
      break if n == 0
    end

    return false
  end
  
end
