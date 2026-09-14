// TASK 03 -- Using the Stack ADT

#include <iostream>
#include "Stack.h"

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack size: " << s.size() << std::endl;
    std::cout << "Top: " << s.peek() << std::endl;

    std::cout << "Popped: " << s.pop() << std::endl;

    s.pop();
    std::cout << "After pop, top: " << s.peek() << std::endl;
    std::cout << "Size now: " << s.size() << std::endl;

    //Test popping/peeking an empty stack

    Stack emptyStack;

    std::cout << "\nPopping empty stack: " << emptyStack.pop() << std::endl;
    std::cout << "Peeking empty stack " << emptyStack.peek() << std::endl;

    //Test pushing onto a full stack

    std::cout << "\nTesting full stack: " << std::endl;

    Stack fullStack;

    for (int i = 0; i < 100; i++)
    {
        fullStack.push(i);
    }

    std::cout << "Size when full: " << fullStack.size() << std::endl;

    fullStack.push(100);

    std::cout <<"Size after failed push: " << fullStack.size() << std::endl;

    return 0;
}
