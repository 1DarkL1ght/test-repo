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

TEST(CandleTest, contains_test1){
  double open = 34.1, high = 36.9, close = 33.8, low = 28.4;
  Candle candle(open, high, low, close);
  double price = 35;
  EXPECT_TRUE(candle.contains(price));
}

TEST(CandleTest, contains_test2){
  double open = 34.1, high = 36.9, close = 33.8, low = 28.4;
  Candle candle(open, high, low, close);
  double price = 37;
  EXPECT_FALSE(candle.contains(price));
}

TEST(CandleTest, contains_test3){
  double open = 34.1, high = 36.9, close = 33.8, low = 28.4;
  Candle candle(open, high, low, close);
  double price = 28.3;
  EXPECT_FALSE(candle.contains(price));
}

TEST(CandleTest, fullsize_test1){
  double open = 34.1, high = 36.9, close = 33.8, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.full_size() == high - low);
}

TEST(CandleTest, fullsize_test2){
  double open = 34.1, high = 36.9, close = 34.1, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.full_size() == high - low);
}

TEST(CandleTest, fullsize_test3){
  double open = 34.1, high = 34.1, close = 28.4, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.full_size() == high - low);
}

TEST(CandleTest, body_size_test1){
  double open = 34.1, high = 34.1, close = 28.4, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.body_size() == open - close);
}

TEST(CandleTest, body_size_test2){
  double open = 34.1, high = 36.9, close = 34.1, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.body_size() == 0);
}

TEST(CandleTest, body_size_test3){
  double open = 34.1, high = 38.9, close = 35.8, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.body_size() == close - open);
}

TEST(CandleTest, is_red_test1){
  double open = 34.1, high = 38.9, close = 35.8, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.is_red() == false);
}

TEST(CandleTest, is_red_test2){
  double open = 34.1, high = 38.9, close = 33.8, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.is_red() == true);
}

TEST(CandleTest, is_red_test3){
  double open = 34.1, high = 34.1, close = 28.4, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.is_red() == true);
}

TEST(CandleTest, is_green_test1){
  double open = 34.1, high = 38.9, close = 35.8, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.is_green() == true);
}

TEST(CandleTest, is_green_test2){
  double open = 34.1, high = 38.9, close = 33.8, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.is_green() == false);
}

TEST(CandleTest, is_green_test3){
  double open = 34.1, high = 34.1, close = 28.4, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.is_green() == false);
}

TEST(CandleTest, constructor_test1){
  double open = 34.1, high = 38.9, close = 35.8, low = 28.4;
  Candle candle(open, high, low, close);
  EXPECT_TRUE(candle.open == open);
  EXPECT_TRUE(candle.high == high);
  EXPECT_TRUE(candle.low == low);
  EXPECT_TRUE(candle.close == close);
}

int main(int argc, char** argv){
  // std::cout << "Running tests..." << std::endl;
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  return 0;
}