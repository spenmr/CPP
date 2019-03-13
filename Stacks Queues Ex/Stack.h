#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
            // Constructors
        Stack();
        Stack(int s);
        virtual ~Stack();

            // Access Methods
        void push(int value);
        int pop();
        int peek();

            // Status Methods
        bool isEmpty();
        bool isFull();

    protected:
    private:
        static const int SIZE = 100;
        int *arr;
        int size;
        int top;
};

#endif // STACK_H
