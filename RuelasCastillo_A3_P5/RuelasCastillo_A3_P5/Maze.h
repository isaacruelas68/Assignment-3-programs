#pragma once

class Maze
{
private:
	 int static const WIDTH = 20;
	 int static const HEIGHT = 20;
public:
	Maze();
	void printMaze(char maze[][WIDTH], int curx, int cury);
	bool validMove(char maze[][WIDTH], bool visited[][WIDTH],
		int newX, int newY);
	bool move(char maze[][WIDTH], bool visited[][WIDTH],
		int& curX, int& curY, int newX, int newY);
	// *** search has new parameters to remember the coordinates of the solution we find
	bool search(char maze[][WIDTH], bool visited[][WIDTH], int x, int y, 
		int solutionX[], int solutionY[], int& numEntries);
	// *** New function, see below
	void addToArrays(int x[], int y[], int& numEntries, int xVal, int yVal);
	int getWidth();
	int getHeight();
};

