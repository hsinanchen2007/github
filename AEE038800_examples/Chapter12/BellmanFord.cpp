/* File name: BellmanFord.cpp */
/* August, 2017 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#define MAXV 100
#define Infinite 1073741823
using namespace std;



class BellmanFord {
private:
    long int A[MAXV+1][MAXV+1];
    long int D[MAXV+1];
    long int changed[MAXV+1];
    int N;
public:
    BellmanFord();
    void init();
    void Output();
    void BellmanFord_access();
};

BellmanFord::BellmanFord() {
    init();
}

int main()
{
    BellmanFord obj;
    obj.BellmanFord_access();
    getchar();
    return 0;
}

void BellmanFord::init()
{
    FILE *fptr;
    int i, j;
    long int weight;
    fptr = fopen("source.dat", "r");
    if ( fptr == NULL ) {
        perror("source.dat");
        exit(1);
    }
    fscanf(fptr, "%d", &N);       /*讀取圖形節點數*/
    for ( i=1; i<=N; i++ )
        for ( j=1; j<=N; j++ )
            A[i][j] = Infinite;  /*起始A[1..N][1..N]相鄰矩陣*/
    while ( fscanf(fptr, "%d %d %ld", &i, &j, &weight) != EOF )
        A[i][j] = weight;      /*讀取i節點到j節點的權weight */
    fclose(fptr);
    /* 起始各陣列初值*/
    for( i =1; i<=N ; i++){
        D[i] = A[1][i]; /*記錄起始頂點至各頂點最短距離*/
        changed[i] = A[1][i];
    }
    changed[1] = 0;
    D[1] = 0;
    cout << "       disk[" << N << "]\n";
    for ( i=1 ; i<=N ; i++)
        printf("=====");
    cout << "\n";
    for ( i=1; i<=N; i++ )
        cout << setw(4) << i;
    cout << "\n";
    for ( i=1 ; i<=N ; i++)
        cout << "-----";
       cout << "\n";
       Output();
       cout << "\n";
}

void BellmanFord::BellmanFord_access()
{
    int  i, u, k;
    for(k=1; k<= N-2; k++)
    {
        for(u=1; u<=N ; u++)
        {
            for(i=1; i<=N ; i++){
                if(D[u] > D[i] + A[i][u]){
                    if (changed[u] > D[i]+A[i][u])
                        changed[u] = D[i] + A[i][u];
                }
            }
        }
        Output();
        cout << "\n";
    }
    cout << "\n";
    for ( i=1 ; i<=N ; i++)
        cout << "=====";
    cout << "\n";
}

void BellmanFord::Output(void)
{
    int i=0, j=0;
    for (j=1 ; j<=N ; j++){
        if ( changed[j] == Infinite )
            cout << "   ∞" ;
        else{
            if (changed[j] != D[j] )
                cout << "  *" << changed[j];
            else
                cout << setw(4) << changed[j];
        }
    }
    for(i=1 ; i<=N ; i++)
        D[i] = changed[i];
}