//
// Created by Sawyer on 3/22/2021.
//

#ifndef CONNECTFOUR_BOARD_H
#define CONNECTFOUR_BOARD_H

#include <array>
#include "Player.h"

class Board {
public:
    // Constructors
    Board();
    Board(Player *player1, Player *player2);

    // Methods
    bool isWinCondition();
    void printBoard();
    void insertPiece(const Player* player, int column);
    bool isValidPlacement(int column);
    void initializeBoardArray();

    // Getters & Setters
    const Player* getWinner() const;

private:
    // Instance Variables
    Player* player1{};
    Player* player2{};
    Player* winner = nullptr;

    std::array<std::array<char, 7>, 6> boardArray{};
    std::array<int, 7> lowestOpenRowAtColumn{};

    // Methods
    bool isHorizontalWinner();
    bool isVerticalWinner();
    bool isDiagonalWinner();
};


#endif //CONNECTFOUR_BOARD_H
