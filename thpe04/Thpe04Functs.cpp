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
    card deck1[110];
    card deck2[110];
    bool check1, check2;
    check1 = fillDeck(deck1, seed1, 110);
    if (check1 == false)
    {
        return;
    }
    check2 = fillDeck(deck2, seed2, 110);
    if (check2 == false)
    {
        return;
    }
}

void runFile(char *file1, char *file2)
{

}

bool fillDeck(card deck[], int seed, int size)
{
    int i, j, indCard;
    int suit, value;
    card temp, oldCard;
    for (i = 0; i < size; i++)
    {
        indCard = getCard(seed);
        suit = indCard / 13;
        value = indCard % 13;
        temp.faceValue = value;
        temp.suit = suit;
        for (j = 0; j < 52; j++)
        {
            oldCard = deck[j];
            if (temp.faceValue == oldCard.faceValue && temp.suit == oldCard.suit)
            {
                indCard = getCard(seed);
                suit = indCard / 13;
                value = indCard % 13;
                temp.faceValue = value;
                temp.suit = suit;
                j = -1;
            }
        }
        deck[i] = temp;
    }
    return true;
}

int getCard(int seed)
{
    static default_random_engine engine(seed);
    uniform_int_distribution<int> deck(0, 51);
    return deck(engine);
}

void WAR(card deck1[], card deck2[])
{

}


//void playRound(Queue<card> &player1, Queue<card> &player2)
//{
//
//}