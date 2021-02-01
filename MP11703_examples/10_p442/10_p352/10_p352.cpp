// 10_p352.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <string>  
#include <iomanip>  
#include <stdint.h>  

using namespace std;

//const long offsetbasis32 = 2166136261;  
#define FNV_32_INIT ((uint32_t)0x811c9dc5)  
//const long FNVprime32 = 16777619;  
#define FNV_32_PRIME ((uint32_t)0x01000193)  

unsigned long FNV1a_32_Hash(const string& str)
{
	unsigned long hashval = FNV_32_INIT;
	for (int i = 0; i < str.length(); i++)
	{
		hashval = hashval ^ str[i];
		// hashval = hashval * FNV_32_PRIME;  
		// 以上程式等價於下面之面之位操作   
		hashval += (hashval << 1) + (hashval << 4)
			+ (hashval << 7) + (hashval << 8) + (hashval << 24);

	}
	return hashval;
}

//const long offsetbasis64 = 14695981039346656037;  
//#define FNV_64_INIT ((uint64_t)0x14650FB0739D0383);  
#define FNV_64_INIT ((uint64_t)0xcbf29ce484222325ULL);  
//const long FNVprime64 = 1099511628211;  
#define FNV_64_PRIME ((uint64_t)0x100000001b3ULL)  

uint64_t FNV1a_64_Hash(const char* bp, size_t len)
{
	uint64_t hval = FNV_64_INIT;
	const char *be = bp + len;
	while (bp < be) {
		hval ^= (uint64_t)*bp++;
		hval += (hval << 1) + (hval << 4) + (hval << 5) + (hval << 7) + (hval << 8) + (hval << 40);
	}
	return hval;
}

int main(int argc, char** argv) {

	string str = "interesting";
	cout << hex << FNV1a_32_Hash(str) << endl;
	cout << hex << FNV1a_64_Hash(str.c_str(), str.length()) << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
