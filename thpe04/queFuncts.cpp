/** **********************************************************************
 * @file
 ************************************************************************/

#include "thpe04.h"

/** **********************************************************************
 * @author Nicholas Wilk
 * 
 * @par Description
 * The overloaded operator = for the card structure.
 * It assigns both the face value and the suit to the new card.
 * 
 * @param[in] rhs the right hand side of the = operator.
 * 
 * @returns A card with the contents of the right hand sided card.
 * 
 ************************************************************************/

card card::operator=(const card rhs)
{
    faceValue = rhs.faceValue;
    suit = rhs.suit;
    return *this;
}

/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par Description
 * The overloaded operator == for the card structure.
 * It checks if both the face value and suit are the same.
 *
 * @param[in] right the right hand side of the = operator.
 *
 * @returns True/False true if they are the same, false if not.
 *
 ************************************************************************/

bool card::operator==( const card right)
{
    return faceValue == right.faceValue && suit == right.suit;
}

/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par Description
 * The overloaded operator = for the card2 structure.
 * It assigns both the face value and the suit to the new card.
 *
 * @param[in] rhs the right hand side of the = operator.
 *
 * @returns A card2 with the contents of the right hand sided card.
 *
 ************************************************************************/

card2 card2::operator=(const card2 rhs)
{
    face = rhs.face;
    suit = rhs.suit;
    return *this;
}

/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par Description
 * The overloaded operator == for the card2 structure.
 * It checks if both the face value and suit are the same.
 *
 * @param[in] right the right hand side of the = operator.
 *
 * @returns True/False true if they are the same, false if not.
 *
 ************************************************************************/


bool card2::operator==(const card2 right)
{
    return face == right.face && suit == right.suit;
}


/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par Description
 * The overloaded friend operator << for the queue class.
 * It outputs the class in a specific way. Only works for the card structure.
 *
 * @param[in] out The output type.
 * 
 * @param[in] q the queue to output.
 *
 * @returns The ostream, the output to whichever platform.
 *
 ************************************************************************/


ostream& operator<< (ostream& out, const queue<card>& q)
{
    queue<card>::node* temp;
    temp = q.headptr;
    while (temp != nullptr)
    {
        out << temp->theCard.faceValue
            << " -- " << temp->theCard.suit << endl;
        temp = temp->next;
    }
    return out;
}

/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par Description
 * The overloaded friend operator << for the queue class.
 * It outputs the class in a specific way. Only works with the 
 * card2 structure.
 *
 * @param[in] out The output type.
 *
 * @param[in] q the queue to output.
 *
 * @returns The ostream, the output to whichever platform.
 *
 ************************************************************************/

ostream& operator<< (ostream& out, const queue<card2>& q)
{
    queue<card2>::node* temp;
    temp = q.headptr;
    while (temp != nullptr)
    {
        out << temp->theCard.face << " of " 
            << temp->theCard.suit << endl;
        temp = temp->next;
    }
    return out;
}


