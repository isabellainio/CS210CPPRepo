Append a new section to your A2README.md called ## Reflection Questions, and answer 
every question below directly underneath it, in your own words, 
referring to your own variable and function names. 
These are written so that a generic definition off the
internet will not answer them. 
If your answer could apply to anyone's stack instead of specifically yours, it is not finished.


## Reflection Questions

1) What value does topIndex hold immediately after construction, 
and why does that specific value make isEmpty() return the right answer with no special-casing?

topIndex holds a value of -1 immediately after construction. I used
-1 because the valid indexes in my data array start at 0. If topIndex is
-1, that means that there is no top element currently. My isEmpty() function
checks if topIndex = -1, so a newly created stack is recognized as empty automatically.

2) Walk through push step by step, in words: 
what happens to data and topIndex, in what order, 
and why would swapping that order break the stack?

My push() first checks whether the stack is full by calling isFull(). If the stack
is not full, I increase topIndex() by 1 and then store the new value in data[topIndex].

The order matters because an empty stack starts with topIndex equaling -1. The first
push needs to change topIndex to 0 before writing into the array. If I stored the value first
and incremented after, the first push would try to write //data[-1], which is not a valid array position.

3) Give the time complexity of push, 
pop, peek, isEmpty, isFull, and size, individually, in Big-O. 
For each one, justify it by describing what your code actually does, 
not by naming the general rule for stacks.

push() is O(1) because my code checks isFull(), increments topIndex
once, and stores one value in the array. It does not loop through
the stack.

pop() is O(1) because it checks isEmpty(), reads data[topIndex],
decreases topIndex once, and returns the saved value.

peek() is O(1) because it checks isEmpty() and directly returns data[topIndex].
It does not search through the array.

isEmpty() is O(1) because it only compares topIndex to -1

isFull() is O(1) because it only compares topIndex to 99

size() is O(1) because it only returns topIndex + 1


4) Exactly what happens in your code when push is called 
while the stack is full? State what prints (if anything), 
what gets returned (if anything), and whether topIndex changes. 
Then say why you chose that behavior.

If the stack is full, my isFull() function returns true because topIndex
is 99. My push() then prints: "Stack is full. Cannot push value."

After printing the message, the function uses return; and stops. Since 
push() has a void return type, it does not return a value. topIndex does not change,
so it stays at 99, and the contents of the stack remain unchanged.

I chose this behavior because the array only has 100 valid positions, so allowing
another push would go past the end limit of teh array. This keeps the program from
accessing invalid memory.

5) Exactly what happens when pop or peek is called while 
the stack is empty? Same level of detail as above.

If pop() is called while the stack is empty, my code prints:

"Stack is empty. Cannot pop value." It then returns -1. topIndex stays
at -1, so the stack remains empty. If a peek() is called while the stack is empty,
my code prints "Stack is empty. Cannot peek value." It also returns -1, and
topIndex does not change.

I chose -1 because the assignment does not allow exceptions, so I needed a 
way to show that the operation failed. One limitation is that -1 could also be a real value
stored in the stack, so the printed error message is important.

6) Your array is fixed at 100 slots. 
If a caller needed more room than that, 
what would have to change in your class to support it, 
and what would it likely cost in terms of the time complexity you gave in question 3?

Right now my class uses //int data[100]; which means it can only hold 100 values.
If a caller needed more room, the storage inside the class would have to change.
One option would be to make the fixed array size larger. That would
still keep methods push(), pop(), peek(), isEmpty(), isFull(), and size() at O(1).

If the class instead used other methods of storage that can change dynamically
when it became full, some pushes could take O(n) because the existing elements might
need to be copied into a larger block of memory. The other basic stack operations
could still remain O(1).

7) Without looking anything up: if this stack were built on a 
linked list instead of an array, name one advantage and one disadvantage 
that trade-off would bring, based on what you already know about how arrays and 
pointers behave differently.

One advantage of using a linked list would be that the stack would not have a fixed
100-element limit. New nodes could be added as needed instead of being
limited by the size of one array.

One disadvantage would be that each node would need a pointer in addition to the 
stored integer. That would use more memory per element and would make the implementation
more complicated because the code would have to manage pointers instead of
using simple array indexes.