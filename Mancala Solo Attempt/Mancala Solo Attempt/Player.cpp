#include "Player.h"
/*
	This recursive function performs a binary check to see if the binary is inside the array.
	This will be use as a condition for stealing and get a free turn if the last piece drops in
	the mancala
	@param arr[] This is the array to search
	@param firstIndex This is the array starting point
	@param lastIndex This is the end index of the array
	@param number This is the number to search for
	@return Return the index where the  number is found; Return -1 if the number is NOT in the 
			array
*/
int Player::CheckIfIndexIsInPlayersRange(int arr[], int firstIndex, int lastIndex, int number) {
	//if the array is in the ascending order
	if (firstIndex <= lastIndex) {
		int midIndex = (firstIndex + lastIndex) / 2;

		if (arr[midIndex] == number)
			return midIndex;
		else if ((arr[firstIndex] < arr[lastIndex]) //Check if the order is ascending or descending
			//If the order is ascending: number is smaller than midpoint, therefore on the right right side
			? (arr[midIndex] > number) 
			//If the order is decending: number is bigger than mid, therefore on the right side
			: (arr[midIndex] < number))
			return CheckIfIndexIsInPlayersRange(arr, firstIndex, midIndex - 1, number);
		else
			return CheckIfIndexIsInPlayersRange(arr, midIndex + 1, lastIndex, number);
	}
	return -1; //Return -1 if the number is not in the array
}

/*
	This function performs a steal
	@param index The index where the steal will perform
	@param &opponent An instance of the opponent player object
	@param &board An instance of a board object
*/
void Player::PerformSteal(int index, Player &opponent, MancalaBoard &board) {

	int newScore = board.GetMancalaGameIndex(index) + board.GetMancalaGameIndex(opponent.GetPlayerStorageIndex(index)) + 1;
	board.SetValueOfMancalaGameIndex(playerStorageIndex[6], newScore);
	board.SetValueOfMancalaGameIndexTo0(opponent.GetPlayerStorageIndex(index));
	board.SetValueOfMancalaGameIndexTo0(GetPlayerStorageIndex(index));
}


/*
	This fuction performs a series of step to change the players move
	@param choice This is the player choice
	@param opponent The opponent player object
	@param board The playing board
*/
void Player::PlayerMoves(int choice, Player &opponent, MancalaBoard &board) {
	playerTurn = false;
	opponent.SetPlayerTurn(true);

	int index = playerStorageIndex[choice];

	int counter = board.GetMancalaGameIndex(index);
	board.SetValueOfMancalaGameIndexTo0(index);

	for (counter; counter > 0; counter--) {
		system("CLS");
		index++;

		if (index > 13)
			index = 0;

		/*Skips the opponent's mancala if the index is equal to their
		  Mancala Location */
		if (index == opponent.GetPlayerStorageIndex(6)) {
			counter++;
			continue;
		}

		board.mancalaGameArray[index]++;

		//Check for special conditions
		if (counter == 1) {
			int lastIndex = CheckIfIndexIsInPlayersRange(playerStorageIndex, 0, 5, index);
			//Conditions for stealing
			if (lastIndex >= 0 && lastIndex < 7 && board.GetMancalaGameIndex(index)== 1) {
				PerformSteal(index, opponent, board);
			}
			//Conditions for getting a free turn
			else if (index == mancalaIndexLocation) {
				playerTurn = true;
				opponent.SetPlayerTurn(false);
			}
		}
		board.RenderingBoard();
		Sleep(500);
	}
}