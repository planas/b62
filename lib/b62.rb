require "b62/b62"

class Integer
  def to_b62
    raise RangeError, "#{self.class} must be positive to be encoded" if self < 0
    
    B62.to_b62(self)
  end
end