//Main.cpp
//12.9.18
//Lab9
//Jacob Silva
//COSC 2030

#include "stdafx.h"
#include<map>
using std::map;
using std::pair;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ofstream;
using std::ifstream;

#include <string>
using std::string;
using std::to_string;

map<string,int> readFile(string fileName)  //this function reads words from a file, and stores them in a map
										   // which is then returned;
{										   // recieved help from https://azrael.digipen.edu/~mmead/www/Courses/CS225/Maps-Example-1.html
	string line;
	ifstream inFile;
	typedef map<string, int> map1;
	map1 wordFinder;
	inFile.open(fileName);
	if (inFile.is_open())
	{
		while (inFile>>line)
		{
			map1::iterator it = wordFinder.find(line);
			if (it != wordFinder.end())
			{
				it->second++;
			}
			else
			{
				pair<string, int> pair1(line, 1);
				wordFinder.insert(pair1);
			}
		}
		inFile.close();
		return wordFinder;
	}
	else
		cout << "File Unavalible";
	return wordFinder;

}

void writeFile(string fileName,string input)
{
	
	ofstream inFile;
	inFile.open(fileName,std::fstream::app);
	if (inFile.is_open())
	{
		
		
			inFile << input << "  ";
			inFile.close();
	}
	else
		cout << "File unavalible";


}

int main()
{
	map<string, int> map1;
	string input;
	cout << "Please Enter a Filename to be read: ";
	cin >> input;
	map1 =readFile(input);
	cout << "Succsess, now please enter a ouput filenmae: ";
	cin >> input;
	
	for (map<string, int> ::iterator it = map1.begin(); it != map1.end(); it++)
	{
		//string number = to_string(it->second); //this output would print number of tallys of the string then the string itself
		//writeFile(input, number);
		int i = 0;
		while (i < it->second) //this loop prints the correct number of strings so if to appears 5 timses, to is written 5 times
		{
			writeFile(input, it->first);
			i++;
		}
	
	}
	
	
    return 0;
}

