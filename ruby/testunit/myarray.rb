class MyArray
  def initialize
    @array = []
  end

  def empty?
    @array.empty?
  end

  def << o
    @array << o
    self
  end
end
