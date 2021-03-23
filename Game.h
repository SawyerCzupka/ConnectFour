//
// Created by Sawyer on 3/22/2021.
//

#ifndef CONNECTFOUR_GAME_H
#define CONNECTFOUR_GAME_H

#include "Player.h"
#include "Board.h"

class Game {
public:
    // Constructor
    Game(const std::string& one, const std::string& two, bool isAiGame = false);

    // Methods
    void test();
    [[ noreturn ]] void mainloop();

private:
    // Instance Variables
    Player* player1;
    Player* player2;
    Board gameBoard;

    // Methods
    static void printIntroduction();
    static void printDirections();
    void printScoreReport();

    static void printMenu();
    static int getMenuResponse();
    int handleBranchResponses(int arr);

    void playRound();
};


#endif //CONNECTFOUR_GAME_H
