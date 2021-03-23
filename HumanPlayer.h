//
// Created by Sawyer on 3/23/2021.
//

#ifndef CONNECTFOUR_HUMANPLAYER_H
#define CONNECTFOUR_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer: public Player {
public:
    explicit HumanPlayer(const std::string &name);

    int getMove(Board brd) const override;
};


#endif //CONNECTFOUR_HUMANPLAYER_H
