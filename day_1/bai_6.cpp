#include <iostream>
using namespace std;

void inMaTran(int **mt, int rows, int cols, string message)
{
    cout << "---------- " << message << " -----------\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mt[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
void nhapMaTran(int **mt, int rows, int cols, string message)
{
    cout << "---------- " << message << " -----------\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "mt[" << i << "][" << j << "] = ";
            cin >> mt[i][j];
        }
    }
    inMaTran(mt, rows, cols, "sau khi nhap");
}

void tongMaTran(int **mt_1, int **mt_2, int rows, int cols)
{
    int *result[rows];
    for (int i = 0; i < rows; i++)
    {
        result[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = mt_1[i][j] + mt_2[i][j];
        }
    }
    inMaTran(result, rows, cols, "tong 2 ma tran");
}
void tichMaTran(int **mt_1, int **mt_2, int rows, int cols)
{
    if (rows != cols)
    {
        cout << "khong ton tai tich 2 ma tran nay \n";
        return;
    }
    int *result[rows];
    for (int i = 0; i < rows; i++)
    {
        result[i] = new int[rows];
        for (int j = 0; j < rows; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < rows; k++)
            {
                result[i][j] += (mt_1[i][k] * mt_2[k][j]);
            }
        }
    }
    inMaTran(result, rows, rows, "tich 2 ma tran");
}
void timPhanTuMinMax(int **mt,int rows, int cols){
    int min = mt[0][0];
    int max = mt[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(min > mt[i][j]){
                min = mt[i][j];
            }
            if(max < mt[i][j]){
                max = mt[i][j];
            }
        }
    }
    cout<<"phan tu min cua ma tran la: "<<min<<endl;
    cout<<"phan tu max cua ma tran la: "<<max<<endl;
}
int main()
{
    int m, n;
    cout << "nhap so hang: ";
    cin >> m;
    cout << "nhap so cot: ";
    cin >> n;
    int *mt_1[m], *mt_2[m]; // mảng các con trỏ, mỗi con trỏ tương ứng 1 hàng
    for (int i = 0; i < m; i++)
    {
        // cấp phát động
        mt_1[i] = new int[n];
        mt_2[i] = new int[n];
    }
    // nhap 2 ma tran
    nhapMaTran(mt_1, m, n, "nhap ma tran 1");
    nhapMaTran(mt_2, m, n, "nhap ma tran 2");
    // tinh tong
    tongMaTran(mt_1, mt_2, m, n);
    tichMaTran(mt_1, mt_2, m, n);
    // tìm min max của ma trận
    timPhanTuMinMax(mt_1, m, n);
    timPhanTuMinMax(mt_2, m, n);

    return 0;
}