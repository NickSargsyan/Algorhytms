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

	if (length > 64)
	{
		//If there is more then 64 bit binary number givem

		cout << "An overflow occures!\n";

		return 0;
	}

	//Starting the convertion

	for (int i = 0 ; i < length ; i++)
	{
		if (argv[1][i] == '1')
		{
			//If there is binary one written on position
			//Shifting "decimal" left by one position
			//And adding one
			decimal = decimal << 1;
			decimal = decimal + 1;
		}
		else if (argv[1][i] == '0')
		{
			//If there is binary zero written on position
			//Only shifting "decimal" left by one position
			decimal = decimal << 1;
		}
		else
		{
			//If there is none 0 neither 1 in position, string is not valid

			cout << "String is not a valid binary number!\n";

			return 0;
		}
	}

	//Printing the answer
	cout << decimal << "\n";

	return 0;
}