#pragma once
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include "MancalaBoard.h"
class Player
{
private:
	std::string name;
	int playerStorageIndex[7];
public:
	Player(int playerNumber, std::string name = "None")
		: name{ name } {
		if (playerNumber == 1) {
			int newArray[] = { 0,1,2,3,4,5,6 };
			std::copy(newArray, newArray + 7, playerStorageIndex);
		}
		else if (playerNumber == 2) {
			int newArray[] = { 12,11,10,9,8,7,13 };
			std::copy(newArray, newArray + 7, playerStorageIndex);
		}
	}
	~Player() {
	}
	/*
		This function returns the player name
		@return Returns the name as a string
	*/
	std::string getName() {
		return this->name;
	}

	/*
		This get the possible index
		@return Return the corresponding index
	*/
	int getPlayerStorageIndex(int index) {
		return playerStorageIndex[index];
	}


	//Members functions
	void playerMoves(int index, Player &opponent, MancalaBoard &board);
	int CheckIfIndexIsInPlayersRange(int arr[], int firstIndex, int rightSide, int index);
	void PerformSteal(int index, Player &opponent, MancalaBoard &board);


};

