#include "List.h"

    //Constructor, does initialization
List::List()
{
    head = nullptr;
}

    //Destructor, delete any remaining links before going away
List::~List()
{
    Link * ptr = head;
    while ( ptr != nullptr )
    {
        Link * temp = ptr;
        ptr = ptr->getNext();
        delete temp;
    }
}
    //Add new value to head
    //Use constructor to simplify code
void List::addHead(int value)
{
    head = new Link(value, head);
}

    //Remove head and return value
int List::removeHead()
{
        //Deal with empty list
    if ( head == nullptr )
        throw std::underflow_error("Empty List");

        //Save link to delete later
    Link * temp = head;
        //Save value to return
    int value = temp->getValue();
        //Update list
    head = head->getNext();
        //Get rid of old link
    delete temp;

    return value;
}

bool List::findValue(int value)
{
    for(Link * ptr = head; ptr != nullptr; ptr = ptr->getNext() )
        if ( ptr->getValue() == value )
            return true;
    return false;
}

bool List::findRemove(int value)
{
        // deal with emtpy list
    if ( head == nullptr )
        return false;
    
        // special case at start of list
    if ( head->getValue() == value )
    {
        removeHead();
        return true;
    }
        // Ordinary link
        // Have to look ahead so we can remove it
    Link * ptr = head;
        // See if something there to test
    while ( ptr->getNext() != nullptr )
    {
            // found it, now update the list
        if ( ptr->getNext()->getValue() == value )
        {
            Link * temp = ptr->getNext();
            ptr->setNext(temp->getNext());
            delete temp;
            return true;
        }
            //not yet found, keep looking
        ptr = ptr->getNext();
    }
        //was not there, go home empty handed
    return false;
}




