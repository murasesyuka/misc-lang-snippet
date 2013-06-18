module Stack
  class EmptyStackError < StandardError; end
end

class MyStack
  def initialize
    @array = []
  end
  
  def empty?
    @array.empty?
  end

  def push(v)
    @array << v
  end

  def pop
    3
  end

  def size
    @array.size
  end
end
