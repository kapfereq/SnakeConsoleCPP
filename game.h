#pragma once
#include "food.h"
#include "snake.h"

class game
{
public:
	void Game();
	void LoadBoard();
private:
	bool gameOver = false;
	snake PlayerSnake;
	food CurrentFood;
	int score = 0;

};

