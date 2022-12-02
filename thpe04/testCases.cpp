#include "thpe04.h"

TEST_CASE("queue - insert empty")
{
    queue que1;
    card card1;
    card1.faceValue = 12;
    card1.suit = 3;
    CHECK(que1.push(card1) == true);
}

TEST_CASE("queue - insert 1 item in")
{
    queue que1;
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
    queue que2;
    card badItem;
    bool check;
    check = que2.pop(badItem);
    CHECK(check == false);
}

TEST_CASE("pop - remove last in list")
{
    queue que3;
    card last, item;
    bool check;
    last.faceValue = 11;
    last.suit = 2;
    que3.push(last);
    check = que3.pop(item);
    CHECK(check == true);
    CHECK(que3.size() == 0);
}


TEST_CASE("Pop - remove all from list")
{
    queue que1;
    card card1, card2, card3, extra, extra2, extra3;
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
    queue que2;
    bool check;
    check = que2.front(item);
    CHECK(check == false);   
}

TEST_CASE("front - good list")
{
    card item, item2;
    queue que2;
    bool check;
    item.faceValue = 13;
    item.suit = 2;
    que2.push(item);
    que2.front(item2);
    CHECK(que2.size() == 1);
    CHECK(item2.faceValue == 13);
}