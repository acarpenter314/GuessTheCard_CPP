#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Card {
public:
    std::string suit;
    std::string value;

    Card(const std::string& s, const std::string& v)
        : suit(s), value(v) {}
};

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck() {
        std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
        std::vector<std::string> values = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

        for (const auto& s : suits) {
            for (const auto& v : values) {
                cards.emplace_back(s, v);
            }
        }
    }

    Card drawRandomCard() const {
        int index = std::rand() % cards.size();
        return cards[index];
    }
};

void playGame() {
    Deck deck;
    Card hidden = deck.drawRandomCard();

    std::string guessSuit;
    std::string guessValue;

    std::cout << "\n=== Guess The Card (C++ Edition) ===\n";
    std::cout << "Choose difficulty:\n";
    std::cout << "  1. Guess Suit\n";
    std::cout << "  2. Guess Value\n";
    std::cout << "  3. Guess Both\n";
    std::cout << "Enter choice: ";

    int choice;
    std::cin >> choice;

    if (!std::cin) {
        std::cout << "Invalid input.\n";
        return;
    }

    if (choice == 1) {
        std::cout << "Guess the suit (Hearts, Diamonds, Clubs, Spades): ";
        std::cin >> guessSuit;

        if (guessSuit == hidden.suit)
            std::cout << "Correct! The card was " << hidden.value << " of " << hidden.suit << ".\n";
        else
            std::cout << "Wrong! The card was " << hidden.value << " of " << hidden.suit << ".\n";
    }
    else if (choice == 2) {
        std::cout << "Guess the value (Ace–10): ";
        std::cin >> guessValue;

        if (guessValue == hidden.value)
            std::cout << "Correct! The card was " << hidden.value << " of " << hidden.suit << ".\n";
        else
            std::cout << "Wrong! The card was " << hidden.value << " of " << hidden.suit << ".\n";
    }
    else if (choice == 3) {
        std::cout << "Guess the suit: ";
        std::cin >> guessSuit;
        std::cout << "Guess the value: ";
        std::cin >> guessValue;

        if (guessSuit == hidden.suit && guessValue == hidden.value)
            std::cout << "Perfect! You guessed both correctly!\n";
        else
            std::cout << "Wrong! The card was " << hidden.value << " of " << hidden.suit << ".\n";
    }
    else {
        std::cout << "Invalid choice.\n";
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    char again = 'y';
    while (again == 'y' || again == 'Y') {
        playGame();
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}