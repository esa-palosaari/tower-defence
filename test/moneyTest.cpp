#include <gtest/gtest.h>
#include "../include/Engine.hpp"
#include "../include/Tower.hpp"
#include "../include/Projectile.hpp"
#include "../include/TileMap.hpp"
#include "../include/Types.hpp"
#include "../include/UserGraphics.hpp"

TEST (moneyTest, negativeBalance) {
  Engine e;
  e.setMoney(100);
  int balance = e.getMoney();
  int moMoney = balance + 20;
  e.loseMoney(moMoney);
  int endBalance = e.getMoney();
  EXPECT_EQ (0, endBalance);
}


int main(int argc, char **argv)  {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
