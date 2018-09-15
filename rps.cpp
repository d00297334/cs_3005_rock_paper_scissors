#include "rps.h"
#include <string>
#include <iostream>

void initializeRandomNumbers( ) {
    std::srand(std::time(0));
}

int getRandomPlayerChoice( ) {
    int r = rand() % 3 + 1;
    return r;  
}

int getUserPlayerChoice( std::istream& input_stream, std::ostream& output_stream ) {

    int userOutput = 0;
    std::string userChoice;
    while (userOutput == 0 ) {
        output_stream << "Choice? (rock, paper, scissors)";
        input_stream >> userChoice;
        if (userChoice == "rock") {
            userOutput = 1;
        } else if (userChoice == "paper") {
            userOutput = 2;
        } else if (userChoice == "scissors") {
            userOutput = 3;
        } else {
            output_stream << "That is not a valid option." << std::endl;
            userOutput = 0;
        }
    } return userOutput;
}

 //rock =1, paper =2, scissor =3
int determineWinner( int user_choice, int random_choice ) {
    if (user_choice == random_choice) {
        return 13; //tie
    } else if (user_choice == 1 && random_choice == 2 ) {
        return 12; 
    } else if (user_choice == 1 && random_choice == 3) {
        return 11; 
    } else if (user_choice == 2 && random_choice == 3) {
        return 12;     
    } else if (random_choice == 1 && user_choice == 2 ) {
        return 11; 
    } else if (random_choice == 1 && user_choice == 3) {
        return 12; 
    } else if (random_choice == 2 && user_choice == 3) {
        return 11;
    } else {
        return 0;
    }
}

void displayMatchResults( std::ostream& output_stream, int user_choice, int random_choice, int winner ) {
    //winner = determineWinner(user_choice, random_choice);
    std::string results;
    if (winner == 11) {
        results = "win";
    } else if (winner == 12) {
        results = "lose";
    } else {
        results = "tie";
    }
    std::string userString;
    std::string randomString;

    if (user_choice == 1 ) {
        userString = "rock";
    } else if (user_choice == 2) {
        userString = "paper";
    } else if (user_choice == 3) {
        userString = "scissors";
    }

    if (random_choice == 3) {
        randomString = "scissors";
    } else if (random_choice == 2) {
        randomString = "paper";
    } else if (random_choice == 1) {
        randomString = "rock";
    }

    output_stream << "You chose " << userString << ". " << "Computer chose " << randomString << ". " << "You " << results << "." << std::endl;
}

void displayStatistics( std::ostream& output_stream, int number_user_wins, int number_user_losses, int number_user_ties ){
    output_stream << "Win: " << number_user_wins << "  Lose: " << number_user_losses << "  Tie: " << number_user_ties << std::endl;
}

bool askUserIfGameShouldContinue( std::istream& input_stream, std::ostream& output_stream ) {
    output_stream << "Play again? ";
    std::string myString;
    input_stream >> myString;
    if (myString[0] == 'y' || myString[0] == 'Y') {
        return true;
    } else {
        return false;
    }
}