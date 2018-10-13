#include "Player.h"
/*
	This recursive function performs a binary check to see if the "index" is inside the array.
	This will be use as a condition for stealing and get a free turn if the last piece drops in
	the mancala
	@param arr[] This is the array to search
	@param firstIndex This is the array starting point
	@param lastIndex This is the end index of the array
	@param number This is the number to search for
	@return Return True if the number is in the array; Return false if the number is not in the array
*/
int Player::CheckIfIndexIsInPlayersRange(int arr[], int firstIndex, int lastIndex, int number) {
	if (firstIndex <= lastIndex) {
		int midIndex = (firstIndex + lastIndex) / 2;

		if (arr[midIndex] == number)
			return midIndex;
		else if (arr[midIndex] > number)
			return CheckIfIndexIsInPlayersRange(arr, firstIndex, midIndex - 1, number);
		else
			return CheckIfIndexIsInPlayersRange(arr, midIndex + 1, lastIndex, number);
	}
	return -1;
}

/*
	This function performs a steal
*/
void Player::PerformSteal(int index, Player &opponent, MancalaBoard &board) {

	int newScore = board.getMancalaGameIndex(index) + board.getMancalaGameIndex(opponent.getPlayerStorageIndex(index)) + 1;
	board.setValueOfMancalaGameIndex(playerStorageIndex[6], newScore);
	board.setValueOfMancalaGameIndexTo0(opponent.getPlayerStorageIndex(index));
	board.setValueOfMancalaGameIndexTo0(getPlayerStorageIndex(index));
}


/*
*/
void Player::playerMoves(int index, Player &opponent, MancalaBoard &board) {
	int counter = board.getMancalaGameIndex(index);
	board.setValueOfMancalaGameIndexTo0(index);

	for (counter; counter >= 0; counter--) {
		system("CLS");
		index++;

		if (index > 13)
			index = 0;

		//Skips the opponent's mancala if the index is equal to theirs
		if (index == opponent.getPlayerStorageIndex(6)) {
			counter++;
			continue;
		}

		board.mancalaGameArray[index]++;
		//Check for conditions
		if (counter == 0) {
			int lastIndex = CheckIfIndexIsInPlayersRange(playerStorageIndex, 0, 7, index);
			if (lastIndex > 0 && lastIndex < 7) {
				PerformSteal(index, opponent, board);
			}
		}


		board.renderingBoard();
		Sleep(500);
	}
}