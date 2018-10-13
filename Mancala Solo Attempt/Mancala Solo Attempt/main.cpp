#include <iostream>
#include <conio.h>
#include <string>
#include "MancalaBoard.h"
#include "Player.h"
#include <stdlib.h>

std::string MultiplayerGame(MancalaBoard &board);


int main() {
	MancalaBoard playingBoard;
	std::string winner = MultiplayerGame(playingBoard);
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
*/
std::string MultiplayerGame(MancalaBoard &board) {
	std::string name;
	std::cout << "Enter a Name for Player 1: ";
	std::cin >> name;
	Player player1(1, name);

	std::cout << "Enter a Name for Player 2: ";
	std::cin >> name;
	Player player2(2, name);
	system("CLS");

	while (true) {
		board.RenderingBoard();
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

			player1.PlayerMoves(player1.GetPlayerStorageIndex(choice), player2, board);
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
			std::cout << player2.GetPlayerStorageIndex(choice) << std::endl;

			player2.PlayerMoves(player2.GetPlayerStorageIndex(choice), player1, board);
		}

		//Check if the game ends
		if (board.CheckIfGameEnds()) {
			board.AddUpPoints();
			if (board.GetMancalaGameIndex(6) > board.GetMancalaGameIndex(13))
				return player1.GetName();
			else if (board.GetMancalaGameIndex(6) < board.GetMancalaGameIndex(13))
				return player2.GetName();
		}

		system("CLS");
	}
}