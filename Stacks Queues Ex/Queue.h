#ifndef QUEUE_H
#define QUEUE_H
#include <exception>

class QueueEmpty : public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "Error: Queue Empty";
        }
};

class Queue
{
    public:
            // Constructors and Destructor
        Queue();
        Queue(int s);
        virtual ~Queue();

            // Access Methods
        void addTail(int value);
        int removeHead();

            // Status Methods
        bool isEmpty();
        bool isFull();

    protected:
    private:
        static const int SIZE = 100;
        int *arr;
        int size;
        int head;
        int tail;
        int count;
};

#endif // QUEUE_H
