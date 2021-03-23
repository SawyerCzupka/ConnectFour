//
// Created by Sawyer on 3/23/2021.
//

#ifndef CONNECTFOUR_AIPLAYER_H
#define CONNECTFOUR_AIPLAYER_H

#include "Player.h"

class AIPlayer: public Player {
public:
    explicit AIPlayer(const std::string &name);

    int getMove(Board brd) const override;

};


#endif //CONNECTFOUR_AIPLAYER_H
