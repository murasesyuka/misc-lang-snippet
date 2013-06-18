require 'test/unit'
require './mystack'

class TestMyStack < Test::Unit::TestCase
  def setup
    @stack = MyStack.new
  end

  def test_empty_by_empty_myarray
    assert(@stack.empty?,"empty error")
  end

  def test_push_and_empty_myarray
    @stack.push(3)
    assert(!@stack.empty?)
  end

  def test_push_and_pop_myarray
    @stack.push(3)
    assert_equal(@stack.pop, 3)
  end

  def test_empty_pop_and_expect_exception_myarray
    ex = assert_raise(Stack::EmptyStackError){
      @stack.pop
    }
  end

  def test_push_and_size_myarray
    @stack.push(3)
    assert_equal(@stack.size, 1)
    
    @stack.push(5)
    assert_equal(@stack.size, 2)
  end
end
