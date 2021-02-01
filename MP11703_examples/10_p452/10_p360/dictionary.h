#pragma once
#ifndef  _DICTIONARY_H_   
#define  _DICTIONARY_H_  

#include <iostream>  
#include <vector>  
#include <list>  
#include <algorithm>  
#include <string>  
#include <cstdlib>  
#include <fstream>  

#include  "hashset.h"  
#include  "hashset.cpp"  

using namespace std;

//Âø´ê¨ç¼Æ
class hash_function
{
public:
	hash_function() {}

	unsigned int operator()(const string& s)  const {

		unsigned int res = 0;
		for (int i = 0; i<s.size(); i++)
		{
			res = res * 1000 + s[i];
		}
		return res;

	}
};

class equality
{
public:
	equality() {}
	bool  operator()(const string& A, const string& B)  const {
		return  (A == B);
	}
};

//¦r¨åÃþ§O
class Dictionary : public HashSet<string, hash_function, equality> {

protected:
	ifstream infile;
public:
	Dictionary(const string &filename) {

		infile.open(filename.c_str());

		if (!infile) {
			cerr << "cannot open " << filename << " for input" << endl;
			return;
		}

		string line = "";

		while (getline(infile, line)) {

			insert(line);
		}
		infile.close();

	}
};

#endif  
