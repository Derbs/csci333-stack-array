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
  for(int i = 0; i <= 4; i++) {
    stk->push(i);
    EXPECT_EQ(5, stk->getMaxSize());
  }
  EXPECT_EQ(5, stk->size());
  stk->push(5);
  
  EXPECT_EQ(10, stk->getMaxSize());  //tests to make sure stack has been properly resized

  //tests to make sure values have been transferred!
  for(int i = stk->size(); i==0; i--) {
    EXPECT_EQ(i, stk->pop());
  }
}

