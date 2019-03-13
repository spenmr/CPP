#include "circlist.h"

    // constructor, set up empty list
CircList::CircList()
{
    cur = nullptr;
}

    // destructor, delete any remaining links
CircList::~CircList()
{
    while (cur != nullptr)
    {
        removeNext();
    }
}
    //If empty, add link at current
    //Else add link at current->next
void CircList::addLink(int value)
{
   if ( cur == nullptr )
   {
        cur = new Link(value);
        cur->setNext(cur);
   }
   else
   {
       cur->setNext(new Link(value, cur->getNext()));
   }
}
    //find if value is on the list
bool CircList::findValue(int value)
{
        //empty list, no values
    if ( cur == nullptr )
        return false;

        //singleton list, see if has value
    if ( cur->getNext() == cur )
        if ( cur->getValue() == value )
            return true;
        else
            return false;

    Link * ptr = cur;

    do {
        if ( ptr->getValue() == value )
            return true;
        ptr = ptr->getNext();
    } while ( ptr != cur );

    return false;
}
    // remove the item that cur points to
int CircList::removeNext()
{
        // nothing there, mistake
    if ( cur == nullptr )
    {
        throw std::underflow_error("Empty List");
    }

        // singleton list, set to be empty
    if ( cur->getNext() == cur )
    {
        int value = cur->getValue();
        delete cur;
        cur = nullptr;
        return value;
    }

    Link * temp = cur->getNext();
    cur->setNext(temp->getNext());
    int value = temp->getValue();
    delete temp;
    return value;
}
    // return the value at next node
int CircList::showNext()
{
    if ( cur == nullptr )
    {
        throw std::underflow_error("Empty List");
    }

    return cur->getNext()->getValue();
}
    // find link with given value
    // if present remove and return true
    // else return false
bool CircList::findRemove(int value)
{
        // empty list, nothing there to find
    if ( cur == nullptr )
        return false;

        // if singleton list, set up as empty
    if ( cur->getNext() == cur )
        if ( cur->getValue() == value )
        {
             delete cur;
             cur = nullptr;
             return true;
        }
        else
            return false;

        // real list, now walk down it to see if there
    Link * ptr = cur;

    do {
        if ( ptr->getValue() == value )
        {
            Link * temp = ptr;
            cur->setNext(temp->getNext());
            if ( cur == temp )
                cur = temp->getNext();
            delete temp;
            return true;
        }
        ptr = ptr->getNext();
    } while ( ptr != cur );

    return false;
}
std::string CircList::displayCirc()
{
    // left as exercise for students
}
void CircList::step(int steps)
{
    for (int i = 0; i < steps; i++)
        cur = cur->getNext();
}
