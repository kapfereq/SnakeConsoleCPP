#pragma once
#include "snake.h"
#include <vector>
#include <algorithm>

// Move the snake in its curremt direction
void snake::MoveSnake()
{
    // Store the current position of the head
    int prev_x = SnakeBody[0].first;
    int prev_y = SnakeBody[0].second;
    int next_x, next_y;

    // Move the head in the current direction
    switch (SnakeDirection) {
    case 'w': prev_x += -1; break;
    case 'a': prev_y += -1; break;
    case 's': prev_x += 1; break;
    case 'd': prev_y += 1; break;
    }

    SnakeBody[0].first = prev_x;
    SnakeBody[0].second = prev_y;

    // Move the rest of the segments to the position of the segment in front of them
    for (size_t i = 1; i < SnakeBody.size(); ++i) {
        next_x = SnakeBody[i].first;
        next_y = SnakeBody[i].second;
        SnakeBody[i].first = prev_x;
        SnakeBody[i].second = prev_y;
        prev_x = next_x;
        prev_y = next_y;
    }
}

// Change the direction the snake is heading
void snake::ChangeDirection(char Key)
{
	switch (Key) {
	case 'w':
        if(SnakeDirection != 's')
            SnakeDirection = 'w'; break;
	case 'a':
        if(SnakeDirection != 'd')
            SnakeDirection = 'a'; break;
	case 's':
        if (SnakeDirection != 'w')
            SnakeDirection = 's'; break;
	case 'd':
        if (SnakeDirection != 'a')
            SnakeDirection = 'd'; break;
	}
}

// Add segment to snake after eating food

void snake::AddSegment() {
    // ... (rest of the code)
    // 
    // Get the current tail position
    int tailY = SnakeBody.back().first;
    int tailX = SnakeBody.back().second;

    // Calculate new head position based on direction
    int newX = tailX, newY = tailY;
    switch (SnakeDirection) {
    case 'w':
        newY--; // Move up one position
        break;
    case 'a':
        newX++; // Move left one position
        break;
    case 's':
        newY++; // Move down one position
        break;
    case 'd':
        newX--; // Move right one position
        break;
    }
    // Add the new head segment with the calculated coordinates
    SnakeBody.push_back(std::make_pair(newX, newY));
}

bool snake::checkCollision()
{
    // Check collision with walls
    if ((SnakeBody[0].first == globals::c_Height - 1 && SnakeBody[0].second == globals::c_Width - 2)
        || (SnakeBody[0].first == 0 || SnakeBody[0].second == 0))
        return true;
    // Check collision with snake body
    else if (std::any_of(SnakeBody.begin() + 1, SnakeBody.end(), // Start from 2nd element
        [this](const auto& segment) {
            return segment.first == SnakeBody[0].first &&
                segment.second == SnakeBody[0].second;
        })) {
        return true; // Collision with body detected
    }

    // No collision detected
    return false;
}

