// Name : Search_b.cpp
// 二元搜尋

#include <iostream>
#include <cstdlib>
using namespace std;

template <class Type>
class Binary {
	private:
		Type input;
	public:
		void binary_search(Type data[]);
};

template <class Type>
void Binary<Type>::binary_search(Type data[])
{
	int i, l = 1, n = 10, m, cnt = 0, ok = 0;

	cout << "\n<< Binary search >>\n";
	cout << "\nSorted data: ";
	for(i = 1; i < 11; i++)
		cout << data[i] << "  ";
	cout << "\n";
	cout << "\nPlease enter a number from data: ";
	cin >> input;
	cout << "\nSearch.....\n";
	m = (l + n) / 2;     // 鍵值在第M筆
	while(l <= n && ok == 0) {
		cout << "\nData when searching ";
		cout.width(2);
		cout << "#" << ++cnt << " time(s) is " << data[m] << " !";
		if(data[m] > input) { // 欲搜尋的資料小於鍵值，則資料在鍵值的前面
			n = m - 1;
			cout << " ---> Choice number is smaller than " << data[m];
		}
		else if(data[m] < input) {  // 否則資料在鍵值的後面
				l = m + 1;
				cout << " ---> Choice number is bigger than " << data[m];
			}
		else {
			cout << "\n\nFound, " << input << " is the " << m << 
"th record in data !";
			ok = 1;
		}
		m = (l + n)/2;
	}
	if(ok == 0)
		cout << "\n\nSorry, " << input << " not found !";
}

int main()
{
	Binary<int> obj;
	int data[11] = {0, 12, 23, 29, 38, 44, 57, 64, 75, 82, 98};

	obj.binary_search(data);
	system("PAUSE");
	return 0;
}

