#include "MancalaBoard.h"


void MancalaBoard::renderingBoard() {
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

