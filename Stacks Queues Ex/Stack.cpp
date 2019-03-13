#include "Stack.h"
#include <stdexcept>

            // Constructors
Stack::Stack()
{
    size = SIZE;
    arr = new int[size];
    top = 0;
}
Stack::Stack(int s)
{
    size = s;
    arr = new int[size];
    top = 0;
}
Stack::~Stack()
{
    delete [] arr;
}

            // Access Methods
void Stack::push(int value)
{
    if ( isFull() )
    {
        int * tempArr = new int[size*2];
        for(int i = 0; i < size; i++)
            tempArr[i] = arr[i];
        delete [] arr;
        arr = tempArr;
        size *= 2;
    }
    arr[top++] = value;
}
int Stack::pop()
{
    if ( isEmpty() )
        throw std::underflow_error("Error: Stack Empty!");
    return arr[--top];
}
int Stack::peek()
{
    return arr[top-1];
}

            // Status Methods
bool Stack::isEmpty()
{
    return top == 0;
}
bool Stack::isFull()
{
    return top == size;
}
