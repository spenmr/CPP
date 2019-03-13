#ifndef LINK_H
#define LINK_H


class Link
{
    public:
        Link(int value, Link * next = nullptr)
            {this->value = value; this->next = next;}
        void setNext(Link * next)
            {this->next = next;}
        Link * getNext()
            {return next;}
        int getValue()
            {return value;}
    protected:
    private:
        int value;
        Link * next;
};

#endif // LINK_H
