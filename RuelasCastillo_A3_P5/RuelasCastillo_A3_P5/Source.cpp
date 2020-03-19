//ISAAC RUELAS CASTILLO ASSIGNMENT 3 PROBLEM 5
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Maze.h"
using namespace std;

int main()
{
	int const HEIGHT = 20;
	int const WIDTH = 20;
	Maze call;
	char maze[HEIGHT][WIDTH];
	bool visited[HEIGHT][WIDTH];

	// Seed random number generator with clock time
	srand(time(NULL));

	/****************
	 Programmatically fill out the maze with ***'s on the borders and spaces in the middle
	 ****************/
	 // All blank
	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGHT; y++)
			maze[y][x] = ' ';
	// Borders with X
	for (int x = 0; x < WIDTH; x++)
	{
		maze[0][x] = 'X';
		maze[HEIGHT - 1][x] = 'X';
	}
	for (int y = 0; y < HEIGHT; y++)
	{
		maze[y][0] = 'X';
		maze[y][WIDTH - 1] = 'X';
	}

	// ***** Randomly fill in 25% of the middle
	int numCells = static_cast<int>((HEIGHT - 2) * (WIDTH - 2) * 0.25);
	int count = 0;
	while (count < numCells)
	{
		int x = (rand() % (WIDTH - 2)) + 1;
		int y = (rand() % (HEIGHT - 2)) + 1;
		if (maze[y][x] == ' ')
		{
			maze[y][x] = 'X';
			count++;
		}
	}

	// ***** Pick a random start and end that is not a wall *****
	int x = (rand() % (WIDTH - 2)) + 1;
	int y = (rand() % (HEIGHT - 2)) + 1;
	while (maze[y][x] == 'X')
	{
		x = (rand() % (WIDTH - 2)) + 1;
		y = (rand() % (HEIGHT - 2)) + 1;
	}
	// At this point, (x,y) contains our start position
	// ***** Pick a random end position that is not a wall *******
	int exitX = (rand() % (WIDTH - 2)) + 1;
	int exitY = (rand() % (HEIGHT - 2)) + 1;
	while (maze[exitY][exitX] == 'X')
	{
		exitX = (rand() % (WIDTH - 2)) + 1;
		exitY = (rand() % (HEIGHT - 2)) + 1;
	}
	maze[exitY][exitX] = 'E';

	// Initialize visited locations to false
	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGHT; y++)
			visited[y][x] = false;
	visited[y][x] = true;

	// Here I created arrays to store the x/y coordinates for the path of our solution.
	// The array is of size [HEIGHT-2]*[WIDTH-2] since we'll never exceed that size.
	// I also made a variable to count how many entries we make..
	// It would probably be more convenient to make a class to store this data rather than
	// have two separate arrays!
	int solutionX[(HEIGHT - 2) * (WIDTH - 2)], solutionY[(HEIGHT - 2) * (WIDTH - 2)];
	int numPoints = 0;

	//bool found = search(maze, visited, x, y, solutionX, solutionY, numPoints);
	bool found = call.search(maze, visited, x, y, solutionX, solutionY, numPoints);
	if (!found)
		cout << "No solution found.";
	else
	{
		cout << "Solution found!  Here is the path from the start." << endl;
		for (int i = numPoints - 1; i >= 0; i--)
		{
			//printMaze(maze, solutionX[i], solutionY[i]);
			call.printMaze(maze, solutionX[i], solutionY[i]);
			cout << endl;
		}
	}
}