require 'test/unit'
require './mystack'

class TestMyStack < Test::Unit::TestCase
  def setup
    @stack = MyStack.new
  end

  def test_empty_by_empty_myarray
    assert(@stack.empty?,"empty error")
  end

  def test_push_and_pop_myarray
    @stack.push(3)
    assert_equal(@stack.pop, 3)
  end
end
