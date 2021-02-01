/* File name: ShPath.cpp */
/* August, 2017 */
/* 最短路徑 : Dijkstra法 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#define  MAX_V  100   /*最大節點數*/
#define  VISITED  1
#define  NOTVISITED  0
#define  Infinite  1073741823

using namespace std;

// A[1..N][1..N] 為圖形的相鄰矩陣
// D[i] i=1..N 用來儲存某起始頂點到i節點的最短距離
// S[1..N] 用來記錄頂點是否已經拜訪過
// P[1..N] 用來記錄最近經過的中間節點

class G_shpath {
private:
    long int  A[MAX_V+1][MAX_V+1];
    long int  D[MAX_V+1];
    long int  S[MAX_V+1],P[MAX_V+1];
    int source , sink , N;
    int step;
    int top;  // 堆疊指標
    int Stack[MAX_V+1];   // 堆疊空間
public:
    G_shpath();
    void init();
    void access();
    int  minD();
    void output_step();
    void output_path();
    void Push(int);
    int  Pop();
};

G_shpath::G_shpath()
{
    step = 1;
    top = -1;
}
void G_shpath::init()
{
    ifstream fin;
    int i,j;
    long int weight;
    
    fin.open("sh_path.dat", ios::in);
    if ( !fin.good() ) {
        perror("sh_path.dat");
        exit(1);
    }
    fin >> N;   // 讀取圖形節點數
    for ( i=1; i<=N; i++ )
        for ( j=1; j<=N; j++ )
            A[i][j] = Infinite;  // 起始A[1..N][1..N]相鄰矩陣
    while ( !fin.eof() ) {
        fin >> i >> j >> weight;
        A[i][j] = weight;    // 讀取i節點到j節點的權weight
    }
    fin.close();
    cout << "Enter source node : ";
    cin >> source;
    cout << "Enter sink node : ";
    cin >> sink;
    // 起始各陣列初值
    for ( i = 1; i <= N; i++ ) {
        S[i] = NOTVISITED; // 各頂點設為尚未拜訪
        D[i] = A[source][i]; // 記錄起始頂點至各頂點最短距離
        P[i] = source;
    }
    S[source] = VISITED;  // 始起節點設為已經走訪
    D[source] = 0;
}

void G_shpath::access()
{
    int I, t;
    
    for ( step =2;step <=N; step++ ) {
        // minD 傳回一值t使得D[t] 為最小
        t = minD();
        S[t] = VISITED;
        // 找出經過t點會使路徑縮短的節點
        for ( I=1; I <= N; I++ )
            if ( (S[I] == NOTVISITED) && (D[t]+A[t][I] <= D[I]) ) {
                D[I] = D[t] + A[t][I];
                P[I] = t;
            }
        output_step();
    }
}
int G_shpath::minD()
{
    int i,t;
    long int minimum = Infinite;
    
    for ( i=1;i<=N;i++ )
        if ( (S[i] == NOTVISITED) && D[i] < minimum ) {
            minimum = D[i];
            t = i;
        }
    return t;
}

// 顯示目前的D陣列與P陣列狀況
void G_shpath::output_step()
{
    int i;
    
    cout << "\n Step #" << step;
    cout << "\n================================================\n";
    for ( i=1; i<=N; i++ )
        cout << "  D[" << i << "]";
    cout << "\n";
    for ( i=1; i<=N; i++ )
        if ( D[i] == Infinite )
            cout << "  ----";
        else {
            cout.width(6);
            cout << D[i];
        }
    cout << "\n================================================\n";
    for (i=1 ; i<=N ; i++)
        cout << "  P[" << i << "]";
    cout << "\n";
    for (i=1 ; i<=N ; i++) {
        cout.width(6);
        cout << P[i];
    }
}

// 顯示最短路徑
void G_shpath::output_path()
{
    int node = sink;
    
    // 判斷是否起始頂點等於終點或無路徑至終點
    if ( (sink == source) || (D[sink] == Infinite) ) {
        cout << "\nNode " << source
        << " has no Path to Node " << sink;
        return;
    }
    cout << "\n";
    cout << " The shortest Path from V" << source << " to V" << sink << " :";
    cout << "\n------------------------------------------\n";
    // 由終點開始將上一次經過的中間節點推入堆疊至到起始節點
    cout << "  V" << source;
    while ( node != source ) {
        Push(node);
        node  = P[node];
    }
    while( node != sink) {
        node = Pop();
        cout << " --" << A[ P[node] ][node] << "-->";
        cout << "V" << node;
    }
    cout << "\n Total length : " << D[sink] << "\n";
}

void G_shpath::Push(int value)
{
    if ( top >= MAX_V ) {
        cout << "Stack overflow!\n";
        exit(1);
    }
    else
        Stack[++top] = value;
}

int G_shpath::Pop()
{
    if ( top < 0 ) {
        cout << "Stack empty!\n";
        exit(1);
    }
    return Stack[top--];
}

int main()
{
    G_shpath obj;
    
    obj.init();
    obj.output_step();
    obj.access();
    obj.output_path();
    
    system("PAUSE");
    return 0;
}