// 10_p351_1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <string>  
#include <iomanip>  
#include <stdint.h>  

using namespace std;

#define HASHSIZE 101  


string keywords[] = {
	"auto",   "break",  "case",     "char",   "const",    "continue", "default",  "do",
	"double", "else",   "enum",     "extern", "float",    "for",      "goto",     "if",
	"int",    "long",   "register", "return", "short",    "signed",   "sizeof",   "static",
	"struct", "switch", "typedef",  "union",  "unsigned", "void",     "volatile", "while"
};

unsigned long BKDRHash(const string& str)
{
	unsigned long seed = 31;
	unsigned long hashval = 0;

	for (int i = 0; i < str.length(); i++)
		hashval = hashval * seed + str[i];
	return hashval % HASHSIZE;
}


int main(int argc, char** argv) {

	int size, pos;
	int count[HASHSIZE];

	for (int i = 0; i < HASHSIZE; i++)
		count[i] = 0;

	size = sizeof(keywords) / sizeof(keywords[0]);
	for (int i = 0; i < size; i++)
		count[BKDRHash(keywords[i])]++;

	for (int i = 0; i < size; i++) {
		pos = BKDRHash(keywords[i]);
		cout << setw(8) << keywords[i] << setw(5) << pos << setw(5) << count[pos] << endl;
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
