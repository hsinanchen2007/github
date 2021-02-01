// 10_p360.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <fstream>  
#include <string>  
#include <sstream>  
#include <cctype>  

#include "dictionary.h"  

using namespace std;

void lower(string& s);
string strip_punct(const string& s);
void check_spelling(ifstream& in, Dictionary& dict);

void spellSuggestionOne(Dictionary& dict, const string& word);
void spellSuggestionTwo(Dictionary& dict, const string& word);
void spellSuggestionThr(Dictionary& dict, const string& word);
void spellSuggestionFou(Dictionary& dict, const string& word);

void main() {

	ifstream inf("test.txt");
	if (!inf) {
		cerr << "讀取檔案失敗，請確認後重試！" << endl;
		return;
	}

	cout << "字典載入中，此過程可能需要幾分鐘…" << endl;

	Dictionary d("wordlist.txt");

	check_spelling(inf, d);

	inf.close();

	cout << endl << endl;
	system("PAUSE");
}

void check_spelling(ifstream& in, Dictionary& dict) {

	int line_number = 0;

	while (in) {

		line_number++;

		string line;
		getline(in, line);

		stringstream ss(stringstream::in | stringstream::out);
		ss << line;

		string word;
		while (ss >> word) {

			word = strip_punct(word);
			lower(word);

			if (!dict.search(word))
			{
				cout << "line " << line_number << ":    \'" << word << "\'" << endl;
				cout << "\tsuggestions:" << endl;

				spellSuggestionOne(dict, word);
				spellSuggestionTwo(dict, word);
				spellSuggestionThr(dict, word);
				spellSuggestionFou(dict, word);
			}
		}
	}
}

void lower(string& s) {

	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}

string strip_punct(const string& s) {

	if (ispunct(s[s.length() - 1])) {
		return s.substr(0, s.length() - 1);
	}
	else {
		return s;
	}
}

void spellSuggestionOne(Dictionary &dict, const string& word)
{
	string temp = "";
	string foregoing = "";

	for (int i = 0; i<word.size(); i++) {

		temp = word;
		//交換相鄰字母
		char tempChar = temp[i];
		temp[i] = temp[i + 1];
		temp[i + 1] = tempChar;

		if (dict.search(temp) && temp != foregoing)
		{
			foregoing = temp;
			cout << "\t\t" << temp << endl;
		}
	}
}

void spellSuggestionTwo(Dictionary& dict, const string& word)
{
	string temp = "";
	string foregoing = "";

	for (int i = 0; i<word.size(); i++)
	{
		temp = word;
		//刪除一個字母
		temp.erase(i, 1);

		if (dict.search(temp) && temp != foregoing)
		{
			foregoing = temp;
			cout << "\t\t" << temp << endl;
		}
	}
}

void spellSuggestionThr(Dictionary& dict, const string& word)
{
	string temp = "";
	string foregoing = "";
	string str = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i<word.size(); i++)
	{
		temp = word;
		for (int j = 0; j<26; j++)
		{
			temp = word;
			temp.replace(i, 1, str.substr(j, 1));
			if (dict.search(temp) && temp != foregoing)
			{
				foregoing = temp;
				cout << "\t\t" << temp << endl;
			}
		}
	}
}

void spellSuggestionFou(Dictionary& dict, const string& word)
{
	string temp = "";
	string foregoing = "";
	string str = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i<word.size(); i++)
	{
		temp = word;
		for (int j = 0; j<26; j++)
		{
			temp = word;
			temp.insert(i, str.substr(j, 1));
			if (dict.search(temp) && temp != foregoing)
			{
				foregoing = temp;
				cout << "\t\t" << temp << endl;
			}
		}
	}
}
