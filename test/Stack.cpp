#include <iostream>
#include "gtest/gtest.h"
#include "../src/Stack.h"

TEST(StackTest, Push) {
  Stack* s = new Stack();
  s->push(6);

  EXPECT_EQ(6, s->peek());
  delete s;
  std::cout << "Hi there?" << std::endl;

}
TEST(StackTest, Resize) {
  Stack* stk = new Stack(5);
  for(int i = 0; i < 4; i++) {
    stk->push(i);
  }
  EXPECT_EQ(4, stk->size());
  EXPECT_EQ(5, stk->getMaxSize());
  stk->push(4);
  EXPECT_EQ(10, stk->getMaxSize());
}

