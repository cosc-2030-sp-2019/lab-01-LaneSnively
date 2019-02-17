//NumberProcess.cpp
//Lane Snively
//shows count of numbers in a file
//shows the first, penultimate, last numbers from a file
//lab01: part 1 of 2
//HELP STATEMENT: c++ reference, my old cosc1030 c++ work

#include <iostream>
#include <fstream>
#include <string>	
using namespace std;

string getInput(void);

int main() {
	string fileName = getInput();
	ifstream inFile;
	inFile.open(fileName);
	//checks if the file will open, closes program if it doesn't
	if (!inFile.is_open()) {
		cout << "File didn't open. You suck at programming." << endl;
		system("pause");
		exit(0);
	}

	int x=0, first, penultimate = 0, last = 0, count = 0;
	//get the first, penultimate, last number in the file
	//makes two passes over the file: first & last in first pass, penultimate in second pass
	inFile >> first;
	while (!inFile.eof()) {
		inFile >> last;
		count++;
	}
	inFile.close();
	inFile.open(fileName);
	while (x < (count-1)) {
		inFile >> penultimate;
		x++;
	}
	inFile.close();

	//prints the first, penultimate, last number in the file
	cout << endl;
	cout << "count of numbers in the file: " << count << endl;
	cout << "first number in the file: " << first << endl;
	cout << "penultimate number in the file: " << penultimate << endl;
	cout << "last number in the file: " << last << endl;
	system("pause");
	return 0;
}

//gets the file name from the user
string getInput(void) {
	string fileName, which;
	cout << "enter a for file1, enter b for file2, enter c for file3" << endl;
	cin >> which;
	if (which == "a")
		fileName = "NumFile1.txt";
	else if (which == "b")
		fileName = "NumFile2.txt";
	else if (which == "c")
		fileName = "NumFile3.txt";
	else
		fileName = which;
	return fileName;
}