require 'test/unit'
require 'b62'

class B62Test < Test::Unit::TestCase
  def test_fixnum_becomes_string
    assert_kind_of String, 68.to_b62
  end

  def test_bignum_becomes_string
    assert_kind_of String, 18446744073709551615.to_b62
  end

  def test_negative_input_raises_exception
    assert_raise RangeError do
      -1.to_b62
    end
  end

  def test_too_big_input_raises_exception
    assert_raise RangeError do
      18446744073709551616.to_b62
    end
  end

  def test_some_known_results
    values = Hash[ 0 => "0",
                   8 => "8", 
                   25 => "P",
                   62 => "10", 
                   28022013 => "1tZnx",
                   18446744073709551615 => "LygHa16AHYF"]

    values.each do |input, output|
      assert_equal input.to_b62, output
    end
  end

end