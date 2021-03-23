//
// Created by Sawyer on 3/22/2021.
//

#include "Player.h"
#include "Board.h"

Player::Player(std::string name) : name(std::move(name)) {
    winCount = 0;
}

char Player::getPieceChar() const {
    return pieceChar;
}

void Player::resetWinCount() {
    winCount = 0;
}

void Player::addWin() {
    winCount++;
}

int Player::getWinCount() const {
    return winCount;
}

Player::Player() {
    pieceChar = 'a';
    winCount = 0;
    name = "Jane Doe";
}

void Player::setPieceChar(char pieceChar) {
    Player::pieceChar = pieceChar;
}

const std::string &Player::getName() const {
    return name;
}


