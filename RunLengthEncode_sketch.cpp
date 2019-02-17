//Lane Snively
// RunLengthEncode.cpp
//lab01: part 2 of 2
//read data from PixData.txt, compress it, insert it into a new file
//HELP STATEMENT: c++ reference, my old cosc1030 c++ work

//#include "stdafx.h"
// CPP program to implement run length encoding
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line;
	string whitespace(" \t\f\v\n\r");
	vector<string> pix_list;
	int i, count, n;
	ifstream pixf_full;
	pixf_full.open("PixData.txt");
	ofstream pixf_cmpr;
	pixf_cmpr.open("PixCmprs.txt");
	if (pixf_full.is_open()) cout << "Input pixData is open.";
	i = 0;
	// Read data from PixData.txt into pix_list.
	//p1. complete parameters for the loop
	while (getline(pixf_full, line))
	{
		cout << i << " " << line << '\n'; //I added an index so I can tell that it's working correctly
		// p2.  (Explain statement below.)
		pix_list.push_back(line); //p2: insert the entire string, "line", as the next element in vector "pix_list"
		i++;
	}
	n = pix_list.size();
	//Test the count of pixels against the size of the array, using an array method, writing the test result to stdout
	cout << "Length of pix_list is " << n << " ; i = " << i << "\n";
	// Go through list, testing whether next pixel is the same.
	//3. complete parameters for the loop
	for (i = 0; i<pix_list.size(); i++) //I don't want to use n. pix_list.size() is descriptive so it's easy to read.
	{
		//4. complete conditions for the if statement
		if (pix_list[i + 1] != pix_list[i])
			pixf_cmpr << "11111111 " << pix_list[i];
		else
		{
			// Pixels same.
			// 1. Write flag character and repeated pixel.  Strip pesky newline at end.
			pixf_cmpr << "00000000 " << pix_list[i].substr(0, pix_list[i].find_last_not_of(whitespace));
			// 5. (Explain loop below.)
			// loop increments i and count without inserting a value into pixf_cmpr. ignores repeated values in pix_list essentially
			count = 1;
			while (i < n - 1 && pix_list[i] == pix_list[i + 1])
			{
				count++;
				i++;
			}
			// Different pixel or end of file encountered.
			// Write output to file.
			pixf_cmpr << " " << count << "\n";
		}
	}
	system("pause");
	return 0;
}