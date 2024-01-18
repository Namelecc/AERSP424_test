#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <regex>

using namespace std;

ifstream inFile("datafile.txt"); //inputs 
void numSearch(string base, int& min, int& max);

void main()
{
	int cumsum = 0;
	string line;
	while (getline(inFile, line))
	{
		int left_num, right_num;
		cout << line << endl;
		numSearch(line, left_num, right_num);

		cout << left_num << " " << right_num << endl;
		cout << left_num * 10 + right_num << "\n" << endl;
		cumsum += left_num * 10 + right_num;
			
	}
	inFile.close();
	cout << "Total sum: " << cumsum << endl;
}



void numSearch(string base, int& min, int& max)
{
	string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	bool first = false;


	for (int pos = 0; pos < base.length(); pos++)
	{
		char thischar = base[pos];

		if (isdigit(thischar))
		{
			max = thischar - '0';

			if (first == false)
			{
				min = thischar - '0';
				first = true;
			}
		}
		else
		{
			for (int num = 0; num < 10; num++)
			{
				int small_net = 3;
				string small_string = base.substr(pos, small_net);
				size_t index_small = small_string.find(numbers[num]);
				if (index_small != string::npos)
				{
					max = num;
					if (first == false)
					{
						min = num;
						first = true;
					}
				}
			}
			for (int num = 0; num < 10; num++)
			{
				int big_net = 5;
				string big_string = base.substr(pos, big_net);
				size_t index_big = big_string.find(numbers[num]);
				if (index_big != string::npos)
				{
					max = num;

					if (first == false)
					{
						min = num;
						first = true;
					}
				}

			}

		}
	}
}
	



	
