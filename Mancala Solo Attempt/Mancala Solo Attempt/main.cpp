#include <iostream>
#include <conio.h>
#include <string>
#include "MancalaBoard.h"
#include "Player.h"
#include <stdlib.h>

std::string MultiplayerGame();


int main() {
	std::string winner = MultiplayerGame();
	std::cout << "The winner is: " << winner << std::endl;

	_getch();
	return 0;
}

/*
	This function checks for valid choice
	@param choice The player's choice
	@return Return true if valid
			Return fasle if not valid
*/
bool CheckForValidChoice(int choice) {
	if (choice > 0 && choice <= 6)
		return true;
	else
		return false;
}

/*
	This function creates a local multiplayer game
	@param board This is the playing board
	@return Return the name of the winner
*/
std::string MultiplayerGame() {
	//Create a playing board
	MancalaBoard playingboard;

	//Creating first player 
	std::string name;
	std::cout << "Enter a Name for Player 1: ";
	std::cin >> name;
	Player player1(1, name);
	system("CLS");

	//Creating second player
	std::cout << "Enter a Name for Player 2: ";
	std::cin >> name;
	Player player2(2, name);
	system("CLS");

	//Game loop
	while (true) {
		playingboard.RenderingBoard();
		int choice;

		//Player 1's Turn
		if (player1.GetPlayerTurn()) {
			std::cout << player1.GetName() << "'s turn: ";
			//Check for Valid Choice
			while (std::cin >> choice) {
				if (choice > 0 && choice <= 6) {
					choice--;
					break;
				}
				else {
					std::cout << "Invalid Choice. Please enter again: ";
					continue;
				}
			}
			player1.PlayerMoves(choice, player2, playingboard);
		}

		//Player2's Turn
		else if (player2.GetPlayerTurn()) {
			std::cout << player2.GetName() << "'s turn: ";
			//Check for Valid Choice
			while (std::cin >> choice) {
				if (CheckForValidChoice(choice)) {
					choice--;
					break;
				}
				else {
					std::cout << "Invalid Choice. Please enter again: ";
					continue;
				}
			}
			player2.PlayerMoves(choice, player1, playingboard);
		}

		//Check if the game ends
		if (playingboard.CheckIfGameEnds()) {
			playingboard.AddUpPoints();
			if (playingboard.GetMancalaGameIndex(6) > playingboard.GetMancalaGameIndex(13))
				return player1.GetName();
			else if (playingboard.GetMancalaGameIndex(6) < playingboard.GetMancalaGameIndex(13))
				return player2.GetName();
		}

		system("CLS");
	}
}