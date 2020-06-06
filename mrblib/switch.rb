class Switch

  def pushed?(status)
    return status(0) if status == :up
    return status(1) if status == :down
    return status(2) if status == :left
    return status(3) if status == :right
    return status(4) if status == :press

    puts "Invalid button #{button}"    
  end
  
end
