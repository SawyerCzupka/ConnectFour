//
// Created by Sawyer on 3/22/2021.
//

#include "Board.h"

#include <iostream>

void Board::printBoard() {
    for (auto row : boardArray) {
        std::cout << "|" ;
        for (auto item : row) {
            std::cout << " " << item << " |";
        }
        std::cout << std::endl;
    }
}

void Board::initializeBoardArray() { // empty space represented as ' '
    boardArray.at(0).at(3) = 'H';
    for (auto & i : boardArray) {
        i.fill(' ');
    }

    for (auto & item : lowestOpenRowAtColumn) {
        item = 5;
    }
}

void Board::insertPiece(const Player* player, int column) {
    if (isValidPlacement(column)) {
        boardArray.at(lowestOpenRowAtColumn.at(column)).at(column) = player->getPieceChar();
        lowestOpenRowAtColumn.at(column)--;
    }
}

bool Board::isValidPlacement(int column) {
    if (boardArray.at(0).at(column) != ' ') {
        return false;
    }

    return true;
}

bool Board::isWinCondition() {
    if (isHorizontalWinner() || isVerticalWinner() || isDiagonalWinner()) {
        std::cout << "returns true" << std::endl;
        return true;
    }
    return false;
}

bool Board::isHorizontalWinner() {
    int currentStreak;
    char pieceBeingChecked;

    for (auto & row : boardArray) {
        currentStreak = 1;
        pieceBeingChecked = row.at(0);

        for (int i = 1; i < row.size(); i++) {
            char current = row.at(i);

            if (pieceBeingChecked == current && current != ' ') {
                currentStreak++;

                if (currentStreak == 4) {
                    winner = (player1->getPieceChar() == pieceBeingChecked) ? player1 : player2;
                    return true;
                }

                continue;
            }
            else {
                currentStreak = 1;
                pieceBeingChecked = current;
            }
        }
    }

    return false;
}

bool Board::isVerticalWinner() {
    int currentStreak;
    char pieceBeingChecked;

    for (int col = 0; col < boardArray.at(0).size(); col++) {
        for (int row = 0; row < boardArray.size(); row++) {
            char current = boardArray.at(row).at(col);
            if (row == 0) { currentStreak = 1; pieceBeingChecked = current; continue;}

            if (current != ' ' && current == pieceBeingChecked) {
                currentStreak++;

                if (currentStreak == 4) {
                    winner = (player1->getPieceChar() == pieceBeingChecked) ? player1 : player2;
                    return true;
                }

                continue;
            }
            else {
                currentStreak = 1;
                pieceBeingChecked = current;
            }
        }
    }

    return false;
}

bool Board::isDiagonalWinner() { // https://stackoverflow.com/questions/39062111/java-how-to-check-diagonal-connect-four-win-in-2d-array
    const int maxX = 7;
    const int maxY = 6;

    int directions[][2] = {{1, 0}, {1, -1}, {1,1}, {0,1}};
    for (auto dir : directions) {
        int dx = dir[0];
        int dy = dir[1];

        for (int x = 0; x < maxX; x++) {
            for (int y = 0; y < maxY; y++) {
                int lastX = x + (3 * dx);
                int lastY = y + (3 * dy);

                if (0 <= lastX && lastX < maxX && 0 <= lastY && lastY < maxY) {
                    char current = boardArray.at(y).at(x);
                    if (current != ' ' && current == boardArray.at(y+dy).at(x+dx)
                                       && current == boardArray.at(y+(2*dy)).at(x+(2*dx))
                                       && current == boardArray.at(lastY).at(lastX)) {
                        winner = (player1->getPieceChar() == current) ? player1 : player2;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

const Player* Board::getWinner() const {
    return winner;
}

Board::Board() = default;

Board::Board(Player *player1, Player *player2) : player1(player1), player2(player2) {
    initializeBoardArray();
}
