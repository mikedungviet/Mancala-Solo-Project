#include "MancalaBoard.h"


void MancalaBoard::RenderingBoard() {
	std::cout << "________________________________________________________________" << std::endl;
	std::cout << "|\t|\t|\t|\t|\t|\t|\t|\t|" << std::endl << "|\t";


	for (int i = 12; i >= 7; i--) {
		if (mancalaGameArray[i] >= 10)
			std::cout << "|  " << mancalaGameArray[i] << "   ";
		else
			std::cout << "|   " << mancalaGameArray[i] << "   ";
	}

	std::cout << "|\t|\n|\t|\t|\t|\t|\t|\t|\t|\t|" << std::endl;
	if (mancalaGameArray[13] >= 10)
		std::cout << "|  " << mancalaGameArray[13] << "   |";
	else
		std::cout << "|   " << mancalaGameArray[13] << "   |";

	std::cout << "_______|_______|_______|_______|_______|_______";


	if (mancalaGameArray[6] >= 10)
		std::cout << "|  " << mancalaGameArray[6] << "   |";
	else
		std::cout << "|   " << mancalaGameArray[6] << "   |";


	std::cout << "\n|\t|\t|\t|\t|\t|\t|\t|\t|\n|\t";
	for (int i = 0; i < 6; i++) {
		if (mancalaGameArray[i] >= 10)
			std::cout << "|  " << mancalaGameArray[i] << "   ";
		else
			std::cout << "|   " << mancalaGameArray[i] << "   ";
	}


	std::cout << "|\t|\n|\t|\t|\t|\t|\t|\t|\t|\t|" << std::endl;
	std::cout << "|_______|_______|_______|_______|_______|_______|_______|_______|" << std::endl;
}

/*
	This function check if the games meets the condition to be ended
	@return True if the condition is met; False if the condition has not been met
*/
bool MancalaBoard::CheckIfGameEnds() {
	if (mancalaGameArray[0] == 0 && mancalaGameArray[1] == 0 && mancalaGameArray[2] == 0 && mancalaGameArray[3] == 0 &&
		mancalaGameArray[4] == 0 && mancalaGameArray[5] == 0)
		return true;
	else if (mancalaGameArray[7] == 0 && mancalaGameArray[8] == 0 && mancalaGameArray[9] == 0 && mancalaGameArray[10] == 0 &&
		mancalaGameArray[11] == 0 && mancalaGameArray[12] == 0)
		return true;
	else
		return false;
}

/*
	This function adds up all point for two players
*/
void MancalaBoard::AddUpPoints() {
	//Add up points for player 1
	for (int i = 0; i <= 5; i++) {
		mancalaGameArray[6] += mancalaGameArray[i];
		mancalaGameArray[i] = 0;
	}

	//Add up points for player 2
	for (int j = 7; j <= 12; j++) {
		mancalaGameArray[13] += mancalaGameArray[j];
		mancalaGameArray[j] = 0;
	}
}


