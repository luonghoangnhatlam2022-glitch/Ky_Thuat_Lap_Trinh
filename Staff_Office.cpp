#include <bits/stdc++.h>
using namespace std; 
struct office {
    int id; 
    string name; 
    string date ; 
    long double salary; 
};
void nhap_nhan_vien(office a){
    cout << "nhap ten nhan vien : ";
    cin >> a.name;
    cout << "nhap ID nhan vien : ";
    cin >> a.id;
    cout << "nhap nam sinh nhan vien : ";
    cin >> a.date;
    cout << "tien luong nhan vien nhan : ";
    cin >> a.salary;
}
void xuat_nhan_vien(office a){
    cout << "ten nhan viên: " << a.name;
    cout << "id nhan vien  : " << a.id;
    cout << "ngay sinh nhan vien : " << a.date;
    cout << "tien luong cua nhan vien : " << a.salary;

}
int main (){
    office a[1000];
    int n ; 
    cout << "moi nhap so nhan vien : "; 
    cin >> n ; 
    for (int i=0;i<n;i++){
        cout << "Moi Nhap Thong Tin Cua Nhan Vien THu ", i+1 ;
        nhap_nhan_vien(a[i]); 
    }
    for (int i=0;i<n;i++){
        cout << "staff information" << '\n';
        cout << "nhan vien thu: ", i+1; 
        xuat_nhan_vien(a[i]);
    }

    return 0 ; 
}