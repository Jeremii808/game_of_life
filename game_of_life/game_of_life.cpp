#include"life.h"
#include<iostream>
using namespace std;

bool user_says_yes();

int main()
{

	Life configuration;
	configuration.instructions();
	configuration.intialize();
	configuration.print();
	cout << "Continue viewing new generations? " << endl;
	while (user_says_yes())
	{
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations? " << endl;
	}

	system("pause");
	return 0;
}

bool user_says_yes()
{
	int c;
	bool intial_response = true;
	do
	{
		if (intial_response)
			cout << "(y,n)?" << flush;
		else
			cout << "Respond with either y or n: " << flush;
		do
		{
			c = cin.get();
		} while (c == '\n' || c == ' ' || c == '\t');
		intial_response = false;
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	return(c == 'y' || c == 'Y');
}
