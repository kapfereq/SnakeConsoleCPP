#include "game.h"
#include "globals.h"
#include <iostream>
#include <windows.h> 

void game::Game()
{
	while (!gameOver) {
		system("cls");
		LoadBoard();
		Sleep(globals::c_GameSpeed);
	}
}

void game::LoadBoard()
{
	//print out the map, snake, and food based on current locations
	for (int i = 0; i < globals::c_Height; ++i) {
		std::cout << "\t\t#";
		for (int j = 0; j < globals::c_Width - 2; ++j) {
			if (i == 0 || i == globals::c_Height - 1) { std::cout << '#'; }
			//check if we encountered any of the snake coordinates
			/*else if (j == PlayerSnake.SnakeHead.first && i ==  PlayerSnake.SnakeHead.second) {
				std::cout << "@";
				break;
			}*/
			else { std::cout << ' '; }
		}
		std::cout << "#\n";
	}
	std::cout << "\n Current score: \t" << score;
}
