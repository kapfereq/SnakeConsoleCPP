#pragma once
#include "food.h"
#include "snake.h"
#include "globals.h"

void food::GenerateRandomPosition(snake Snake)
{
    int randomX, randomY;
    do {
        randomX = rand() % (globals::c_Width - 2) + 1; // Avoid border and snake body
        randomY = rand() % (globals::c_Height - 2) + 1;
    } while (std::find(Snake.SnakeBody.begin(), Snake.SnakeBody.end(),
        std::make_pair(randomX, randomY)) != Snake.SnakeBody.end());

    // Update food coordinates
    CurrentFoodCoord.first = randomX;
    CurrentFoodCoord.second = randomY;
}
