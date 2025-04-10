#include <iostream>
#include <gtest/gtest.h>
#include "candle.h"

// low < open < close < high
TEST(CandleTest, body_contains_test1){
  double open = 33.8, high = 36.9, low = 28.4, close = 34.1;
  Candle candle(open, high, low, close);
  double price = 34.1;
  EXPECT_TRUE(candle.body_contains(price));
  price = 35;
  EXPECT_FALSE(candle.body_contains(price));
  price = 29;
  EXPECT_FALSE(candle.body_contains(price));
}

// low < close < open < high
TEST(CandleTest, body_contains_test2){
  double open = 34.1, high = 36.9, close = 33.8, low = 28.4;
  Candle candle(open, high, low, close);
  double price = 34.1;
  EXPECT_TRUE(candle.body_contains(price));
  price = 29;
  EXPECT_FALSE(candle.body_contains(price));
  price = 35;
  EXPECT_FALSE(candle.body_contains(price));
}

// low = close < open = high
TEST(CandleTest, body_contains_test_3){
  double open = 22.1, high = 22.1, close = 15.3, low = 15.3;
  Candle candle(open, high, low, close);
  double price = 17;
  EXPECT_TRUE(candle.body_contains(price));
  price = 28;
  EXPECT_FALSE(candle.body_contains(price));
  price = 14;
  EXPECT_FALSE(candle.body_contains(price));
}

int main(int argc, char** argv){

  return 0;
}