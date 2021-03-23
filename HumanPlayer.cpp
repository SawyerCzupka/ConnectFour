//
// Created by Sawyer on 3/23/2021.
//

#include "HumanPlayer.h"
#include "Board.h"

#include <iostream>

int HumanPlayer::getMove(Board brd) const {
    std::cout << "It is " << getName() << "'s turn. ";

    int column;

    do {
        std::cout << "Please type the column you would like to place your piece (0-6): " << std::endl;
        std::cin >> column;

        if (!(column >=0 && column <=6)) {
            std::cout << "Invalid column, please try again." << std::endl;
        }

        else if (!brd.isValidPlacement(column)) {
            std::cout << "That column is full, please try again." << std::endl;
        }
    } while (!(column >=0 && column <=6) || !brd.isValidPlacement(column));

    return column;
}

HumanPlayer::HumanPlayer(const std::string &name) : Player(name) {}
