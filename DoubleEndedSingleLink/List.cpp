#include "List.h"

    //Constructor, does initialization
List::List()
{
    head = tail = nullptr;
}

    //Destructor, delete any remaining links before going away
    //Same for single end or double end
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
        // special case empty list
    if ( head == nullptr )
        head = tail = new Link(value);
    else
        head = new Link(value, head);
}

//Add new value to tail
//Use constructor to simplify code
void List::addTail(int value)
{
    // special case empty list
    if ( head == nullptr )
        head = tail = new Link(value);
    else
    {
            // create new link
            // attach to end of list
            // update tail
        Link * temp = new Link(value);
        tail->setNext(temp);
        tail = temp;
    }
}

//Remove head and return value
int List::removeHead()
{
        //Deal with empty list
    if ( head == nullptr )
        throw std::underflow_error("Empty List");

    
    //Not empty, so delete the link
    
        //Save link to delete
    Link * temp = head;
    
        //Save value to return
    int value = temp->getValue();
    
        //Now, you can get rid of old link
    delete temp;
    
        //Update list
    head = head->getNext();

    
        //check if list now empty
        //if so, update tail
    if ( head == nullptr )
        tail = nullptr;

    return value;
}

    //Find item, return true if present
    // Same code for single or double ended list
bool List::findValue(int value)
{
        //Walk down the list, return if find
    for(Link * ptr = head; ptr != nullptr; ptr = ptr->getNext() )
        if ( ptr->getValue() == value )
            return true;
    
        // end of list without finding it, go home empty handed
    return false;
}

    //find item, if there delete it
    //Modified for presence of tail
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
                //Save link for deleting
            Link * temp = ptr->getNext();
                //update list
            ptr->setNext(temp->getNext());
                //remove the link
            delete temp;
                //if last item on list, update tail
            if ( ptr->getNext() == nullptr )
                tail = nullptr;
            
                //done, return with success
            return true;
        }
            //not yet found, keep looking
        ptr = ptr->getNext();
    }
        //was not there, go home empty handed
    return false;
}




