//
// Created by Sawyer on 3/22/2021.
//

#include "Game.h"

#include <iostream>

int main() {
    std::string player1;
    std::string player2;
    char response;
    bool isAiGame;

    do {
        std::cout << "Enter the name of player 1 (no spaces): " << std::endl;
        std::cin >> player1;

        std::cout << "Enter the name of player 2 (no spaces): " << std::endl;
        std::cin >> player2;

        if (player1 == player2) {
            std::cout << "Names cannot be equal. Please enter two different names." << std::endl;
        }

    } while (player1 == player2);

    std::cout << "Do you want to play against an Ai? (y/n): " << std::endl;
    std::cin >> response;

    isAiGame = (response == 'y');

    Game connectFourGame(player1, player2, isAiGame);

    connectFourGame.mainloop();
}

