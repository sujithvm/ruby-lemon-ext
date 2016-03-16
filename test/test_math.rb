require "test/unit"
require File.expand_path('../../lib/ruby_lemon', __FILE__)

class TestMath < Test::Unit::TestCase

  def test_constant_values
    assert_equal(Lemon::E, 2.718281828459045)
    assert_equal(Lemon::LOG2E, 1.4426950408889634)
    assert_equal(Lemon::LOG10E, 0.4342944819032518)
    assert_equal(Lemon::LN2, 0.6931471805599453)
    assert_equal(Lemon::LN10, 2.302585092994046)
    assert_equal(Lemon::PI, 3.141592653589793)
    assert_equal(Lemon::PI_2, 1.5707963267948966)
    assert_equal(Lemon::PI_4, 0.7853981633974483)
    assert_equal(Lemon::SQRT2, 1.4142135623730951)
    assert_equal(Lemon::SQRT1_2, 0.7071067811865476)    
  end 

  def test_round
    assert_equal(Lemon::round(5.6), 6.0)   
    assert_equal(Lemon::round(3.4), 3.0)   
    assert_equal(Lemon::round(7.5), 8.0)   
  end  

end
