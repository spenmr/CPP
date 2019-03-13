#include "Queue.h"
#include <stdexcept>

QueueEmpty theException;

    // Constructors and Destructor
Queue::Queue()
{
    size = SIZE;
    arr = new int[size];
    tail = 0;
    head = -1;
    count = 0;
}
Queue::Queue(int s)
{
    size = s;
    arr = new int[size];
    tail = 0;
    head = -1;
    count = 0;
}
Queue::~Queue()
{
    delete [] arr;
}

    // Access Methods
void Queue::addTail(int value)
{
    if ( isFull() )
    {
        int * tempArr = new int[size*2];
        int tempCount = count;
        for(int i = 0; i < size; i++)
            tempArr[i] = removeHead();
        tail = size;
        head = -1;
        count = tempCount;
        delete [] arr;
        arr = tempArr;
        size *= 2;
    }
    arr[tail++] = value;
    if ( tail == size )
        tail = 0;
    count++;
}
int Queue::removeHead()
{
    if ( isEmpty() )
        throw theException;

    if ( head == size -1 )
        head = -1;
    int temp = arr[++head];

    count--;

    return temp;
}

    // Status Methods
bool Queue::isEmpty()
{
    return count == 0;
}
bool Queue::isFull()
{
    return count == size;
}
