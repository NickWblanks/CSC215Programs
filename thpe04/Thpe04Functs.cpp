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

void chooseRun(char* option, int s1, int s2, char* file1, char* file2, ifstream &fin)
{
    if (strcmp(option, "-s") == 0)
    {
        runSeed(s1, s2);
    }
    if (strcmp(option, "-f") == 0)
    {
        runFile(file1, file2, fin);
    }
}

void runSeed(int seed1, int seed2)
{
    queue deck1;
    queue deck2;
    fillDeckS(deck1, seed1);
    fillDeckS(deck2, seed2);
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
    fillDeckF(fin, deck1);
    fillDeckF(fin, deck2);
}

void fillDeckS(queue &deck, int seed)
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
}

void fillDeckF(ifstream &fin, queue &deck)
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
}

int getCard(int seed)
{
    static default_random_engine engine(seed);
    uniform_int_distribution<int> deck(0, 51);
    return deck(engine);
}



void playRound(queue player1, queue player2)
{
    stack<card> p1Stack, p2Stack;
    card p1Card, p2Card, newCard1, newCard2;
    int i = 0;
    player1.pop(p1Card);
    player2.pop(p2Card);
    if (p1Card.faceValue > p2Card.faceValue)
    {
        player1.push(p2Card);
        player1.push(p1Card);
        return;
    }
    if (p2Card.faceValue > p1Card.faceValue)
    {
        player2.push(p1Card);
        player2.push(p2Card);
        return;
    }
    p1Stack.push(p1Card);
    p2Stack.push(p2Card);
    while (p1Card.faceValue == p2Card.faceValue)
    {
        while (i < 3)
        {
            player1.pop(p1Card);
            player2.pop(p2Card);
            p1Stack.push(p1Card);
            p2Stack.push(p2Card);
            i++;
        }
        player1.pop(p2Card);
        player2.pop(p1Card);
    }
    if (p1Card.faceValue > p2Card.faceValue)
    {
        while (p2Stack.empty() == false)
        {
            newCard2 = p2Stack.top();
            player1.push(newCard2);
            p2Stack.pop();
        }
        while (p1Stack.empty() == false)
        {
            newCard1 = p1Stack.top();
            player1.push(newCard1);
            p1Stack.pop();
        }
        return;
    }
    if (p2Card.faceValue > p1Card.faceValue)
    {
        while (p1Stack.empty() == false)
        {
            newCard1 = p1Stack.top();
            player1.push(newCard1);
            p1Stack.pop();
        }
        while (p2Stack.empty() == false)
        {
            newCard2 = p2Stack.top();
            player1.push(newCard2);
            p2Stack.pop();
        }
        return;
    }
}

void WAR(queue deck1, queue deck2)
{
    int i = 0;
    while (deck1.empty() == false || deck2.empty() == false)
    {
        playRound(deck1, deck2);
        i++;
    }
    if (deck1.empty() == true)
    {
        cout << "It Took: " << i << " Rounds for player 1 to win." << endl;
    }
    if (deck2.empty() == true)
    {
        cout << "It Took: " << i << " Rounds for player 2 to win." << endl;
    }
}
