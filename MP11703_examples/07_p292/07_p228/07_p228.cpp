// 07_p228.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <map>  
#include <string>  
#include <iostream>  

using namespace std;

int main()
{
	map<string, string> writer;

	writer["Shakespeare"] = "English writer, his works include 'Hamlet', 'Othello', and 'King Lear', etc.";
	writer["Tagore"] = "India writer, his works include 'Gitanjali', etc.";
	writer["Tolstoy"] = "Russian writer, his works include 'War and Peace', and 'Anna Karenina', etc.";
	writer["Andersen"] = "Danish writer, his works include 'The Ugly Duckling', etc.";
	writer["Dumas"] = "French writer, his works include 'The Count of Monte Cristo', and 'The Three Musketeers', etc.";

	cout << writer.size() << endl << endl;

	int i = 1;

	map<string, string>::iterator it = writer.begin();
	for (; it != writer.end(); it++)
	{
		cout << i << " : ";
		cout << it->first << ": " << it->second << endl;
		i++;
	}

	cout << endl;
	cout << (writer.find("Tagore"))->second << endl << endl;

	writer.erase(writer.find("Tagore"));
	cout << writer.size() << endl << endl;

	writer.clear();
	cout << writer.size() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
