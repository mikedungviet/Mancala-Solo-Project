#include <iostream>
#include <conio.h>
#include <string>
#include "MancalaBoard.h"
#include "Player.h"

int main() {
	Player playerOne(1, "Mike");
	Player playerTwo(2, "Mike2");
	MancalaBoard playingBoard;

	playingBoard.renderingBoard();
	playerOne.playerMoves(1, playerTwo, playingBoard);

	//playingBoard.renderingBoard();



	_getch();
	return 0;
}