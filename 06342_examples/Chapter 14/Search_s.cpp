// Name : Search_s.cpp
// 循序搜尋

#include <iostream>
#include <cstdlib>
using namespace std;

template <class Type>
class Sequential {
	private:
		Type input;
	public:
		void sequential_search(Type data[]);
};

template <class Type>
void Sequential<Type>::sequential_search(Type data[])
{
	int i;

	cout << "\n<< Squential search >>\n";
	cout << "\nData: ";
	for(i = 0; i < 10; i++)
		cout << data[i] << "  ";
	cout << "\n";
	cout << "\nPlease enter a number from data: ";
	cin >> input;
	cout << "\nSearch.....\n";
	for(i = 0; i < 10; i++) { // 依序搜尋資料
		cout << "\nData when searching ";
		cout.width(2);
		cout << "#" << i+1 << " time(s) is " << data[i];
		if(input == data[i]) break;
	}
	if(i == 10)
		cout << "\n\nSorry, " << input << " not found !";
	else
		cout << "\n\nFound, " << input << " is the " << i+1
				<< "th record in data !";
}

int main()
{
	Sequential<int> obj;
	int data[10] = {75, 23, 98, 44, 57, 12, 29, 64, 38, 82};

	obj.sequential_search(data);
	system("PAUSE");
	return 0;
}

