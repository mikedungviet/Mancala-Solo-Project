/*
	Class commenting
*/
#pragma once
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include "MancalaBoard.h"
class Player
{
private:
	std::string name;
	int playerStorageIndex[6];
	int mancalaIndexLocation;
	bool playerTurn;
public:
	/*
		This is set to be the default consturctor for Player Class
		@param playerNumber There can only 2 players exist at a time
							therefore this number will be set with 
							1 or 2
		@param name This is the name of the player. If the player 
					does not enter a name, set it to "Player"

	*/
	Player(int playerNumber, std::string name = "Player")
		: name{ name } {
		if (playerNumber == 1) {
			int newArray[] = { 0,1,2,3,4,5};
			std::copy(newArray, newArray + 6, playerStorageIndex);
			mancalaIndexLocation = 6;
		}
		else if (playerNumber == 2) {
			int newArray[] = { 12,11,10,9,8,7};
			std::copy(newArray, newArray + 6, playerStorageIndex);
			mancalaIndexLocation = 13;
		}
	}

	~Player() {
	}

	/*
		This function returns the player name
		@return Returns the name as a string
	*/
	std::string GetName() {
		return this->name;
	}

	/*
		This get the possible index
		@return Return the corresponding index
	*/
	int GetPlayerStorageIndex(int index) {
		return playerStorageIndex[index];
	}

	/*
		This function set the player turn 
		@param turn This bool sets if true then it is the player turn
				else not the player turn
	*/
	void SetPlayerTurn(bool turn) {
		playerTurn = turn;
	}

	/*
		This function get if whether it is a player turn
		@return Return false if it is not the player's turn
				Return true if it is the player's turn
	*/
	bool GetPlayerTurn() {
		return playerTurn;
	}

	//Members functions
	void PlayerMoves(int, Player &opponent, MancalaBoard &board);
	int CheckIfIndexIsInPlayersRange(int arr[], int firstIndex, int rightSide, int index);
	void PerformSteal(int, Player &opponent, MancalaBoard &board);
};

