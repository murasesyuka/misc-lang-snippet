class MyArray
  def initialize
    @array = []
  end

  def empty?
    true
  end

  def << o
    @array << o
    self
  end
end
