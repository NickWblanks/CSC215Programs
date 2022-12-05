#include "thpe04.h"

int CmdCheck(int count, char* arg1)
{ //returns 0 if it fails anywhere, 1 if it passes through
    if (count != 4)
    {
        return 0;
    }
    if (strcmp(arg1, "-s") != 0 && strcmp(arg1, "-f") != 0)
    {
        return 0;
    }
    return 1;
}

void chooseRun(char* option, int s1, int s2, char* file1, char* file2)
{
    if (strcmp(option, "-s") == 0)
    {
        runSeed(s1, s2);
    }
    if (strcmp(option, "-f") == 0)
    {
        runFile(file1, file2);
    }
}

void runSeed(int seed1, int seed2)
{
    queue deck1;
    queue deck2;
    bool check1, check2;
    check1 = fillDeckS(deck1, seed1);
    if (check1 == false)
    {
        return;
    }
    check2 = fillDeckS(deck2, seed2);
    if (check2 == false)
    {
        return;
    }
}

void runFile(char *file1, char *file2, ifstream &fin)
{
    fin.open(file1);
    if (!fin.is_open())
    {
        cout << "Unable to open file." << endl;
        return;
    }
    fin.open(file2);
    if (!fin.is_open())
    {
        cout << "Unable to open file." << endl;
        return;
    }
    queue deck1, deck2;
    bool check1, check2;
    check1 = fillDeckF(fin, deck1);
    if (check1 == false)
    {
        return;
    }
    check2 = fillDeckF(fin, deck2);
    if (check2 == false)
    {
        return;
    }

}

bool fillDeckS(queue deck, int seed)
{
    int i, indCard;
    i = 0;
    int suit, value;
    card newCard;
    indCard = getCard(seed);
    suit = indCard / 13;
    value = indCard % 13;
    newCard.faceValue = value;
    newCard.suit = suit;
    deck.push(newCard);
    while (i < 52)
    {
        indCard = getCard(seed);
        suit = indCard / 13;
        value = indCard % 13;
        newCard.faceValue = value;
        newCard.suit = suit;
        while(deck.SameCheck(newCard) == true)
        {
            indCard = getCard(seed);
            suit = indCard / 13;
            value = indCard % 13;
            newCard.faceValue = value;
            newCard.suit = suit;
        }
        deck.push(newCard);
        i++;
    }
    deck.print(cout);
    return true;
}

bool fillDeckF(ifstream &fin, queue deck)
{
    card cardIn;
    int card, suit, value;
    while (fin >> card)
    {
        suit = card / 13;
        value = card % 13;
        cardIn.suit = suit;
        cardIn.faceValue = value;
        deck.push(cardIn);
    }
    deck.print(cout);
}

int getCard(int seed)
{
    static default_random_engine engine(seed);
    uniform_int_distribution<int> deck(0, 51);
    return deck(engine);
}

void WAR(queue deck1, queue deck2)
{

}


//void playRound(Queue<card> &player1, Queue<card> &player2)
//{
//
//}