/* File name: Allpair.cpp*/
/* August, 2017 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#define MAXV 10
#define Infinite 1073741823

class Allpair {
private:
    long int A[MAXV+1][MAXV+1];
    long int D[MAXV+1][MAXV+1];
    long int Origin[MAXV+1][MAXV+1];
    int N;
    int first = 1;
public:
    Allpair();
    int getN();
    void init();
    void Output();
    void Changed(int num);
    void AllPairLength(int N);
};

Allpair::Allpair() {
    init();
}

int Allpair::getN() {
    return N;
}

void Allpair::init()
{
    FILE *fptr;
    int i, j;
    long int weight;
    fptr = fopen("allpair.dat", "r");
    if ( fptr == NULL )	{
        perror("allpair.dat");
        exit(1);
    }
    fscanf(fptr, "%d", &N);
    for ( i=1; i<=N; i++ )
        for ( j=1; j<=N; j++ )
            A[i][j] = Infinite;
    while ( fscanf(fptr, "%d %d %ld", &i, &j, &weight) != EOF )
        A[i][j] = weight;
    fclose(fptr);
    for ( i = 1; i <= N; i++){
        for ( j = 1; j <= N; j++ ){
            D[i][j] = A[i][j];
        }
        D[i][i] = 0;
    }
    cout << "If the distance is changed, \nthen it will have '*' symbol !!\n";
    cout << "    A#" << 0;
    Output();
}

void Allpair::AllPairLength(int N)
{
    int i, j, k;
    first = 0;
    for(k=1; k<=N; k++){
        
        for(i=1; i<=N; i++){
            for(j=1; j<=N; j++){
                if ((D[i][k] + D[k][j]) < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
        cout << "\n    A#" << k;
        Changed(k);
        Output();
    }
}

void Allpair::Output()
{
    int i=0, j=0;
    
    cout << "\n";
    for ( i=1 ; i<=N ; i++)
        cout << "======";
    cout << "\n";
    cout << "    j";
    for ( i=1; i<=N; i++ )
        cout << setw(4) << i;
    cout << "\n";
    for ( i=1 ; i<=N ; i++)
        cout << "------";
    cout << "\n";
    for ( i =1; i<=N ; i++){
        if (i == (1+N)/2)
            cout << "i";
        else
            cout << " ";
        cout << setw(4) << i;
        for ( j=1; j<=N; j++ )
            if ( D[i][j] == Infinite )
                cout << "   ∞";
            else{
                if (Origin[i][j] != D[i][j] && first != 1)
                    cout << "  *" << D[i][j];
                else
                    cout << setw(4) << D[i][j];
            }
        cout << "\n";
    }
    cout << "\n";
    for ( i=1 ; i<=N ; i++)
        cout << "======";
    cout << "\n";
}

void Allpair::Changed(int num)
{
    int i, j, k;
    switch(num){
        case 1:
            for ( i = 1; i <= N; i++){
                for ( j = 1; j <= N; j++ ){
                    Origin[i][j] = A[i][j];
                }
                Origin[i][i] = 0;
            }
            break;
        default:
            for(k=num-1; k<=num-1 ; k++){
                for(i=1; i<=N; i++){
                    for(j=1; j<=N; j++){
                        if ((Origin[i][k] + Origin[k][j]) < Origin[i][j])
                            Origin[i][j] = Origin[i][k] + Origin[k][j];
                    }
                }
            }
            break;
    }
}

int main()
{
    Allpair obj;
    obj.AllPairLength(obj.getN());
    getchar();
    return 0;
}