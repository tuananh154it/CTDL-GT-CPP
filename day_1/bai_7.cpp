#include<iostream>
#include<string.h>
using namespace std;

struct SoPhuc
{
    double thuc;
    double ao;

    SoPhuc(double t, double a){
        thuc = t;
        ao = a;
    }
    SoPhuc(){};

    void nhapVao(string thongBao){
        cout<<"--------- "<<thongBao<<" -----------"<<endl;
        cout<<"nhap vao phan thuc: ";
        cin>>thuc;
        cout<<"nhap vao phan ao: ";
        cin>>ao;
        system("cls");
    }
    // hàm trả về số thực dạng string
    string inRa(){
        return to_string(thuc) + " + "+ to_string(ao) + "j";
    }
};
SoPhuc tong(SoPhuc s1,SoPhuc s2){
    SoPhuc result = SoPhuc(s1.thuc + s2.thuc, s1.ao + s2.ao);
    return result;
}

SoPhuc hieu(SoPhuc s1,SoPhuc s2){
    SoPhuc result = SoPhuc(s1.thuc - s2.thuc, s1.ao - s2.ao);
    return result;
}

int main(){
    SoPhuc soPhuc1, soPhuc2;
    // nhap so phuc tu ban phim
    soPhuc1.nhapVao("nhap so phuc thu 1");
    soPhuc2.nhapVao("nhap so phuc thu 2");
    // tinh tong
    cout<<"("<<soPhuc1.inRa()<<") + ("<<soPhuc2.inRa()<<") = "<<tong(soPhuc1,soPhuc2).inRa()<<endl;
    // tinh hieu
    cout<<"("<<soPhuc1.inRa()<<") - ("<<soPhuc2.inRa()<<") = "<<hieu(soPhuc1,soPhuc2).inRa()<<endl;
    return 0;
}