#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

struct HocSinh{
    char maSo[7];
    char ten[30];
    char queQuan[30];
    float tongDiem;

    void in(){
        cout<<setw(15)<<left<<maSo;
        cout<<setw(35)<<left<<ten;
        cout<<setw(35)<<left<<queQuan;
        cout<<setw(15)<<left<<tongDiem<<endl;
    }
    void nhap(){
        cout<<"nhap ma so: ";
        cin.ignore();
        cin.getline(maSo, 7);
        cout<<"nhap ho ten: ";
        cin.ignore();
        cin.getline(ten, 30);
        cout<<"nhap que quan: ";
        cin.ignore();
        cin.getline(queQuan, 30);
        cout<<"nhap tong diem: ";
        cin>>tongDiem;
    }
};
void inTieuDe(){
    cout<<setw(15)<<left<<"MA SO";
    cout<<setw(35)<<left<<"TEN";
    cout<<setw(35)<<left<<"QUE QUAN";
    cout<<setw(15)<<left<<"TONG DIEM"<<endl;
}
void nhapDSHocSinh(HocSinh hs[], int n){
    cout<<"------------ nhap danh sach hoc sinh ----------------\n";
    for (int i = 0; i < n; i++)
    {   
        cout<<"------------ nhap hoc sinh thu "<<i+1<<endl;
        hs[i].nhap();
    }
    system("cls");
}

void inTheoThuTuGiamTD(HocSinh hs[], int n){\
// sap xep giam
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i+1; j<n;j++){
            if(hs[i].tongDiem < hs[j].tongDiem){
                HocSinh temp =  hs[i];
                hs[i] = hs[j];
                hs[j] = temp;
            }
        }
    }
    // in
    cout<<"------------ giam dan tong diem ------------- \n";
    inTieuDe();
    for(int i = 0 ; i < n; i++){
        hs[i].in();
    }
}
void queNamDinh(HocSinh hs[], int n){
    char nd[] = "nam dinh";
    cout<<"-------------- que nam dinh ---------------\n";
    inTieuDe();
    for(int i = 0 ; i< n; i++){
        char check[30];
        strcpy(check,hs[i].queQuan);
        for(int j = 0; j <30 ; j++){
            tolower(check[i]);
        }
        if (strstr(nd, check) != nullptr) {
            hs[i].in();
        }
    }
}

int main(){
    int n;
    cout<<"nhap so luong hoc sinh: ";
    cin>>n;
    HocSinh hs[n];
    nhapDSHocSinh(hs, n);
    inTheoThuTuGiamTD(hs, n);
    queNamDinh(hs, n);
    return 0;
}