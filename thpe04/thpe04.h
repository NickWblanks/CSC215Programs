
#pragma once
#include "..\\catch.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <string>
#include <random>

const bool RUNCATCH = true;


using namespace std;

struct card
{
    int faceValue;
    int suit;
};

class queue
{
public:
    queue( );
    queue(queue &q);
    ~queue( );

    bool pop(card &item);
    bool push(card item);
    bool front(card &item);
    int size( );
    bool empty( );
    void print(ostream &out);
    bool SameCheck(card item);//finds if card already exists in deck.



private:

    struct node
    {
        card theCard;
        node* next;
    };
    node *headptr;
    node *tailptr;    
};


int getCard(int seed);

void usageStatement();

int CmdCheck(int count, char* arg1);

void chooseRun(char* option, int s1, int s2, char* file1, char* file2, ifstream& fin);

void runSeed(int seed1, int seed2);

void runFile(char* file1, char* file2, ifstream& fin);

void fillDeckS(queue &deck, int seed);

void fillDeckF(ifstream& fin, queue &deck);
