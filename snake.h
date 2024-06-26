#pragma once
#include "globals.h"
#include <utility>

class snake
{
public:
	//std::pair<int, int> SnakeHead = std::make_pair(globals::c_Height / 2, globals::c_Width / 2 - 1); 
	globals::COORD SnakeBody{ std::make_pair(globals::c_Height / 2, globals::c_Width / 2 - 1) };
	char SnakeDirection = 'd';
	void ChangeDirection(char Key);
	void MoveSnake();
	void AddSegment();
	bool checkCollision();
private:
	
};

