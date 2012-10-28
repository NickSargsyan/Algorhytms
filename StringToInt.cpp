#include <cstring>
#include <iostream>
using namespace std;

int main(int argc , char* argv[])
{
	if (argc == 1)
	{
		//If now input data is given

		cout << "Now string to convert is given!\n";

		return 0;
	}

	//geting lenght of the string
	int length = strlen(argv[1]);

	//long long type provides 64 bit of data
	long long decimal = 0;

	//Strating the convertion

	for (int i = 0 ; i < length ; i++)
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			//If there is a number in position

			decimal = decimal * 10 + (argv[1][i] - '0'); 
		}
		else
		{
			//If there is non-number symbol in position
			
			cout << "String is not a valid decimal number!\n";

			return 0;
		}
	}

	//Printing the answer
	cout << decimal << "\n";

	return 0;
}