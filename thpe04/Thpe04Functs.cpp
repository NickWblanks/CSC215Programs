/** **********************************************************************
 * @file
 ************************************************************************/


#include "thpe04.h"

 /** **********************************************************************
  *  @author Nicholas K Wilk
  *
  *  @par Description
  *
  *  This function takes no arguments. It will produce an error message to
  *  the screen when it is called.
  *
  *
  *  @par Example
  *  @verbatim

     if(count != 4)
     {
         usageStatement();
     }

     @endverbatim
  ************************************************************************/

void usageStatement()
{
    cout << "Invalid Startup" << endl;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the count of expected
 *  arguments. The second is the option specified by the user at runtime.
 *  If the count is not 4, or if the user did not specify -s or -f, the function
 *  will return a 0 and drop out.
 *
 *  @param[in] count The number of expected arguments, should be 4.
 *
 *  @param[in] arg1 The option of how to run the program, should be -s or -f.
 *
 *  @returns An integer value, 0 if the count or option were incorrect
 *  1 if it all passed.
 *
 *  @par Example
 *  @verbatim

    int count = 4;
    int ans;
    char *option = "-s";
    ans = CmdCheck(count, option);
    return ans;

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is the input file
 *  stream containing the file to open. The second is the file name.
 *
 *  @param[in] option The option specified by the user. This will determine
 *  how the program will run.
 *
 *  @param[in] s1 If -s is provided as an option, this value will be called
 *  to run the program.
 * 
 *  @param[in] s2 If -s is provided as the option, this value will be 
 *  called to run the program.
 *  
 *  @param[in] file1 If -f is provided, this is the first file to open
 *  and run the program with.
 * 
 *  @param[in] file2 If -f is provided, this is the second file to open
 *  and run the program with.
 * 
 *  @param[in] fin An ifstream variable to open the input files file1 and file2.
 *
 *  @returns A boolean value, true or false. True if the
 *  file opened properly, false otherwise.
 *
 *  @par Example
 *  @verbatim

    ifstream fin;
    char * option = "-s"
    int s1 = 90;
    int s2 = 102;
    chooseRun(option, s1, s2, file1, file2, fin)
    //will run the program using the seeds.

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. Both are seeds to generate decks of cards from.
 *  After both decks have been generated, it will play war.
 *
 *  @param[in] seed1 An integer representing the first seed to generate
 *  a deck from.
 *
 *  @param[in] seed2 An integer representing the first seed to generate
 *  a deck from.
 *
 *  @par Example
 *  @verbatim

    seed1 = 9573;
    seed2 = 5803;
    runSeed(seed1, seed2);
    //will generate two decks of card from these 2 seeds.
    and then play the game of war.

    @endverbatim
 ************************************************************************/

void runSeed(int seed1, int seed2)
{
    queue<card> deck1;
    queue<card> deck2;
    fillDeckS(deck1, seed1);
    fillDeckS(deck2, seed2);
    WAR(deck1, deck2);
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. Both are file names to generate decks of cards from.
 *  After both decks have been generated, it will play war.
 *
 *  @param[in] file1 A file name representing the first file to generate
 *  a deck from.
 *
 *  @param[in] file2 A file name representing the first file to generate
 *  a deck from.
 * 
 *  @param[in] fin An ifstream variable used to open input files.
 *
 *  @par Example
 *  @verbatim
    
    ifstream fin;
    file1 = player1.deck;
    file2 = player2.deck;
    runfile(file1, file2, fin);
    //will generate two decks of card from these 2 files.
    and then play the game of war.

    @endverbatim
 ************************************************************************/

void runFile(char *file1, char *file2, ifstream &fin)
{
    queue<card> deck1, deck2;
    fin.open(file1);
    if (!fin.is_open())
    {
        cout << "Unable to open file." << endl;
        return;
    }
    fillDeckF(fin, deck1);
    fin.close();
    fin.open(file2);
    if (!fin.is_open())
    {
        cout << "Unable to open file." << endl;
        return;
    }
    fillDeckF(fin, deck2);
    WAR(deck1, deck2);
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is a deck to fill, and the second
 *  is a seed to generate cards from. This will fill a deck of 52 cards
 *  with no duplicates.
 *
 *  @param[in] deck The players deck to fill with random cards.
 *
 *  @param[in] seed An integer representing the seed to generate cards from.
 *
 *  @par Example
 *  @verbatim

    queue<card> deck;
    int seed = 95739;
    fillDeckS(deck, seed);
    //will fill a linked list based queue with 52 cards from a seed

    @endverbatim
 ************************************************************************/

template <class ty>
void fillDeckS(queue<ty> &deck, int seed)
{
    int i, indCard, qSize;
    i = 0;
    int suit, value;
    card newCard;
    indCard = getCard(seed);
    suit = indCard / 13;
    value = indCard % 13;
    newCard.faceValue = value;
    newCard.suit = suit;
    deck.push(newCard);
    while (i < 51)
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
        qSize = deck.size();
    }

}

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is an ifstream variable
 *  holding the file to pull the data from, the second is the deck to fill.
 *  This function does no error checking and simply pulls data until EOF.
 *  Then stores that data into the deck.
 *
 *  @param[in] fin The ifstream variable used for input.
 *
 *  @param[in] deck The players deck to fill cards with from the file.
 *
 *  @par Example
 *  @verbatim

    ifstream fin;
    queue<card> deck;
    fillDeckF(fin, deck);
    //will fill a linked list based queue with cards from a file.

    @endverbatim
 ************************************************************************/

template <class ty>
void fillDeckF(ifstream &fin, queue<ty> &deck)
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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 1 argument. It is a seed to generate a card.
 *  This function does only this and has no error checking.
 *
 *  @param[in] seed The seed used by a random number generator to generate
 *  a single card.
 * 
 *  @returns An integer that is the card it pulled.
 *
 *
 *  @par Example
 *  @verbatim

    int seed = 95749;
    int card;
    card = getCard(seed);
    //generates a random card between 0-51.

    @endverbatim
 ************************************************************************/

int getCard(int seed)
{
    static default_random_engine engine(seed);
    uniform_int_distribution<int> deck(0, 51);
    return deck(engine);
}



/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. Both are the decks of the two players.
 *  The function will play a SINGLE round of war in which both players
 *  will play a single card from their deck and compare them to each other.
 *  In the case of a tie, both will then pull 2 more face down, and compare the
 *  third card.
 *
 *  @param[in] &player1 The first players deck.
 *
 *  @param[in] &player2 The second players deck.
 *
 *  @par Example
 *  @verbatim

    queue<card> player1, player2;
    playRound(player1, player2)
    //both decks must have values in them.
    //will play a SINGLE round of war.

    @endverbatim
 ************************************************************************/

template <class ty>
void playRound(queue<ty>& player1, queue<ty>& player2)
{
    stack<card> p1Stack, p2Stack;
    card p1Card, p2Card, newCard1, newCard2, testC1, testC2;
    p1Card.faceValue = 0;
    p1Card.suit = 0;
    card finalCard, finalCard2;
    finalCard2 = finalCard = newCard2 = newCard1 = p2Card = p1Card;
    int i = 0;
    int q1 = player1.size();
    int q2 = player2.size();
    player1.pop(p1Card);
    player2.pop(p2Card);
    p1Stack.push(p1Card);
    p2Stack.push(p2Card);
    testC1 = p1Stack.top();
    testC2 = p2Stack.top();
    if (testC1.faceValue > testC2.faceValue)
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
    if (testC2.faceValue > testC1.faceValue)
    {
        while (p1Stack.empty() == false)
        {
            newCard1 = p1Stack.top();
            player2.push(newCard1);
            p1Stack.pop();
        }
        while (p2Stack.empty() == false)
        {
            newCard2 = p2Stack.top();
            player2.push(newCard2);
            p2Stack.pop();
        }
        return;
    }
    while(testC1.faceValue == testC2.faceValue)
    {
        q1 = player1.size();
        q2 = player2.size();
        while (i < 2 && q1 > 1 && q2 > 1)
        {
            player1.pop(newCard1);
            p1Stack.push(newCard1);
            player2.pop(newCard2);
            p2Stack.push(newCard2);
            q1 = player1.size();
            q2 = player2.size();
            i++;
        }
        player1.pop(finalCard);
        player2.pop(finalCard2);
        p1Stack.push(finalCard);
        p2Stack.push(finalCard2);
        testC1 = p1Stack.top();
        testC2 = p2Stack.top();
        i = 0;
    }
    if (testC1.faceValue > testC2.faceValue)
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
    if (testC2.faceValue > testC1.faceValue)
    {
        while (p1Stack.empty() == false)
        {
            newCard1 = p1Stack.top();
            player2.push(newCard1);
            p1Stack.pop();
        }
        while (p2Stack.empty() == false)
        {
            newCard2 = p2Stack.top();
            player2.push(newCard2);
            p2Stack.pop();
        }
        return;
    }
}

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. Both are the decks of the players. This
 *  function will repeatedly call the playRound function until one of
 *  the players is out of cards. It will then output how many rounds
 *  was required as well as who won, and what the order of their deck was.
 *
 *  @param[in] deck1 The first player.
 *
 *  @param[in] deck2 The second player.
 *
 *  @par Example
 *  @verbatim

    queue<card> player1, player2;
    WAR(player1, player2);
    //will play an entire game of war until one player loses, I.E. is out of cards.

    @endverbatim
 ************************************************************************/

template <class ty>
void WAR(queue<ty> &deck1, queue<ty> &deck2)
{
    queue<card2> DeckN;
    int i = 0;
    while (deck1.size() != 0 && deck2.size() != 0)
    {
        playRound(deck1, deck2);
        i++;
    }
    if (deck1.empty() == true)
    {
        cout << "It Took: " << i << " Rounds for player 2 to win." << endl;
        cout << "Player 2's deck is: " << endl;
        convertDeck(deck1, DeckN);
        cout << "Face Value" << " -- " << "Suit" << endl;
        cout << DeckN << endl;
        cout << DeckN.size() << endl;
    }
    if (deck2.empty() == true)
    {
        cout << "It Took: " << i << " Rounds for player 1 to win." << endl;
        cout << "Player 1's deck is: " << endl;
        convertDeck(deck1, DeckN );
        cout << "Face Value" << " -- " << "Suit" << endl;
        cout << DeckN << endl;
        cout << DeckN.size() << endl;
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *
 *  This function takes 2 arguments. The first is a deck of cards that holds
 *  the face value and suit in the form of integers. Both are offset by 1
 *  I.E. 0 = ace, 1 = deuce. The second argument is a deck that will
 *  hold the same info, but will adjust it so it matches what it should be
 *  as well as rewriting it in string format for readability. The first 
 *  deck is preserved upon conversion.
 *
 *  @param[in] deck1 The original deck, holds data in the form of integers.
 *
 *  @param[in] deck2 The deck that now holds the data from deck1 but in an
 *  easier to read format.
 *
 *  @par Example
 *  @verbatim

    queue<card> deck;
    queue<card2> deck2;
    convertDeck(deck1, deck2);
    //Will convert a deck from integers to strings for readability.
    //card2 is a structure that stores the same data but in string format.
    @endverbatim
 ************************************************************************/

void convertDeck(queue<card>& deck1, queue<card2>& deck2)
{
    card card1;
    card2 cardN;
    int value, suitI;
    string faceVal;
    string suitS;
    while (deck1.empty() == false)
    {
        deck1.pop(card1);
        value = card1.faceValue;
        suitI = card1.suit;
        if (value == 0)
        {
            faceVal = "ACE";
        }
        if (value == 1)
        {
            faceVal = "TWO";
        }
        if (value == 2)
        {
            faceVal = "THREE";
        }
        if (value == 3)
        {
            faceVal = "FOUR";
        }
        if (value == 4)
        {
            faceVal = "FIVE";
        }
        if (value == 5)
        {
            faceVal = "SIX";
        }
        if (value == 6)
        {
            faceVal = "SEVEN";
        }
        if (value == 7)
        {
            faceVal = "EIGHT";
        }
        if (value == 8)
        {
            faceVal = "NINE";
        }
        if (value == 9)
        {
            faceVal = "TEN";
        }
        if (value == 10)
        {
            faceVal = "JACK";
        }
        if (value == 11)
        {
            faceVal = "QUEEN";
        }
        if (value == 12)
        {
            faceVal = "KING";
        }
        if (suitI == 0)
        {
            suitS = "HEARTS";
        }
        if (suitI == 1)
        {
            suitS = "Diamonds";
        }
        if (suitI == 2)
        {
            suitS = "Clubs";
        }
        if (suitI == 3)
        {
            suitS = "Spades";
        }
        cardN.face = faceVal;
        cardN.suit = suitS;
        deck2.push(cardN);
        deck1.push(card1);
    }
}
