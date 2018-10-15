/*
	Class commenting 
*/
#pragma once
#include <iostream>
class MancalaBoard
{
private:
	int mancalaGameArray[14];
	friend class Player;

public:
	MancalaBoard() {
		int tempArray[]{ 4,4,4,4,4,4,0,4,4,4,4,4,4,0 };
		std::copy(tempArray, tempArray + 14, mancalaGameArray);
	}

	~MancalaBoard() {

	}

	/*
		Get the value at the "index" position of the mancalaGameArray
		@param The index to take from
		@return Return the value at that index
	*/
	int GetMancalaGameIndex(int index) {
		return mancalaGameArray[index];
	}

	/*
		Set the value at the "index" position of the mancalaGameArray
		to 0
		@param The index of the array to set to 0
	*/
	void SetValueOfMancalaGameIndexTo0(int index) {
		mancalaGameArray[index] = 0;
	}

	/*
		Set the value at the "index" position of the mancalaGameArray
		to a number
		@param index The index of the array to set to a value
		@param value The number to set the value of the index to
	*/
	void SetValueOfMancalaGameIndex(int index, int value) {
		mancalaGameArray[index] = value;
	}

	//Class member functions
	void RenderingBoard();
	bool CheckIfGameEnds();
	void AddUpPoints();
};


