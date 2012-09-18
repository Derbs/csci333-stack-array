#include <iostream>
#include "gtest/gtest.h"
#include "../src/Stack.h"

TEST(StackTest, Init) {
  Stack* s = new Stack();
  EXPECT_EQ(0, s->size());
  delete s;
}

TEST(StackTest, Push) {
  Stack* s = new Stack();
  s->push(6);

  EXPECT_EQ(6, s->peek());
  delete s;
}

TEST(StackTest, Resize) {
  Stack* stk = new Stack(5);
  for(int i = 0; i <= 4; i++) {
    stk->push(i);
  }
  EXPECT_EQ(5, stk->size());
  stk->push(5);
  
  //stack should be resized as 5 is pushed onto stk.  new size should be 10.  
  //if this isn't working, then we'll have an error in the push(int) method of Stack.  
  
  //tests to make sure values have been transferred!
  for(int i = stk->size(); i==0; i--) {
    EXPECT_EQ(i, stk->pop());
  }
}

