#include <iostream>
using namespace std;


void inMang(int *arr, int n, string message)
{
    cout << "---------- " << message << " ---------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i]<<"  ";
    }
    cout<<endl;
}

void nhapMang(int *arr, int n)
{
    cout << "---------- nhap mang ---------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    system("cls");
    inMang(arr, n, "mang vua nhap la");
}


void inNguoc(int *arr, int n)
{
    cout << "-------- in nguoc mang nhap vao ---------- \n";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

int timKiem(int *arr, int n)
{
    cout<<"-------- tim kiem ----------- \n";
    int s, count = 0;
    cout << "nhap vao gia tri can tim kiem: ";
    cin >> s;
    cout << "vi tri phan tu co gia tri bang " << s << " la: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s)
        {
            cout << i << "  ";
            count++;
        }
    }
    if (count == 0)
    {
        cout << "khong co vi tri nao";
    }
    cout << endl;
}

void sapXepTang(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    inMang(arr, n, "sau khi sap xep tang");
}
int main()
{
    int n;
    cout << "nhap so phan tu cua mang: ";
    cin >> n;
    int arr[n];
    //
    nhapMang(arr, n);
    //
    inNguoc(arr, n);
    //
    timKiem(arr, n);
    //
    sapXepTang(arr, n);
}