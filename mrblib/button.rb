class Button

  def pushed?(button)
    return status(0) if button == :a
    return status(1) if button == :b
    return status(2) if button == :c

    puts "Invalid button #{button}"
  end
  
end
