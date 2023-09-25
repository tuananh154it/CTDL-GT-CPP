#include<iostream>
using namespace std;

struct  PhanSo
{
    float t;
    float m;
    void nhap(string message){
        cout<<"-------------"<<message<<"------------\n";
        cout<<"nhap tu so: ";
        cin>>t;
        while (true)
        {
            cout<<"nhap mau so: ";
            cin>>m;
            if (t != 0)
            {
                break;
            }
            cout<<"CANH BAO: mau khong duoc  = 0, nhap lai !!!!! \n";
        }
        
    }
};
PhanSo tong2PhanSo(PhanSo pt_1, PhanSo pt_2){
    PhanSo result;
    result.t = pt_1.t*pt_2.m + pt_2.t*pt_1.m;
    result.m = pt_1.m * pt_2.m;
    return result;
}
int main(){
    int n;
    cout<<"nhap so luong phan so: ";
    cin>>n;
    // khoi tao bien luu tong
    PhanSo tong;
    tong.t = 0;
    tong.m = 1;
    for(int i = 0; i < n; i++){
        PhanSo pt_n;
        pt_n.nhap("nhap phan so thu " + (i+1));
        tong = tong2PhanSo(tong, pt_n);
    }

    cout<<"tong cac phan so vua nhap: "<<tong.t<<"/"<<tong.m<<endl;

    return 0;
}