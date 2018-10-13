#pragma once
#include <iostream>
class MancalaBoard
{
private:
	int mancalaGameArray[14];
	friend class Player;

public:
	MancalaBoard() {
		for (int i = 0; i < 14; i++) {
			if (i == 6 || i == 13) {
				mancalaGameArray[i] = 0;
				continue;
			}
			else if (i == 1) {
				mancalaGameArray[i] = 12;
				continue;
			}
			mancalaGameArray[i] = 4;
		}
	}

	~MancalaBoard() {

	}

	/*
		Get the value at the "index" position of the mancalaGameArray
		@param The index to take from
		@return Return the value at that index
	*/
	int getMancalaGameIndex(int index) {
		return mancalaGameArray[index];
	}

	/*
	*/
	void setValueOfMancalaGameIndexTo0(int index) {
		mancalaGameArray[index] = 0;
	}

	void setValueOfMancalaGameIndex(int index, int value) {
		mancalaGameArray[index] = value;
	}

	void renderingBoard();
};


