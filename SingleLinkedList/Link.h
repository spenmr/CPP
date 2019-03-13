#ifndef LINK_H
#define LINK_H


class Link
{
    public:
        Link(int value = 0, Link * next = nullptr);
        virtual ~Link();

        void setNext(Link * next);

        int getValue();
        Link * getNext();
    protected:
    private:
        int value;
        Link * next;
};

#endif // LINK_H
