/* File name: SparseMatrix.cpp */
/* August 2017 */

#include <iostream>
#include <stdlib.h>

using namespace std;

#define width 6   //矩陣寬
#define height 6  //矩陣高

class SparseMatrix {
private:
    int sm[10][3];  //儲存稀疏矩陣的資料結構預設 10 - 1 = 9 個元素
    int smRow=1;
    int source[width][height]=
    { 0,15, 0, 0,-8, 0,
        0, 0, 6, 0, 0, 0,
        0, 0, 0,-6, 0, 0,
        0, 0,18, 0, 0, 0,
        0, 0, 0, 0, 0,16,
        72, 0, 0, 0,20, 0
    };
    int row=0,col=0;
    int nonZero=0;
public:
    int getNonZero();
    void scanMatrix();
    void outputSm(int);
};

int SparseMatrix::getNonZero(){
    return nonZero;
}

void SparseMatrix::scanMatrix()
{
    cout << "Scan the matrix...\n";
    while (row < height && col < width) {
        if(source[row][col] !=0){
            nonZero++;  //計算非零元素個數
            sm[smRow][0] = row+1;
            sm[smRow][1] = col+1;
            sm[smRow][2] = source[row][col];
            smRow++;
        }
        if(col == width-1){  //先掃單一列上所有元素
            row++;
            if(row <= height-1) //當掃到最後一列就不歸零
                col=0;
        }
        else
            col++;
    }
    cout << "Total nonzero elements = " << nonZero << " \n";
    //稀疏矩陣資料結構資訊
    sm[0][0] = row;
    sm[0][1] = col+1; //最後col停在陣列編號最後一個元素,換成個//數要加1
    sm[0][2] = nonZero;
}

void SparseMatrix::outputSm(int nonZero)
{
    int i,j;
    cout << "     1)  2)  3)\n";
    cout << "----------------\n";
    for(i=0 ; i <= nonZero ;i++) {
        cout << "A(" << i << ", ";
        for(j=0 ; j < 3; j++)
            cout << " " << sm[i][j] << " ";
        cout << "\n";
    }
}



int main()
{
    SparseMatrix obj;
    //掃描矩陣
    obj.scanMatrix();
    //輸出稀疏矩陣
    obj.outputSm(obj.getNonZero());
    return 0;
}