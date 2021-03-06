#include<iostream>
using namespace std;

//select grid size
const int maxrow = 20, maxcol = 60;

class Life
{
public:
	void intialize();
	void print();
	void update();
	void instructions();
private:
	int grid[maxrow + 2][maxcol + 2];
	int neighbor_count(int row, int col);
};

int Life::neighbor_count(int row, int col)
{
	int i, j;
	int count = 0;
	for (i = row - 1; i <= row + 1; i++)
		for (j = col - 1; j <= col + 1; j++)
			count += grid[i][j];
	count -= grid[row][col];

	return count;
}

void Life::update()
{
	int row, col;
	int new_grid[maxrow + 2][maxcol + 2];
	for (row = 1; row <= maxrow; row++)
		for (col = 1; col <= maxcol; col++)
			switch (neighbor_count(row, col))
			{
			case 2:
				new_grid[row][col] = grid[row][col];
				break;
			case 3:
				new_grid[row][col] = 1;
				break;
			default:
				new_grid[row][col] = 0;
			}
	for (row = 1; row <= maxrow; row++)
		for (col = 1; col <= maxcol; col++)
			grid[row][col] = new_grid[row][col];
}

void Life::intialize()
{
	int row, col;
	for (row = 0; row <= maxrow + 1; row++)
		for (col = 0; col <= maxcol + 1; col++)
			grid[row][col] = 0;
	cout << "List the coordinates for living cells." << endl;
	cout << "Terminate the list with the special pair -1 -1" << endl;
	cout << "Enter row ";
	cin >> row;
	cout << "Enter column ";
	cin >> col;
	while (row != -1 || col != -1)
	{
		if (row >= 1 && row <= maxrow)
			if (col >= 1 && col <= maxcol)
				grid[row][col] = 1;
			else
				cout << "Column " << col << " is out of range." << endl;
		else
			cout << "Row " << row << " is out of range." << endl;
		cout << "Enter row ";
		cin >> row;
		cout << "Enter column ";
		cin >> col;
	}
}

void Life::print()
{
	int row, col;
	cout << "\nThe current Life configuration is:" << endl;
	for (row = 1; row <= maxrow; row++)
	{
		for (col = 1; col <= maxcol; col++)
			if (grid[row][col] == 1)
				cout << '*';
			else
				cout << ' ';
		cout << endl;
	}
	cout << endl;
}

void Life::instructions()
{
	cout << "Welcome to Conway's game of Life." << endl;
	cout << "This game uses a grid of size "
		<< maxrow << " by " << maxcol << " in which" << endl;
	cout << "each cell can either be occupied by an organism or not." << endl;
	cout << "The occupied cells change from generation to generation" << endl;
	cout << "according to the number of neighboring cells which are alive."
		<< endl;
}