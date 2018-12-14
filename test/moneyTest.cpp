#include <gtest/gtest.h>
#include "../include/Engine.hpp"

TEST (moneyTest, negativeBalance) {
  Engine e;
  int balance = e.getMoney;
  int endBalance = e.loseMoney(balance + 20);
  EXPECT_EQ (0, endBalance);
}


int main(int argc, char **argv)  {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
