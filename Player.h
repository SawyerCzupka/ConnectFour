//
// Created by Sawyer on 3/22/2021.
//

#ifndef CONNECTFOUR_PLAYER_H
#define CONNECTFOUR_PLAYER_H

#include <string>

class Board;
class Player {
public:
    // Constructors
    Player();
    explicit Player(std::string name);

    // Methods
    void addWin();
    void resetWinCount();

    virtual int getMove(Board brd) const = 0;

    // Getters & Setters
    char getPieceChar() const;
    int getWinCount() const;
    void setPieceChar(char pieceChar);
    const std::string &getName() const;

protected:
    char pieceChar = 'A';
    std::string name;
    int winCount;
};


#endif //CONNECTFOUR_PLAYER_H
