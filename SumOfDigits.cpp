#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
 * Function Name:	ParseInput
 * Description:		Parses the input string into individual integers
 */
vector<int> ParseInput(string s)
{
	vector<int> inputDigits;
	
	// using a single digit char array to allow me to use atoi in the loop below
	char digit[1];
	
	for(unsigned int index = 0; index < s.size(); ++index)
	{
		if(isdigit(s[index]))
		{
			digit[0] = s[index];
			
			inputDigits.push_back(atoi(digit));
		}
	}
	
	return inputDigits;
}

/*
 * Function Name:	AddInput
 * Description:		Adds the elements of the input vector
 */
int AddInput(vector<int> input)
{
	int sum = 0;
	
	for(unsigned int index = 0; index < input.size(); ++index)
	{
		sum = sum + input[index];
	}
	
	return sum;
}

int main(int argc, char *argv[])
{
	ifstream inputFileStream(argv[1]);
	
	int sum = 0;
	
	vector<int> inputDigits;
	
	string inputString;
	
	if(inputFileStream.is_open() == false)
	{
		cout << "Error with input file." << endl;
	}
	else
	{
		while(getline(inputFileStream,inputString))
		{
			sum = 0;
			
			inputDigits = ParseInput(inputString);
			
			sum = AddInput(inputDigits);
			
			cout << sum << endl;
		}
	}

	return 0;
}