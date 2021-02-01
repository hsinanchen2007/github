// Name : Heaptree.cpp
// 利用堆積樹(HEAP TREE)處理會員進出資料—新增、刪除、輸出

#include <iostream>
#include <stdlib.h>
#define MAX 100  // 設定上限

using namespace std;

class heaptree {
	private:
int heap_tree[MAX];    // 堆積樹陣列
int last_index;        // 最後一筆資料的INDEX
	public:
heaptree();
void insert_f(void);   // 插入函數
void delete_f(void);   // 刪除函數
void display_f(void);  // 輸出函數
void create(int id_number);      // 建立資料於堆積樹
void removes(int index_temp); // 從堆積樹中刪除資料
void show(char op);             // 印出資料於螢幕
void adjust_u(int temp[], int index);  // 從下而上調整資料
void adjust_d(int temp[], int index1, int index2); // 從上而下調整資料
void exchange(int *id1, int *id2);      // 交換資料
int search(int id_number);   // 搜尋資料
};

heaptree::heaptree()
{
	last_index = 0;
}

void heaptree::insert_f(void)
{
	int id_number;
	if(last_index >= MAX) {  // 資料數超過上限，顯示錯誤訊息
		cout << " Login members are more than " << MAX << "!!\n";
		cout << " Please wait for a minute!!\n";
	}
	else {
		cout << " Please enter login ID number: ";
		cin >> id_number;
		create(id_number);  // 建立堆積
		cout << " Login successfully!!\n";
	}
}

void heaptree::delete_f(void)
{
	int id_number, del_index;
	if(last_index < 1) {  // 無資料存在，顯示錯誤訊息
		cout << " No member to logout!!\n";
		cout << " Please check again!!\n";
	}
	else {
		cout << " Please enter logout ID number: ";
		cin >> id_number;
		del_index = search(id_number);  // 尋找欲刪除資料
		if(del_index == 0)  // 沒找到資料，顯示錯誤訊息
			cout << " ID number not found!!\n";
		else {
			removes(del_index);  // 刪除資料，並調整堆積樹
			cout << " ID number " << id_number << " logout!!\n";
		}
	}
}

void heaptree::display_f(void)
{
	char option;

	if(last_index < 1)  // 無資料存在，顯示錯誤訊息
		cout << " No member to show!!\n";
	else {
		cout << " ***************************\n";
		cout << "        <1> increase\n";  // 選擇第一項為由小到大排列
		cout << "        <2> decrease\n";  // 選擇第二項為由大到小排列
		cout << " ***************************\n";
		do {
			cout << " Please enter your option: ";
			cin>>option;
			cin.get();
			cout << "\n";
		} while(option != '1' && option != '2');
		show(option);
	}
}

void heaptree::create(int id_number)  // ID_NUMBER為新增資料
{
	heap_tree[++last_index] = id_number;  // 將資料新增於最後
	adjust_u(heap_tree, last_index);    // 調整新增資料
}

void heaptree::removes(int index_temp)  // INDEX_TEMP為欲刪除資料之INDEX
{ 
	// 以最後一筆資料代替刪除資料
	heap_tree[index_temp] = heap_tree[last_index];
	heap_tree[last_index--] = 0;
	if(last_index > 1) { // 當資料筆數大於1筆，則做調整
		// 當替代資料大於其PARENT NODE，則往上調整
		if(heap_tree[index_temp] > heap_tree[index_temp / 2] && index_temp > 1)
			adjust_u(heap_tree, index_temp);
		else // 替代資料小於其CHILDEN NODE，則往下調整
			adjust_d(heap_tree, index_temp, last_index-1);
	}
}

void heaptree::show(char op)
{
	int heap_temp[MAX+1];
	int c_index;
	// 將堆積樹資料複製到另一個陣列作排序工作
	for(c_index = 1; c_index <= last_index; c_index++)
	    heap_temp[c_index] = heap_tree[c_index];
	// 將陣列調整為由小到大排列
	for(c_index = last_index-1; c_index > 0; c_index--) {
		exchange(&heap_temp[1], &heap_temp[c_index+1]);
		adjust_d(heap_temp, 1, c_index);
	}
	cout << "\n       ID number\n";
	cout << " =====================\n";
	// 選擇第一種方式輸出，以遞增方式輸出--使用堆疊
	// 選擇第二種方式輸出，以遞減方式輸出--使用佇列
	switch(op) {
		case '1': 
			for(c_index = 1; c_index <= last_index; c_index++) {
				cout.width(14);
				cout << heap_temp[c_index] << "\n";
			}
			break;
		case '2': 
			for(c_index = last_index; c_index > 0; c_index--) {
				cout.width(14);
				cout << heap_temp[c_index] << "\n";
			}
			break;
	}
	cout << " =====================\n";
	cout << " Total member: " << last_index << "\n";
}

void heaptree::adjust_u(int temp[], int index) // INDEX為目前資料在陣列之INDEX
{
	while(index > 1) { // 將資料往上調整至根為止
		if(temp[index] <= temp[index/2])  // 資料調整完畢就跳出，否則交換資料
			break;
		else
			exchange(&temp[index], &temp[index/2]);
		index /= 2;
	}
}

// INDEX1為目前資料在陣列之INDEX，INDEX2為最後一筆資料在陣列之INDEX
void heaptree::adjust_d(int temp[], int index1, int index2)
{ 
	// ID_NUMBER記錄目前資料，INDEX_TEMP則是目前資料之CHILDEN NODE的INDEX
	int id_number, index_temp;
	id_number = temp[index1];
	index_temp = index1 * 2;
	// 當比較資料之INDEX不大於最後一筆資料之INDEX，則繼續比較
	while(index_temp <= index2) {
		if((index_temp < index2) && (temp[index_temp] < temp[index_temp+1]))
			index_temp++;  // INDEX_TEMP記錄目前資料之CHILDEN NODE中較大者
		if(id_number >= temp[index_temp])  // 比較完畢則跳出，否則交換資料
			break;
		else {
			temp[index_temp/2] = temp[index_temp];
			index_temp *= 2;
		}
	}
	temp[index_temp/2] = id_number;
}

void heaptree::exchange(int *id1, int *id2)  // 交換傳來之ID1及ID2儲存之資料
{
	int id_number;
	id_number = *id1;
	*id1 = *id2;
	*id2 = id_number;
}

int heaptree::search(int id_number)  // 尋找陣列中ID_NUMBER所在
{
	int c_index;
	for(c_index = 1; c_index <= MAX; c_index++)
	    if(id_number == heap_tree[c_index])
			return c_index;  // 找到則回傳資料在陣列中之INDEX
	return 0;  // 沒找到則回傳0
}

int main()
{
	heaptree obj;
	char option;
	do {
		cout << "\n ***************************\n";
	    cout << "         <1> login\n";
		cout << "         <2> logout\n";
		cout << "         <3> show\n";
		cout << "         <4> quit\n";
		cout << " ***************************\n";
		cout << " Please enter your choice: ";
		cin>>option;
		cin.get();
		cout << "\n";
		switch(option) {
			case '1': obj.insert_f();
					break;
			case '2': obj.delete_f();
					break;
			case '3': obj.display_f();
					break;
			case '4': system("PAUSE");
	return 0;
			default : cout << "\n Option error!!\n";
		}
	} while(option != '4');
}

