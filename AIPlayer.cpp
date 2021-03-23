//
// Created by Sawyer on 3/23/2021.
//

#include "AIPlayer.h"
#include "Board.h"

#include <iostream>

AIPlayer::AIPlayer(const std::string &name) : Player(name) {}

int AIPlayer::getMove(Board brd) const {
    std::cout << "Child" << std::endl;
    return 0;
}
