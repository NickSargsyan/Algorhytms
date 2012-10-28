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

	//Getting number of steps to print
	long long n = StringToInt(argv[1]);

	//prevprev is value of position before previous position
	long long prevprev = 0;

	//prev is value of previous position
	long long prev = 1;

	//current is value of current position
	long long current;

	//if n is not a zero, print the value of first position, it is out of counting cycle
	if (n > 0)
	{
		cout << 1 << " ";

		n--;
	}

	//start printing fron second position
	for (n ; n > 0 ; n--)
	{
		//Current value is sum previous value and value before previous value
		current = prevprev + prev;

		//Printing current value
		cout << current << " ";

		//Previous value becomes value before previous for next position
		//Current value becomes previous for next position
		prevprev = prev;
		prev = current;
	}

	cout << endl;

	return 0;
}