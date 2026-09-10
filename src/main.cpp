#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// ------------------------------------------------------------
// Card Class
// Represents a single playing card with a suit and value.
// ------------------------------------------------------------
class Card {
public:
    std::string suit;
    std::string value;

    // Constructor to create a card with a suit and value
    Card(std::string s, std::string v) : suit(s), value(v) {}
};

// ------------------------------------------------------------
// Deck Class
// Holds a full deck of 52 cards and can return a random card.
// ------------------------------------------------------------
class Deck {
private:
    std::vector<Card> cards;  // Dynamic list of all cards

public:
    // Constructor builds the full deck automatically
    Deck() {
        std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
