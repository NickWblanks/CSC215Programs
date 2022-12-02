#include "thpe04.h"

queue::queue() //constructor
{
    headptr = nullptr;
    tailptr = nullptr;
}

queue::~queue() //destructor
{
    node* temp;
    while (headptr != nullptr)
    {
        temp = headptr;;
        headptr = temp->next;
        delete temp;
    }
}

bool queue::empty() //checks for an empty list
{
    if (headptr == nullptr)
    {
        return true;
    }
    return false;
}

int queue::size() //returns list size
{
    node* temp;
    temp = headptr;
    int count = 0;
    if (headptr == nullptr) //empty list
    {
        return count;
    }
    while (temp != nullptr) //traverse list until end.
    {
        temp = temp->next;
        count++;
    }
    return count;
}

bool queue::push(card item)  //enque/insert, only inserts at end.
{
    node* temp;
    node* prev = headptr;
    node* curr = headptr;
    temp = new (nothrow) node;
    if (temp == nullptr)
    {
        return false;
    }
    temp->theCard.faceValue = item.faceValue;
    temp->theCard.suit = item.suit;
    temp->next = nullptr;
    if (empty() == true)//insert empty
    {
        headptr = temp;
        tailptr = temp;
        return true;
    }
    //insert end
    tailptr->next = temp;
    tailptr = temp;
    return true;
}

bool queue::pop(card &item)
{
    node* temp;
    temp = headptr;
    int fNum = 1;
    if (empty() == true) //cant remove from empty list
    {
        return false;
    }
    item = headptr->theCard; //stores first in list in param
    headptr = headptr->next;//removes front item
    delete temp;
    return true;
}

bool queue::front(card &item)
{
    if (empty() == true)
    {
        return false;
    }
    item = headptr->theCard; //stores first in list in param
    return true;
}

void queue::print(ostream &out)
{
    node* temp;
    temp = headptr;
    out << "Face Value" << " -- " << "Suit" << endl;
    while (temp != nullptr)
    {
        out << temp->theCard.faceValue << " -- " 
            << temp->theCard.suit << endl;
        temp = temp->next;
    }
}