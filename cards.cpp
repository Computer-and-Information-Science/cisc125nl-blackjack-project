#include "cards.h" 
#include <cstdlib>
#include <algorithm>

Card::Card(int index) {
  // Create a playing card or placeholder
  if (index >= 0 && index <= 51) // if valid Card object
    card_index = index;
  else 
    card_index = 52; // placeholder
}

char Card::suit() const {
  static const char suits[] = { 'H', 'S', 'D', 'C' }; // valid suits
  if (card_index == 52)
    return 'X'; // placeholder
  return suits[card_index % 4];
}

char Card::value() const {
  static const char values[] = { // valid values
    '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
  if (card_index == 52)
    return 'X'; // placeholder
  return values[card_index / 4];
}

std::string Card::str() const {
  // Return concatenation of value and suit
  std::string s;
  s += value();
  s += suit();
  return s;
}

int Card::rank() const {
  // return a number from 2 to 14 (for Ace), or 0 for placeholder
  if (card_index == 52)
    return 0;
  return 2 + card_index / 4;
}

Deck::Deck() {
  // Initialize Card object to the distinct 52 cards
  for (int i = 0; i < 52; i++)
    cards[i] = Card(i);
  cards_dealt = 0;
}

Card Deck::deal() {
  // Deal (return) the next Card object
  if (cards_dealt == 52)
    return Card(); // placeholder of no cards remaining
  return cards[cards_dealt++];
}

void Deck::shuffle() {
  // Randomize the Card objects and reset to zero Card objects dealt
  for (int i = 0; i < 52; i++) {
    int j = rand() % 52;
    std::swap(cards[i], cards[j]);
  }
  cards_dealt = 0;
}
