#include "game.h"
#include "globals.h"
#include <iostream>
#include <windows.h> 
#include <conio.h>

void game::Game()
{
    // Take random seed from current time and generate starting food
    srand(time(nullptr));
    CurrentFood.GenerateRandomPosition(PlayerSnake);
    // Game loop
	while (!gameOver) {
        // Clear the frame
		system("cls");
        // Move snake according to current direction
        PlayerSnake.MoveSnake();
        // Load the board
		LoadBoard();
        // Check if snake is changing direction
		if (_kbhit()) {
			PlayerSnake.ChangeDirection(_getch());
		}
        // Waiting using global game speed intager
		Sleep(globals::c_GameSpeed);
	}
    system("cls");
    std::cout << "Congratulations! You finished the game with " << score << " score!\n\n\n";\
        for (auto& element : PlayerSnake.SnakeBody) {
            std::cout << "\n element first: " << element.first << " element second: " << element.second;
        }
    Sleep(5000);
}

void game::LoadBoard()
{
    //print out the map, snake, and food based on current locations
    for (int i = 0; i < globals::c_Height; ++i) {
        std::cout << "\t\t#";
        for (int j = 0; j < globals::c_Width - 2; ++j) {
            // Check if the snake head encountered food
            if (CurrentFood.CurrentFoodCoord.first == PlayerSnake.SnakeBody[0].second &&
                CurrentFood.CurrentFoodCoord.second == PlayerSnake.SnakeBody[0].first) {
                PlayerSnake.AddSegment();
                CurrentFood.GenerateRandomPosition(PlayerSnake);
                score++;
            }
            // Check if we encountered the head of the snake
            if (i == PlayerSnake.SnakeBody[0].first && j == PlayerSnake.SnakeBody[0].second)
                std::cout << "@";
            // Check if we encountered any of the snake coordinates
            else if (std::find(PlayerSnake.SnakeBody.begin(), PlayerSnake.SnakeBody.end(),
                std::make_pair(i, j)) != PlayerSnake.SnakeBody.end()) {
                std::cout << "O";
            }
            // Check if we encountered food
            else if (CurrentFood.CurrentFoodCoord.first == j && CurrentFood.CurrentFoodCoord.second == i) {
                std::cout << "+"; // Print "+" for food
            }
            // Check if we encountered a wall or the snake itself (ENDS GAME)
            else if (PlayerSnake.checkCollision())
                gameOver = true;
            else {
                // Print space for empty cells and # for top and bottom rows
                if (i == 0 || i == globals::c_Height - 1) {
                    std::cout << '#';
                }
                else {
                    std::cout << ' ';
                }
            }
        }
        std::cout << "#\n";
    }
    std::cout << "\n Current score: \t" << score;
    std::cout << "\n" << PlayerSnake.SnakeBody[0].first << " " << PlayerSnake.SnakeBody[0].second;
    std::cout << "\n FoodX: " << CurrentFood.CurrentFoodCoord.first << " SnakeX: " << PlayerSnake.SnakeBody[0].first
        << "\n FoodY: " << CurrentFood.CurrentFoodCoord.second << " SnakyY: " << PlayerSnake.SnakeBody[0].second; 
}


