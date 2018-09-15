#include <ctime>
#include <cstdlib>
#include <iostream>

void initializeRandomNumbers( );
int getRandomPlayerChoice( );
int getUserPlayerChoice( std::istream& input_stream, std::ostream& output_stream );
int determineWinner( int user_choice, int random_choice );
void displayMatchResults( std::ostream& output_stream, int user_choice, int random_choice, int winner );
void displayStatistics( std::ostream& output_stream, int number_user_wins, int number_user_losses, int number_user_ties );
bool askUserIfGameShouldContinue( std::istream& input_stream, std::ostream& output_stream );
