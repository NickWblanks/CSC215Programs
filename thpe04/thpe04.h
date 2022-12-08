/** **********************************************************************
 * @file
 ************************************************************************/

 /** **************************************************************************
  * @mainpage Take Home Programming Exam 04 - War
  *
  * @section course_section Course Information
  *
  * @author Nick Wilk
  *
  * @par Professor:
  *         Dr. Rodger Schrader
  *
  * @par Course:
  *         CSC215 - M001 - Programming Techniques
  *
  * @par Location:
  *         Classroom Building - M205
  *
  * @date Due December 9, 2022
  *
  * @section program_section Program Information
  *
  * @details
  * 
  * This program will play the game of war after generating two
  * decks of cards from either seeds or from files.
  * This program will fill two queues of type <card> with up to 52 
  * cards. The output of this program will inform the user
  * of which deck won, how many rounds it took to win, and
  * what the winners deck is.
  * 
  * Usage
  * thep04.exe -option argument2 agrument3
  * -option: is the option to run the program with either seeds
  * or from files. 
  * Argument2: If the option to run was -s, argument two must be
  * an integer representing the first seed. If -f is provided
  * this argument must be the name of the first file.
  * Argument3: If the option to run was -s, argument three must be
  * an integer representing the second seed. If -f is provided
  * this argument must be the name of the second file.
  *
  * @section compile_section Compiling and Usage
  *
  * @par Compiling Instructions:
  *      None - a standard compilation with no additional resources
  *
  * @par Usage:
    @verbatim
    c:\> thpe04.exe -option SeedORFile1 seedORfile2
             -option Either -s or -f, -s will run seed, -f will run files.
             seedORfile1 If -s is supplied this must be an integer. If -f this must be a file name.
             seedORfile2 If -s is supplied this must be an integer. If -f this must be a file name.



    @endverbatim
  *
  * @section todo_bugs_modification_section Todo, Bugs, and Modifications
  *
  * @bug 
  * The program does no error checking on secondary arguments.
  * if -s is supplied but filenames are given for the next 2 or vice versa
  * the program may not work properly.
  *
  *
  *
  * @par Modifications and Development Timeline:
  * This is a link to gitlab's commit as an example. To view <a target="_blank"
  * href="https://gitlab.cse.sdsmt.edu/101095827/csc215f22programs/-/tree/main/thpe04">click here.</a>
  *
  *****************************************************************************/

#pragma once
#include "..\\catch.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <string>
#include <random>


/** **********************************************************************
 *
 * @brief RUNCATCH a variable to determine to run catch.
 *
 *************************************************************************/



const bool RUNCATCH = false;


using namespace std;

/** **********************************************************************
 *
 * @brief A structure named Card that holds the data for a single card.
 *
 *************************************************************************/

struct card
{
    int faceValue; /**< The Face Value of a card from 0-12 */
    int suit; /**< The suit of a card from 0-3 */
    card operator=( const card rhs);
    bool operator==( const card right);
};

/** **********************************************************************
 *
 * @brief A structure named Card2 that holds the data for a single card.
 *
 *************************************************************************/

struct card2
{
    string face; /**< The Face Value of a card in the form of strings */
    string suit; /**< The suit of a card in the form of strings */
    card2 operator=(const card2 rhs);
    bool operator==(const card2 right);
};



/** **********************************************************************
 * @class queue
 * 
 * @brief A class named queue, it is singly linked list based and can hold
 * any data type.
 *
 *************************************************************************/

template <class ty>
class queue
{
public:
    queue( );
    queue(queue<ty> &q);
    ~queue( );

    bool pop(ty &item);
    bool push(ty item);
    bool front(ty &item);
    int size( );
    bool empty( );
    void print(ostream &out);
    bool SameCheck(ty item);//finds if card already exists in deck.

    friend ostream& operator<< (ostream& out, const queue<card>& q);
    friend ostream& operator<<(ostream& out, const queue<card2>& q);


private:

 /**
  * @brief A container to hold each item in a list.
 **/
    struct node
    {
        ty theCard; /*!< The data being held within a node */
        node* next; /*!< A pointer to the next node in the list */
    };
    node *headptr; /*!< Where the list begins */
    node *tailptr; /*!< Where the list ends */
};


/** **********************************************************************
 * @author Nicholas Wilk
 * 
 * @par description 
 * The constructore for the queue class.
 *************************************************************************/
template <class ty>
queue<ty>::queue() //constructor
{
    headptr = nullptr;
    tailptr = nullptr;
}

/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par description
 * The copy constructor for the queue class.
 * 
 * @param[in] q the queue to be copied in.
 *************************************************************************/

template <class ty>
queue<ty>::queue(queue<ty>& q)
{
    if (q.empty() == true)
    {
        headptr = nullptr;
        return;
    }
    headptr = nullptr;
    node* copy = q.headptr;
    node* paste;

    headptr = new (nothrow) node;
    headptr->theCard = copy->theCard;//copy 1 item in.
    headptr->next = nullptr;

    copy = q.headptr->next; //seek next item
    paste = headptr;
    while (copy != nullptr) //if next is null drop out
    {
        paste->next = new (nothrow) node;
        paste = paste->next;
        paste->theCard = copy->theCard;
        paste->next = nullptr;
        copy = copy->next;
    }
}


/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par description
 * The destructor for the queue class.
 *************************************************************************/

template <class ty>
queue<ty>::~queue() //destructor
{
    node* temp;
    temp = headptr;
    while (temp != nullptr)
    {
        delete temp;
        temp = temp->next;
    }
}


/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par description
 * The empty function for the queue class.
 * 
 * @returns True/False True if empty, false if not.
 *************************************************************************/

template <class ty>
bool queue<ty>::empty() //checks for an empty list
{
    if (headptr == nullptr)
    {
        return true;
    }
    return false;
}


/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par description
 * The size function for the queue class.
 *
 * @returns An integer, representing the size of the queue.
 *************************************************************************/


template <class ty>
int queue<ty>::size() //returns list size
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


/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par description
 * The push/enqueue function for the queue class.
 * 
 * @param[in] item The item to add to a list.
 *
 * @returns True/False True if the item was added, false if not.
 *************************************************************************/


template <class ty>
bool queue<ty>::push(ty item)  //enque/insert, only inserts at end.
{
    node* temp;
    temp = new (nothrow) node;
    if (temp == nullptr)
    {
        return false;
    }
    temp->theCard = item;
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


/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par description
 * The pop/dequeue function for the queue class.
 * 
 * @param[in] item The item to store the first element into.
 *
 * @returns True/False True if the item was removed and stored, false if not.
 *************************************************************************/

template <class ty>
bool queue<ty>::pop(ty &item)
{
    node* temp;
    temp = headptr;
    if (empty() == true) //cant remove from empty list
    {
        return false;
    }
    item = headptr->theCard; //stores first in list in param
    headptr = headptr->next;//removes front item
    delete temp;
    return true;
}

/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par description
 * The front function for the queue class.
 * 
 * @param[in] item The item to store the first element into.
 *
 * @returns True/False True if the item was stored, false if not.
 *************************************************************************/

template <class ty>
bool queue<ty>::front(ty &item)
{
    if (empty() == true)
    {
        return false;
    }
    item = headptr->theCard; //stores first in list in param
    return true;
}


/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par description
 * The print function for the queue class.
 * 
 * @param[in] out The ostream to output to.
 *
 *************************************************************************/

template <class ty>
void queue<ty>::print(ostream& out)
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


/** **********************************************************************
 * @author Nicholas Wilk
 *
 * @par description
 * The sameCheck function for the queue class.
 * 
 * @param[in] item The item to search for.
 *
 * @returns True/False True if the item was in the list, false if not.
 *************************************************************************/

template <class ty>
bool queue<ty>::SameCheck(ty item)//checks if item already exists in list
{
    node* temp;
    temp = headptr;
    while (temp != nullptr)
    {
        if (temp->theCard == item)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}



int getCard(int seed);

void usageStatement();

int CmdCheck(int count, char* arg1);

void chooseRun(char* option, int s1, int s2, char* file1, char* file2, ifstream& fin);

void runSeed(int seed1, int seed2);

void runFile(char* file1, char* file2, ifstream& fin);

template <class ty>
void fillDeckS(queue<ty> &deck, int seed);

template <class ty>
void fillDeckF(ifstream& fin, queue<ty> &deck);

template <class ty>
void WAR(queue<ty>& deck1, queue<ty> &deck2);

template <class ty>
void playRound(queue<ty>& player1, queue<ty>& player2);

