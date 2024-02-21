// cards.h - A library for representing playing cards.

#pragma once

#include <string> 

// Card - Represents a playing card from a deck of cards. A card, once created,
// has properties of a value and a suit (accessor methods). The value and suit
// cannot be changed once a Card object is created, however a Card object may
// be change via assignment from another Card object. A Card object may be
// created as a "placehold", an invalid card, to support creation of a Card
// object variable that has yet to have a valid card assigned to it.
class Card {
private:
  int card_index; // 0-51 to represent a card, or 52 for a placeholder
public:
  Card() { card_index = 52; }
  Card(int index);

  char suit() const; // 'H', 'S', 'D', 'C', or 'X' if a placeholder
  char value() const; // '2' .. '9', 'T', 'J', 'Q', 'K', 'A', or 'X'

  std::string str() const; // A string such as "7D"
  int rank() const; // Number for common card ordering
};

// Deck - Represents a deck of playing cards. A Deck object may be "shuffled",
// after which the Deck object represents the full complement of 52 cards with
// the ordering of Card objects randomized. May also "deal" from the Deck
// which returns the next Card object from the deck, reducing the number of
// Card objects in the deck by one.
class Deck {
private:
  Card cards[52]; // The 52 distinct Card objects, randomized
  int cards_dealt; // Number of Card objects dealt from the Deck
public: 
  Deck();

  Card deal();
  void shuffle();

  int size() const { return 52 - cards_dealt; }
};
