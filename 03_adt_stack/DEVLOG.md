# Development Log

## Sep 14, 2026

I updated Stack.h and Stack.cpp to follow the A2 requirements. I used a fixed 
C-style array called data with 100 slots instead of the vector mentioned in the original repo comments.
I set topIndex to -1 in the constructor so that the stack starts empty.

## Sep 14, 2026

I implemented push(), pop(), peek(), isEmpty(), isFull(), and size(). I decided
that if push() is called when the stack is full, it will print an error message
and leave the stack unchanged. If pop() or peek() is called when the stack is empty, it will
print an error message and return -1. I chose this because A2 does not allow 
exceptions, and this gives the user an indication that the operation failed.

## Sep 14, 2026

I added tests in main.cpp for normal stack operations and the boundary cases.
I tested pushing and popping values, peeking at the top value, popping and peeking an 
empty stack, and trying to push a 101st value into a full stack. If I did
this differently, I would test each function immediately after implementing all the functions before testing them. 