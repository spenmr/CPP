#include "DList.h"

    // Constructor, same as single Linked List
DList::DList()
{
   head = tail = nullptr;
}
    //Destructor, same as single linked list
DList::~DList()
{
    DLink * ptr = head;
    while ( ptr != nullptr )
    {
        DLink * temp = ptr;
        ptr = ptr->getNext();
        delete temp;
    }
}
    //AddHead, similar to single linked, need to deal with previous
void DList::addHead(int value)
{
        //special case emtpy list
    if ( head == nullptr )
        head = tail = new DLink(value);
    
        //regular list, create new link and attach to list
    else
    {
        DLink * temp = new DLink(value, head);
        head->setPrev(temp);
        head = temp;
    }
}
    //AddTail, similar to addhad
void DList::addTail(int value)
{
    //special case emtpy list
    if ( tail == nullptr )
        head = tail = new DLink(value);
    
    //regular list, create new link and attach to list
    else
    {
        DLink * temp = new DLink(value);
        temp->setPrev(tail);
        tail->setNext(temp);
        tail = temp;
    }
}

    //Remove head, similar to single link
    // just take care of previous
int DList::removeHead()
{
        //Deal with empty list
    if ( head == nullptr )
        throw std::underflow_error("Empty List");

        //Not empty, save link for deletion
    DLink * temp = head;
    
        //Update head
    head = head->getNext();
    
        //if list is now empty, update tail
        //if not, then set previous on new head
    if ( head == nullptr )
        tail = nullptr;
    else
        head->setPrev(nullptr);
    
        //save value
        // delete link
        // and return
    int value = temp->getValue();
    delete temp;
    return value;
}

    //No remove tail on single linked list
    // very similar to remove head
int DList::removeTail()
{
    //Deal with empty list
    if ( tail == nullptr )
        throw std::underflow_error("Empty List");
    
    //Not empty, save link for deletion
    DLink * temp = tail;
    
    //Update tail
    tail = tail->getPrev();
    
    //if list is now empty, update head
    //if not, then set next on new tail
    if ( tail == nullptr )
        head = nullptr;
    else
        tail->setNext(nullptr);
    
    //save value
    // delete link
    // and return
    int value = temp->getValue();
    delete temp;
    return value;
}

    //Find Value -- same as single list
bool DList::findValue(int value)
{
    for(DLink * ptr = head; ptr != nullptr; ptr = ptr->getNext() )
        if ( ptr->getValue() == value )
            return true;
    return false;
}

    //Find and remove, simpler than single list
    // do not need to look ahead
bool DList::findRemove(int value)
{
        //Check for empty list
    if ( head == nullptr )
        return false;
    
        //Now, walk down list until find it
    for(DLink * ptr = head; ptr != nullptr; ptr = ptr->getNext() )
        if ( ptr->getValue() == value )
        {
                // if not last, set up next
                // otherwise reset tail
            if ( ptr->getNext() != nullptr )
                ptr->getNext()->setPrev(ptr->getPrev());
            else
                tail = ptr->getPrev();

                // if not first, set up prev
                // otherwise reset head
            if ( ptr->getPrev() != nullptr )
                ptr->getPrev()->setNext(ptr->getNext());
            else
                head =ptr->getNext();

                // delete the link
                // and return success
            delete ptr;
            return true;
        }
    
        // got to end without finding it
        // return empty handed
    return false;
}






