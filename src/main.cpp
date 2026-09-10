srand(time(nullptr));
    Deck deck;

    bool playAgain = true;

    while (playAgain) {
        std::cout << "\n=== Guess The Card (C++ Edition) ===\n";
        std::cout << "Choose difficulty:\n";
        std::cout << "1. Guess Suit\n";
        std::cout << "2. Guess Value\n";
        std::cout << "3. Guess Both\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;

        Card card = deck.getRandomCard();

        std::string guessSuit, guessValue;

        if (choice == 1) {
            std::cout << "Guess the suit (Hearts, Diamonds, Clubs, Spades): ";
            std::cin >> guessSuit;

            if (guessSuit == card.suit) {
                std::cout << "Correct! The card was " << card.value << " of " << card.suit << ".\n";
            } else {
                std::cout << "Wrong! The card was " << card.value << " of " << card.suit << ".\n";
            }

        } else if (choice == 2) {
            std::cout << "Guess the value (Ace, 2-10, Jack, Queen, King): ";
            std::cin >> guessValue;

            if (guessValue == card.value) {
                std::cout << "Correct! The card was " << card.value << " of " << card.suit << ".\n";
            } else {
                std::cout << "Wrong! The card was " << card.value << " of " << card.suit << ".\n";
            }

        } else if (choice == 3) {
            std::cout << "Guess the suit: ";
            std::cin >> guessSuit;
            std::cout << "Guess the value: ";
            std::cin >> guessValue;

            if (guessSuit == card.suit && guessValue == card.value) {
                std::cout << "Perfect! You guessed both correctly!\n";
            } else {
                std::cout << "Wrong! The card was " << card.value << " of " << card.suit << ".\n";
            }

        } else {
            std::cout << "Invalid choice.\n";
        }

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