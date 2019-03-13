#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <string>

// adding to the left adds to a queue starting at the left
// get from the left, gets from the tail of that queue
// add to the right, adds to a queue startnig on the right
// get from teh right gets from the tail of htat queue
class dequeue {
    private:
        static const int SIZE = 100;
        static const int NumPerLine = 10;
        int * theArray;
        int theSize;
        int left;
        int right;
        int numElements;
    public:
        dequeue();
        dequeue(int size);
        ~dequeue();
        void addLeft(int value);
        void addRight(int Value);
        int getLeft();
        int getRight();
        bool isEmpty();
        bool isFull();
        std::string listRightLeft();
        std::string listLeftRight();
        std::string dumpArray();
        void zeroOut();
};
#endif // DEQUEUE_H
