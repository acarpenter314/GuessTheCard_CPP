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
        std::vector<std::string> values = {
            "Ace", "2", "3", "4", "5", "6", "7",
            "8", "9", "10", "Jack", "Queen", "King"
        };

        // Create all 52 cards
        for (auto &s : suits) {
            for (auto &v : values) {
                cards.emplace_back(s, v);
            }
        }
    }

    // Returns a random card from the deck
    Card getRandomCard() {
        int index = rand() % cards.size();
        return cards[index];
    }
};

// ------------------------------------------------------------
// Main Game Loop
// Handles menu, guessing logic, and replay option.
// ------------------------------------------------------------
int main() {
    srand(time(nullptr));  // Seed random generator
    Deck deck;             // Create a deck of cards

    bool playAgain = true; // Controls replay loop

    while (playAgain) {
        // Display game menu
        std::cout << "\n=== Guess The Card (C++ Edition) ===\n";
        std::cout << "Choose difficulty:\n";
        std::cout << "1. Guess Suit\n";
        std::cout << "2. Guess Value\n";
        std::cout << "3. Guess Both\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;

        // Pull a random card from the deck
        Card card = deck.getRandomCard();

        std::string guessSuit, guessValue;

        // ------------------------------------------------------------
        // Difficulty Option 1: Guess only the suit
        // ------------------------------------------------------------
        if (choice == 1) {
            std::cout << "Guess the suit (Hearts, Diamonds, Clubs, Spades): ";
            std::cin >> guessSuit;

            if (guessSuit == card.suit) {
                std::cout << "Correct! The card was " << card.value << " of " << card.suit << ".\n";
            } else {
                std::cout << "Wrong! The card was " << card.value << " of " << card.suit << ".\n";
            }

        }
        // ------------------------------------------------------------
        // Difficulty Option 2: Guess only the value
        // ------------------------------------------------------------
        else if (choice == 2) {
            std::cout << "Guess the value (Ace, 2-10, Jack, Queen, King): ";
            std::cin >> guessValue;

            if (guessValue == card.value) {
                std::cout << "Correct! The card was " << card.value << " of " << card.suit << ".\n";
            } else {
                std::cout << "Wrong! The card was " << card.value << " of " << card.suit << ".\n";
            }

        }
        // ------------------------------------------------------------
        // Difficulty Option 3: Guess both suit and value
        // ------------------------------------------------------------
        else if (choice == 3) {
            std::cout << "Guess the suit: ";
            std::cin >> guessSuit;
            std::cout << "Guess the value: ";
            std::cin >> guessValue;

            if (guessSuit == card.suit && guessValue == card.value) {
                std::cout << "Perfect! You guessed both correctly!\n";
            } else {
                std::cout << "Wrong! The card was " << card.value << " of " << card.suit << ".\n";
            }

        }
        // ------------------------------------------------------------
        // Invalid menu choice
        // ------------------------------------------------------------
        else {
            std::cout << "Invalid choice.\n";
        }

        // ------------------------------------------------------------
        // Replay Prompt
        // ------------------------------------------------------------
        char again;
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;

        if (again != 'y' && again != 'Y') {
            playAgain = false;
        }
    }

    std::cout << "\nThanks for playing!\n";
    return 0;
}
