#include "rps.h"

int main() {
    int win = 0;
    int loss = 0;
    int tie = 0;
    bool keepGoing = true;
    while (keepGoing) {
        initializeRandomNumbers();
        int random = getRandomPlayerChoice();
        int choice = getUserPlayerChoice(std::cin, std::cout);
        int winner = determineWinner(choice, random);
        if (winner == 13) {
            tie += 1;
        } else if (winner == 12) {
            loss += 1;
        } else if (winner == 11) {
            win += 1;
        }
        displayMatchResults(std::cout, choice, random, winner);
        displayStatistics(std::cout, win, loss, tie);
        bool continueGame = askUserIfGameShouldContinue(std::cin, std::cout);
        if (continueGame == false) {
            keepGoing = false;
        }
    }
    return 0;

}