require 'test/unit'
require './myarray'

class TestMyArray < Test::Unit::TestCase
  def setup
    @array = MyArray.new
  end

  def test_empty_by_empty_myarray
    assert(@array.empty?)
  end
end
