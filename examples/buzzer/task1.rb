puts "Buzzer for mruby/c"

buzzer = Buzzer.new

10.times do
  buzzer.buzz(128)
  sleep 1
  buzzer.buzz(0)
  sleep 1
end

puts "OK complete."
while true; sleep 1; end
