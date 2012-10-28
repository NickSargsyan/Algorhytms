#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

long long StringToInt(char* string)
{
	//geting lenght of the string
	int length = strlen(string);

	//long long type provides 64 bit of data
	long long decimal = 0;

	//Strating the convertion

	for (int i = 0 ; i < length ; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			//If there is a number in position

			decimal = decimal * 10 + (string[i] - '0'); 
		}
		else
		{
			//If there is non-number symbol in position
			
			cout << "StringToInt: String is not a valid decimal number!\n";

			return 0;
		}
	}

	return decimal;
}

int main(int argc , char* argv[])
{
	if (argc == 1)
	{
		//If now input data is given

		cout << "Number of lines is not given!\n";

		return 0;
	}

	//Getting number of lines to print
	long long n = StringToInt(argv[1]);

	//Queue, where current line will stored
	queue<long long> Q;

	//first line is '1'
	Q.push(1);

	//Printing Pascal Triangle

	for (int i = 1 ; i <= n ; i++)
	{
		//Variable to store upleft number of current position in Pascal Triangle
		//It is 0 for first position in the line
		long long upleft = 0;

		//Printing current line and counting new one

		for (int j = i ; j > 0 ; j--)
		{
			//Printing cuurent position
			cout << Q.front() << " ";

			//Counting number under current position and pushing it into queue
			//Upleft for new number is the previous position, or 0, if the position is the first
			Q.push(upleft + Q.front());

			//Geting upleft for next position
			upleft = Q.front();

			//Poping printed number from queue
			Q.pop();
		}

		//Last position in line gets value of one all the time
		//It is not counted in cycle above, so it is add now
		Q.push(1);

		//Passing to new line 
		cout << endl;
	}

	return 0;
}