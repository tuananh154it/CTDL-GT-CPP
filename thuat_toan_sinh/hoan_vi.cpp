#include<iostream>
using namespace std;

int n;
int A[100];
int B[100];
int C[100];
int dem=0,dem1=0;

void Xuat()
{
    cout<<"A["<<dem<<"]=";
    for(int i=1;i<=n;i++)
    {
        cout<<C[i]<<" ";
    }
    cout<<endl;
}

void F( int a )
{
    for(int i=1;i<=n;i++)
    {
        if ( B[i]==0 )
        {
            C[a]=A[i];
            B[i]=a;
            dem1++;
        }
        if ( a==n )
        {
            if ( dem1==n )
            {
                dem++;
                Xuat();
            }
        }
        else F(a+1);
        if ( B[i]==a )
        {
            B[i]=0;
            dem1--;
        }
    }
}

int main()
{
    n=6;
    for (int i=1;i<=n;i++)
    {
        A[i]=i;
        B[i]=0;
    }
    F(1);
}