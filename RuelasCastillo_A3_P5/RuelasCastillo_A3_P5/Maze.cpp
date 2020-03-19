#include "Maze.h"
#include<iostream>
Maze::Maze()
{ }
void Maze::addToArrays(int x[], int y[], int& numEntries, int xVal, int yVal)
{
	x[numEntries] = xVal;
	y[numEntries] = yVal;
	numEntries++;
}

bool Maze::move(char maze[][WIDTH], bool visited[][WIDTH],int& curX, int& curY, int newX, int newY)
{
	bool foundExit = false;
	if (maze[newY][newX] == 'E') 	// Check for exit
		foundExit = true;
	curX = newX;			// Update location
	curY = newY;
	visited[curY][curX] = true;

	return foundExit;
}

void Maze::printMaze(char maze[][WIDTH], int curx, int cury)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((x == curx) && (y == cury))
				std::cout << "@";
			else
				std::cout << maze[y][x];
		}
		std::cout << std::endl;
	}
}
bool Maze::search(char maze[][WIDTH], bool visited[][WIDTH], int x, int y,
	int solutionX[], int solutionY[], int& numEntries)
{
	bool foundExit = false;

	if (maze[y][x] == 'E')
		return true;
	visited[y][x] = true;
	if (validMove(maze, visited, x, y - 1))
		foundExit = search(maze, visited, x, y - 1, solutionX, solutionY, numEntries);
	if (!foundExit && (validMove(maze, visited, x, y + 1)))
		foundExit = search(maze, visited, x, y + 1, solutionX, solutionY, numEntries);
	if (!foundExit && (validMove(maze, visited, x - 1, y)))
		foundExit = search(maze, visited, x - 1, y, solutionX, solutionY, numEntries);
	if (!foundExit && (validMove(maze, visited, x + 1, y)))
		foundExit = search(maze, visited, x + 1, y, solutionX, solutionY, numEntries);

	if (foundExit)
	{
		// Remember coordinates we found the exit in the solution arrays
		addToArrays(solutionX, solutionY, numEntries, x, y);
		return true;
	}
	return false;
}
bool  Maze::validMove(char maze[][WIDTH], bool visited[][WIDTH],
	int newX, int newY)
{
	// Check for going off the maze edges
	if (newX < 0 || newX >= WIDTH)
		return false;
	if (newY < 0 || newY >= HEIGHT)
		return false;
	// Check if target is a wall
	if (maze[newY][newX] == 'X')
		return false;
	// Check if visited
	if (visited[newY][newX])
		return false;
	return true;
}
int Maze::getHeight()
{
	return this->HEIGHT;
}
int Maze::getWidth()
{
	return this->WIDTH;
}