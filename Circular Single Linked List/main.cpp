#include <iostream>
#include "circlist.h"


int main()
{
    CircList theList;

    std::cout << "Adding 3, 4, 7 to circular linked list" << std::endl;
    theList.addLink(3);
    theList.addLink(4);
    theList.addLink(7);

    std::cout << " the number 6 " << (theList.findValue(6) ? "is" : "is not") << " in the list" << std::endl;
    std::cout << " the number 4 " << (theList.findValue(4) ? "is" : "is not") << " in the list" << std::endl;

    std::cout << "\n\nNow emptying list, should be in reverse order" << std::endl;
    std::cout << theList.removeNext() << " ";
    std::cout << theList.removeNext() << " ";
    std::cout << theList.removeNext() << std::endl;

    std::cout << "\n\nAdding 1, 2, 3, 4, 5 to circular linked list" << std::endl;
    theList.addLink(1);
    theList.addLink(2);
    theList.addLink(3);
    theList.addLink(4);
    theList.addLink(5);

    std::cout << " stepping two, then emptying list, should get 3 2 1 5 4" << std::endl;
    theList.step(2);
    std::cout << theList.removeNext() << " ";
    std::cout << theList.removeNext() << " ";
    std::cout << theList.removeNext() << " ";
    std::cout << theList.removeNext() << " ";
    std::cout << theList.removeNext() << std::endl;


    return 0;
}
