#pragma once
#include <utility>
#include "snake.h"

class food
{
public:
	std::pair<int, int> CurrentFoodCoord;
	void GenerateRandomPosition(snake Snake);
private:
};

