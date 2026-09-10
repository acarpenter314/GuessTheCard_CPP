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
        std::vector<std::string> suits = { "Hearts", "Diamonds", "Clubs", "Spades" };
        std::vector<std::string> values = {
            "Ace", "2", "3", "4", "5", "6", "7",
            "8", "9", "10", "Jack", "Queen", "King"
        };

        // Create all 52 cards
        for (auto& s : suits) {
            for (auto& v : values) {
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

void gamePlay(Deck& deck) {
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
        std::cout << "Choose the suit:\n";
        std::cout << "1. Hearts\n";
        std::cout << "2. Diamonds\n";
        std::cout << "3. Clubs\n";
        std::cout << "4. Spades\n";
        std::cout << "Enter choice: ";

        int suitChoice;
        std::cin >> suitChoice;

        std::string guessSuit;

        switch (suitChoice) {
        case 1: guessSuit = "Hearts"; break;
        case 2: guessSuit = "Diamonds"; break;
        case 3: guessSuit = "Clubs"; break;
        case 4: guessSuit = "Spades"; break;
        default:
            std::cout << "Invalid choice.\n";
            return; // or handle error
        }

        if (guessSuit == card.suit) {
            std::cout << "Correct! The card was " << card.value << " of " << card.suit << ".\n";
        }
        else {
            std::cout << "Wrong! The card was " << card.value << " of " << card.suit << ".\n";
        }

    }
    // ------------------------------------------------------------
    // Difficulty Option 2: Guess only the value
    // ------------------------------------------------------------
    else if (choice == 2) {
        std::cout << "Choose the value:\n";
        std::cout << "1. Ace\n";
        std::cout << "2. 2\n";
        std::cout << "3. 3\n";
        std::cout << "4. 4\n";
        std::cout << "5. 5\n";
        std::cout << "6. 6\n";
        std::cout << "7. 7\n";
        std::cout << "8. 8\n";
        std::cout << "9. 9\n";
        std::cout << "10. 10\n";
        std::cout << "11. Jack\n";
        std::cout << "12. Queen\n";
        std::cout << "13. King\n";
        std::cout << "Enter choice: ";

        int valueChoice;
        std::cin >> valueChoice;

        std::string guessValue;

        switch (valueChoice) {
        case 1: guessValue = "Ace"; break;
        case 2: guessValue = "2"; break;
        case 3: guessValue = "3"; break;
        case 4: guessValue = "4"; break;
        case 5: guessValue = "5"; break;
        case 6: guessValue = "6"; break;
        case 7: guessValue = "7"; break;
        case 8: guessValue = "8"; break;
        case 9: guessValue = "9"; break;
        case 10: guessValue = "10"; break;
        case 11: guessValue = "Jack"; break;
        case 12: guessValue = "Queen"; break;
        case 13: guessValue = "King"; break;
        default:
            std::cout << "Invalid choice.\n";
            return;
        }

        if (guessValue == card.value) {
            std::cout << "Correct! The card was " << card.value << " of " << card.suit << ".\n";
        }
        else {
            std::cout << "Wrong! The card was " << card.value << " of " << card.suit << ".\n";
        }
    }

    // ------------------------------------------------------------
    // Difficulty Option 3: Guess both suit and value
    // ------------------------------------------------------------
    else if (choice == 3) {
        // -------------------------
        // Suit selection
        // -------------------------
        std::cout << "Choose the suit:\n";
        std::cout << "1. Hearts\n";
        std::cout << "2. Diamonds\n";
        std::cout << "3. Clubs\n";
        std::cout << "4. Spades\n";
        std::cout << "Enter choice: ";

        int suitChoice;
        std::cin >> suitChoice;

        std::string guessSuit;

        switch (suitChoice) {
        case 1: guessSuit = "Hearts"; break;
        case 2: guessSuit = "Diamonds"; break;
        case 3: guessSuit = "Clubs"; break;
        case 4: guessSuit = "Spades"; break;
        default:
            std::cout << "Invalid suit choice.\n";
            return;
        }

        // -------------------------
        // Value selection
        // -------------------------
        std::cout << "Choose the value:\n";
        std::cout << "1. Ace\n";
        std::cout << "2. 2\n";
        std::cout << "3. 3\n";
        std::cout << "4. 4\n";
        std::cout << "5. 5\n";
        std::cout << "6. 6\n";
        std::cout << "7. 7\n";
        std::cout << "8. 8\n";
        std::cout << "9. 9\n";
        std::cout << "10. 10\n";
        std::cout << "11. Jack\n";
        std::cout << "12. Queen\n";
        std::cout << "13. King\n";
        std::cout << "Enter choice: ";

        int valueChoice;
        std::cin >> valueChoice;

        std::string guessValue;

        switch (valueChoice) {
        case 1: guessValue = "Ace"; break;
        case 2: guessValue = "2"; break;
        case 3: guessValue = "3"; break;
        case 4: guessValue = "4"; break;
        case 5: guessValue = "5"; break;
        case 6: guessValue = "6"; break;
        case 7: guessValue = "7"; break;
        case 8: guessValue = "8"; break;
        case 9: guessValue = "9"; break;
        case 10: guessValue = "10"; break;
        case 11: guessValue = "Jack"; break;
        case 12: guessValue = "Queen"; break;
        case 13: guessValue = "King"; break;
        default:
            std::cout << "Invalid value choice.\n";
            return;
        }

        // -------------------------
        // Compare both
        // -------------------------
        if (guessSuit == card.suit && guessValue == card.value) {
            std::cout << "Perfect! You guessed both correctly!\n";
        }
        else {
            std::cout << "Wrong! The card was " << card.value << " of " << card.suit << ".\n";
        }
    }

    // ------------------------------------------------------------
    // Invalid menu choice
    // ------------------------------------------------------------
    else {
        std::cout << "Invalid choice.\n";
    }
}
bool gameReplay() {
    // ------------------------------------------------------------
    // Replay Prompt
    // ------------------------------------------------------------
    char again;

    while (true) {
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;

        if (again == 'y' || again == 'Y') {
            return true;
        }
        else if (again == 'n' || again == 'N') {
            return false;
        }
        else {
            std::cout << "Invalid input. Please type Y or N.\n";
        }
    }
}

// ------------------------------------------------------------
// Main Game Loop
// Handles menu, guessing logic, and replay option.
// ------------------------------------------------------------
int main() {
    srand(time(nullptr));  // Seed random generator
    Deck deck;             // Create a deck of cards

    bool playAgain = true; // Controls replay loop

    while (playAgain) {
        gamePlay(deck);
        playAgain = gameReplay();

        if (playAgain) {
            system("cls"); // Windows clear screen
        }
    }

    std::cout << "\nThanks for playing!\n";
    return 0;
}
