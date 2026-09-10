#include <iostream>
#include <string>
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

    Card(const std::string& s, const std::string& v)
        : suit(s), value(v) {}
};

// ------------------------------------------------------------
// Deck Class
// Builds a simple 40‑card deck (Ace–10 in four suits).
// Provides a method to draw a random card.
// ------------------------------------------------------------
class Deck {
private:
    std::vector<Card> cards;

public:
    Deck() {
        std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
        std::vector<std::string> values = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

        // Build the deck by combining suits and values
        for (const auto& s : suits) {
            for (const auto& v : values) {
                cards.emplace_back(s, v);
            }
        }
    }

    // Draws a random card from the deck
    Card drawRandomCard() const {
        int index = std::rand() % cards.size();
        return cards[index];
    }
};

// ------------------------------------------------------------
// playGame()
// Handles the main gameplay loop:
// - Difficulty selection
// - User guessing
// - Win/loss output
// ------------------------------------------------------------
void playGame() {
    Deck deck;
    Card hidden = deck.drawRandomCard();

    std::string guessSuit;
    std::string guessValue;

    std::cout << "\n=== Guess The Card (C++ Edition) ===\n";
    std::cout << "Choose difficulty:\n";
