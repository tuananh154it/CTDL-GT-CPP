#include<iostream>
using namespace std;

int n,m;
int A[10]; // tập ban đầu
int C[10]; // tập con
int dem=0; // đếm số tập con

// hàm in tập con
void Xuat()
{
    cout<<"C["<<dem<<"]=";
    for(int i=1;i<=m;i++)
    {
        cout<<C[i]<<" ";
    }
    cout<<endl;
}

// hàm sinh tập con
void F(int a,int k) 
{
    //a: vị trí của phần tử trong A đang xét
    //k: vịt trí của phần tử trong C đang xét
    for (int i=a;i<=n;i++)
    {
        C[k]=A[i];
        if(k==m)
        {
            dem++;
            Xuat();
        }
        else F(i+1,k+1);
    }
}

int main()
{
    n=6; // số phần tử của A
    m=4; // số phần tử của C
    
    // thêm phần tử ban đầu cho A
    for (int i=1;i<=n;i++)
    {
        A[i]=i;
    }
    
    F(1,1);
}