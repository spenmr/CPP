#include <iostream>
#include "list.h"
#include "stack.h"
#include "queue.h"


int main()
{
    List theList;

    std::cout << "Adding 3, 4, 2 to the List" << std::endl;
    theList.addHead(3);
    theList.addHead(4);
    theList.addHead(2);

    std::cout << " the number 6 " << (theList.find(6) ? "is" : "is not") << " in the list" << std::endl;
    std::cout << " the number 4 " << (theList.find(4) ? "is" : "is not") << " in the list" << std::endl;

    Stack theStack;

    std::cout << "\n\nNow pushing 6, 2, 3 on the Stack, then popping " << std::endl;
    theStack.push(6);
    theStack.push(2);
    theStack.push(3);

    std::cout << theStack.pop() << " ";
    std::cout << theStack.pop() << " ";
    std::cout << theStack.pop() << std::endl;

    Queue theQueue;

    std::cout << "\n\nNow adding 6, 2, 3 to the tail of the Queue, then removing at head " << std::endl;
    theQueue.addTail(6);
    theQueue.addTail(2);
    theQueue.addTail(3);

    std::cout << theQueue.removeHead() << " ";
    std::cout << theQueue.removeHead() << " ";
    std::cout << theQueue.removeHead() << std::endl;
    return 0;
}
