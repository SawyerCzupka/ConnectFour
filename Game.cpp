//
// Created by Sawyer on 3/22/2021.
//

#include "Game.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"

#include <iostream>


void Game::printIntroduction() {
    std::cout << "Welcome to Connect Four!" << std::endl;
}

void Game::printDirections() {
    std::cout << "To play your turn, type in the index of the column you would like to put your piece into (0-6).\n"
                 "If the column is full, you will be asked to submit a different column to play.\n"
                 "When the game finishes, the winning player will have a point added onto their score.\n"
                 "At the end of a game you can type 'reset' to reset your scores, type 'again' to play another game,"
                 "or type 'end' to finish the game." << std::endl;
}

void Game::playRound() {
    gameBoard.initializeBoardArray();
    Player* nextPlayer = player1;
    gameBoard.printBoard();

    while (true) {
        Player* currentPlayer = nextPlayer;
        nextPlayer = (currentPlayer == player1) ? player2 : player1;
        std::string str = currentPlayer->getName();

        gameBoard.insertPiece(currentPlayer, currentPlayer->getMove(gameBoard));
        gameBoard.printBoard();

        if (gameBoard.isWinCondition()) {
            break;
        }
    }

    if (player1->getName() == gameBoard.getWinner()->getName()) {
        player1->addWin();
    }
    else {
        player2->addWin();
    }

    std::cout << gameBoard.getWinner()->getName() << " is the winner! Ez clap, winner winner chicken dinner" << std::endl;
}

Game::Game(const std::string& one, const std::string& two, bool isAiGame) {
    if (isAiGame) {
        player1 = new HumanPlayer(one);
        player2 = new AIPlayer(two);
    } else {
        player1 = new HumanPlayer(one);
        player2 = new HumanPlayer(two);
    }

    player1->setPieceChar('X');
    player2->setPieceChar('Y');

    gameBoard = Board(player1, player2);
}

[[ noreturn ]] void Game::mainloop() {
    std::cout << player1->getName() << std::endl;
    std::cout << player2->getName() << std::endl;
    printIntroduction();
    printDirections();

    while (true) {
        playRound();
        int r = getMenuResponse();
        int response = handleBranchResponses(r);

        switch (response) {
            case 1:
                continue;
                case 2:
                player1->resetWinCount();
                player2->resetWinCount();
                break;
            case 4:
               exit(EXIT_SUCCESS);
            default:
                std::cout << "Something went wrong. Response Value: " << response << std::endl;
                exit(EXIT_SUCCESS);
        }
    }
}

void Game::printMenu() {
    std::cout << "What would you like to do now?" << std::endl;
    std::cout << "1. Play again\n"
                 "2. Reset scores\n"
                 "3. Get Score Report\n"
                 "4. End the game" << std::endl;
}

int Game::getMenuResponse() {
    int response;
    printMenu();

    do {
        std::cout << "Enter your response: " << std::endl;
        std::cin >> response;
    } while (!(response >= 1 && response <= 4));


    return response;
}

void Game::printScoreReport() {
    double totalGamesPlayed = player1->getWinCount() + player2->getWinCount();
    std::string player1Name = player1->getName();
    std::string player2Name = player2->getName();
    int player1WinCount = player1->getWinCount();
    int player2WinCount = player2->getWinCount();

    std::cout << "-------------------- Score Report --------------------" << std::endl;
    std::cout << player1Name << " won " << player1WinCount << " games." << std::endl;
    std::cout << player2Name << " won " << player2WinCount << " games." << std::endl;
    std::cout << std::endl;
    std::cout << player1Name << " had a win percentage of " << player1WinCount / totalGamesPlayed << std::endl;
    std::cout << player2Name << " had a win percentage of " << player2WinCount / totalGamesPlayed << std::endl;

    std::cout << std::endl;
}

int Game::handleBranchResponses(int arr) {
    if (arr == 3) {
        printScoreReport();
        return getMenuResponse();
    }
    else {
        return arr;
    }
}

void Game::test() {
    std::cout << player1->getName() << std::endl;
    std::cout << player2->getName() << std::endl;
}
