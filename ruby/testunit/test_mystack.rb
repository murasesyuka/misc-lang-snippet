require 'test/unit'
require './mystack'

class TestMyStack < Test::Unit::TestCase
  def setup
    @stack = MyStack.new
  end

  def test_empty_by_empty_myarray
    assert(@stack.empty?,"empty error")
  end
end
