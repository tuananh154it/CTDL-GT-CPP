#include <iostream>
#include <iomanip>

using namespace std;

struct MatHang{
    char maHang[8];
    char tenHang[30];
    int soLuong;
    float donGia;
    float thanhTien;
    void nhap(){
        cin.ignore();
        cout<<"nhap ma hang: ";
        cin.getline(maHang, 8);
        cout<<"nhap ten hang: ";
        cin.ignore();
        cin.getline(tenHang, 30);
        cout<<"nhap so luong: ";
        cin>>soLuong;
        cout<<"nhap don gia: ";
        cin>>donGia;
    }
    void in(){
        cout<<setw(15)<<left<<maHang;
        cout<<setw(35)<<left<<tenHang;
        cout<<setw(15)<<left<<soLuong;
        cout<<setw(15)<<left<<donGia;
        cout<<setw(15)<<left<<thanhTien<<endl;
    }
};
void inTieuDe(){
    cout<<setw(15)<<left<<"MA HANG";
    cout<<setw(35)<<left<<"TEN HANG";
    cout<<setw(15)<<left<<"SO LUONG";
    cout<<setw(15)<<left<<"DON GIA";
    cout<<setw(15)<<left<<"THANH TIEN"<<endl;
}

float tinhThanhTien(int soLuong, float donGia){
    return soLuong*donGia;
}

void nhapDSMatHang(MatHang mhs[], int n){
    cout<<"--------------- nhap danh sach mat hang ----------------\n";
    for(int i = 0; i<n ; i++){
        mhs[i].nhap();
        mhs[i].thanhTien = tinhThanhTien(mhs[i].soLuong, mhs[i].donGia);
        system("cls");
    }
}
void matHangDonGiaLonHon50(MatHang mhs[], int n){
    cout<<"------------- don gia lon hon 50 -------------\n";
    inTieuDe();
    for(int i = 0; i < n; i++){
        if(mhs[i].donGia > 50){
            mhs[i].in();
        }
    }
}
int main(){
    int n;
    cout<<"nhap so luong mat hang: ";
    cin>>n;
    MatHang mhs[n];
    nhapDSMatHang(mhs, n);
    matHangDonGiaLonHon50(mhs, n);
    return 0;
}