#include "Stack.h"
#include <iostream>
#include "assert.h"

Stack::Stack(int initialSize) {
  theStack = new int[initialSize];
  top = 0;
  maxSize = initialSize;
}

Stack::~Stack() {
  delete[] theStack;
}

void Stack::push(int value) {
  //if theStack is full
  // create new stack twice as big
  // copy all elements to new stack
  // delete old stack
  // point old stack pointer to new stack
  if(top>=maxSize) {
    int* holder = theStack; 
    theStack = new int[maxSize*2];
    for(int i=0; i<top; i++) {
      theStack[i] = holder[i];
    }
    delete[] holder;
    maxSize = 2*maxSize;
  }
  assert(top!=maxSize);
  theStack[top] = value;
  top++;
}

int Stack::pop() {
  top--;
  return theStack[top];
}

int Stack::peek() {
  return theStack[top-1];
}

int Stack::size() {
  return top;
}

