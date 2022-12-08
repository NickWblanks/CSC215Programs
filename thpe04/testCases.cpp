#include "thpe04.h"

TEST_CASE("queue - insert empty")
{
    queue<card> que1;
    card card1;
    card1.faceValue = 12;
    card1.suit = 3;
    CHECK(que1.push(card1) == true);
}

TEST_CASE("queue - insert 1 item in")
{
    queue<card> que1;
    card card1, card2, card3;
    card1.faceValue = 12;
    card1.suit = 3;
    card2.faceValue = 9;
    card2.suit = 1;
    card3.faceValue = 1;
    card3.suit = 3;
    que1.push(card1);
    que1.push(card2);
    que1.push(card3);
    CHECK(que1.size() == 3);
}

TEST_CASE("pop - remove from empty list")
{
    queue<card> que2;
    card badItem;
    badItem.faceValue = 0;
    badItem.suit = 0;
    bool check;
    check = que2.pop(badItem);
    CHECK(check == false);
}

TEST_CASE("pop - remove last in list")
{
    queue<card> que3;
    card last, item;
    item.faceValue = 0;
    item.suit = 0;
    bool check;
    last.faceValue = 11;
    last.suit = 2;
    que3.push(last);
    check = que3.pop(item);
    CHECK(check == true);
    CHECK(que3.size() == 0);
    CHECK(item.faceValue == 11);
}


TEST_CASE("Pop - remove all from list")
{
    queue<card> que1;
    card card1, card2, card3, extra, extra2, extra3;
    extra.faceValue = 0;
    extra.suit = 0;
    extra3 = extra2 = extra;
    card1.faceValue = 12;
    card1.suit = 3;
    card2.faceValue = 9;
    card2.suit = 1;
    card3.faceValue = 1;
    card3.suit = 2;
    que1.push(card1);
    que1.push(card2);
    que1.push(card3);
    que1.pop(extra);
    que1.pop(extra2);
    que1.pop(extra3);
    CHECK(que1.size() == 0);
    CHECK(extra.faceValue == 12);
    CHECK(extra3.suit == 2);
}

TEST_CASE("front - empty list")
{
    card item;
    item.faceValue = 0;
    item.suit = 0;
    queue<card> que2;
    bool check;
    check = que2.front(item);
    CHECK(check == false);   
}

TEST_CASE("front - good list")
{
    card item, item2;
    item2.faceValue = 0;
    item2.suit = 0;
    queue<card> que2;
    item.faceValue = 12;
    item.suit = 2;
    que2.push(item);
    que2.front(item2);
    CHECK(que2.size() == 1);
    CHECK(item2.faceValue == 12);
}

TEST_CASE("print - cout it")
{
    card item, item2, item3;
    queue<card> que1;
    item.faceValue = 11;
    item.suit = 1;
    item2.faceValue = 4;
    item2.suit = 0;
    item3.faceValue = 3;
    item3.suit = 1;
    que1.push(item);
    que1.push(item2);
    que1.push(item3);
    que1.print(cout);
    CHECK(que1.size() == 3);
}

TEST_CASE("sameCheck - not in queue")
{
    card item1, item2, testItem;
    queue<card> que1;
    bool check;
    item1.faceValue = 7;
    item1.suit = 3;
    item2.faceValue = 6;
    item2.suit = 2;
    testItem.faceValue = 13;
    testItem.suit = 1;
    que1.push(item1);
    que1.push(item2);
    check = que1.SameCheck(testItem);
    if (check == false)
    {
        que1.push(testItem);
    }
    CHECK(que1.size() == 3);
}

TEST_CASE("fillDeckS - checking to see if it fills up to 52")
{
    queue<card> deck1;
    int seed = 94850;
    bool check;
    int qSize;
    fillDeckS(deck1, seed);
    check = deck1.empty();
    qSize = deck1.size();
    CHECK(qSize == 52);
    CHECK(check == false);
}

TEST_CASE("FillDeckF - running file1")
{
    int qSize;
    queue<card> deck;
    ifstream fin;
    string fileName;
    fileName = "Deck1.cards";
    fin.open(fileName);
    if (!fin.is_open())
    {
        cout << "Unable to open File." << endl;
    }
    fillDeckF(fin, deck);
    qSize = deck.size();
    CHECK(qSize == 52);
    CHECK(deck.empty() == false);
}

TEST_CASE("playRound - p2 wins after 2 rounds")
{
    int i;
    queue<card> deck1, deck2;
    card card1;
    int p1[2] = { 4, 8 };
    int p2[2] = { 2, 7 };
    for (i = 0; i < 2; i++)
    {
        card1.faceValue = p1[i];
        card1.suit = 0;
        deck1.push(card1);
    }
    for (i = 0; i < 2; i++)
    {
        card1.faceValue = p2[i];
        card1.suit = 0;
        deck2.push(card1);
    }
    playRound(deck1, deck2);
    CHECK(deck2.size() == 1);
    CHECK(deck1.size() == 3);
}

TEST_CASE("playRound - tied first, pull 2 more, p2 wins")
{
    int i;
    queue<card> deck1, deck2;
    card card1;
    int p1[10] = { 4, 8, 6, 5 ,11, 2, 7, 1, 0, 3};
    int p2[10] = { 4, 9, 8, 8, 2, 1, 11, 12, 4, 5 };
    for (i = 0; i < 10; i++)
    {
        card1.faceValue = p1[i];
        card1.suit = 0;
        deck1.push(card1);
    }
    for (i = 0; i < 10; i++)
    {
        card1.faceValue = p2[i];
        card1.suit = 0;
        deck2.push(card1);
    }
    playRound(deck1, deck2);
    deck1.print(cout);
    deck2.print(cout);
    CHECK(deck2.size() == 14);
    CHECK(deck1.size() == 6);
}

TEST_CASE("playRound - tied first, not enough cards, p2 wins")
{
    int i;
    queue<card> deck1, deck2;
    card card1;
    int p1[10] = { 4, 8, 6 };
    int p2[10] = { 4, 9, 8 };
    for (i = 0; i < 3; i++)
    {
        card1.faceValue = p1[i];
        card1.suit = 0;
        deck1.push(card1);
    }
    for (i = 0; i < 3; i++)
    {
        card1.faceValue = p2[i];
        card1.suit = 0;
        deck2.push(card1);
    }
    playRound(deck1, deck2);
    deck1.print(cout);
    deck2.print(cout);
    CHECK(deck2.size() == 6);
    CHECK(deck1.size() == 0);
}

TEST_CASE("playRound - tied first, p1 not enough cards, p2 wins")
{
    int i;
    queue<card> deck1, deck2;
    card card1;
    int p1[10] = { 4, 8, 6 };
    int p2[10] = { 4, 9, 8, 10, 11, 2, 1 };
    for (i = 0; i < 3; i++)
    {
        card1.faceValue = p1[i];
        card1.suit = 0;
        deck1.push(card1);
    }
    for (i = 0; i < 7; i++)
    {
        card1.faceValue = p2[i];
        card1.suit = 0;
        deck2.push(card1);
    }
    playRound(deck1, deck2);
    deck1.print(cout);
    deck2.print(cout);
    CHECK(deck2.size() == 10);
    CHECK(deck1.size() == 0);
}

