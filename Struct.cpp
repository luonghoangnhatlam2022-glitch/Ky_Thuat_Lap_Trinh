#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct PhanSo {
    int TuSo;
    int MauSo;  
};
struct HonSo{
    int phannguyen; 
    PhanSo phanso;
};
void nhapPS(PhanSo&a);
void xuatPS(PhanSo a);
PhanSo Sum(PhanSo ps1,PhanSo ps2);
PhanSo Subtraction(PhanSo ps1,PhanSo ps2);
PhanSo Multiplication(PhanSo ps1,PhanSo ps2);
PhanSo Divide(PhanSo ps1,PhanSo ps2);
void RutGon(PhanSo &ps);
//
void nhapHS(HonSo&a);
void xuatHS(HonSo a);
PhanSo chuyenHSsangPS(HonSo a);
HonSo chuyenPSsangHS(PhanSo a);
HonSo SumHS(HonSo a,HonSo b ); 
// 
void nhapMang(PhanSo a[],int n );
void xuatMang(PhanSo a[],int n);
int main(){
    freopen("Struct.inp", "r", stdin);
    freopen("Struct.out", "w", stdout);
    PhanSo ps1; 
    PhanSo ps2; 
    nhapPS(ps1);nhapPS(ps2);
    xuatPS(Sum(ps1,ps2));
    xuatPS(Subtraction(ps1,ps2));
    xuatPS(Multiplication(ps1,ps2));
    xuatPS(Divide(ps1,ps2));
    cout <<"==============="<<endl;
    ///////////////////////////////////////////////
    HonSo hs1,hs2;
    nhapHS(hs1); nhapHS(hs2);
    xuatHS(hs1); xuatHS(hs2);
    xuatPS(chuyenHSsangPS(hs1));
    xuatPS(chuyenHSsangPS(hs2));
    xuatHS(chuyenPSsangHS(chuyenHSsangPS(hs1)));
    xuatHS(chuyenPSsangHS(chuyenHSsangPS(hs2)));
    xuatHS(SumHS(hs1,hs2));
    cout << "==============="<<endl; 
    //////////////////////////////////////////////
    PhanSo mangps[1000];
    int n; cin>> n; 
    PhanSo kq={0,1}; 
    nhapMang(mangps,n);
    //xuatMang(mangps,n);
    for (int i=0; i<n; i++){
        kq=Sum(kq,mangps[i]);
    }
    xuatPS(kq);
    PhanSo maxx=mangps[0];
    double tmp=mangps[0].TuSo / mangps[0].MauSo;
    for (int i=0;i<n;i++){
        if(tmp<(mangps[i].TuSo/(double)mangps[i].MauSo)){
            tmp=mangps[i].TuSo/(double)mangps[i].MauSo;
            maxx=mangps[i];
        }
    }
    xuatPS(maxx);
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if((mangps[i].TuSo/(double)mangps[i].MauSo)>
                (mangps[j].TuSo/(double)mangps[j].MauSo)){
                    swap(mangps[i],mangps[j]);
        }
        }
    }
    xuatMang(mangps,n);
    return 0;
}

void nhapPS(PhanSo &a){
    cin >> a.TuSo ;
    cin >> a.MauSo; 
}
void xuatPS(PhanSo a){
    cout<< a.TuSo << "/"<< a.MauSo; 
    cout << endl ;
}
PhanSo Sum(PhanSo ps1,PhanSo ps2){
    PhanSo result; 
    result.TuSo=ps1.TuSo*ps2.MauSo+ps1.MauSo*ps2.TuSo;
    result.MauSo=ps1.MauSo*ps2.MauSo; 
    RutGon(result);
    return result; 
}
PhanSo Subtraction(PhanSo ps1,PhanSo ps2){
    PhanSo result; 
    result.TuSo=ps1.TuSo*ps2.MauSo-ps1.MauSo*ps2.TuSo;
    result.MauSo=ps1.MauSo*ps2.MauSo; 
    RutGon(result);
    return result; 
}
PhanSo Multiplication(PhanSo ps1,PhanSo ps2){
    PhanSo result; 
    int g1=gcd(ps1.TuSo,ps2.MauSo);
    int g2=gcd(ps1.MauSo,ps2.TuSo);
    ps1.TuSo/=g1; ps2.MauSo/=g1; // rut gon truoc khi nhan 
    ps1.MauSo/=g2; ps2.TuSo/=g2;
    result.TuSo=ps1.TuSo*ps2.TuSo;
    result.MauSo=ps1.MauSo*ps2.MauSo; 
    RutGon(result);
    return result; 
}
PhanSo Divide(PhanSo ps1,PhanSo ps2){
    PhanSo result; 
    result.TuSo=ps1.TuSo*ps2.MauSo;
    result.MauSo=ps1.MauSo*ps2.TuSo;
    RutGon(result);
    return result; 
}
void RutGon(PhanSo &a){
    int tmp=gcd(a.TuSo,a.MauSo);
    a.MauSo/=tmp;
    a.TuSo/=tmp;

// chuan hoa dau 
    if(a.MauSo<0){
        a.MauSo*=-1;
        a.TuSo*=-1;
    }
}
////////////////////////////
void nhapHS(HonSo&a){
    cin >> a.phannguyen;
    nhapPS(a.phanso);
}
void xuatHS(HonSo a){
    cout<< a.phannguyen << " ";
    xuatPS(a.phanso);
}
PhanSo chuyenHSsangPS(HonSo a){
    PhanSo kq; 
    kq.MauSo=a.phanso.MauSo;
    kq.TuSo=a.phanso.TuSo+a.phannguyen*a.phanso.MauSo;
    return kq; 
}
HonSo chuyenPSsangHS(PhanSo a){
    HonSo kq;
    kq.phannguyen=a.TuSo/a.MauSo;
    kq.phanso.TuSo=a.TuSo% a.MauSo;
    kq.phanso.MauSo= a.MauSo;
    return kq;
}
HonSo SumHS(HonSo a,HonSo b ){
    return chuyenPSsangHS(Sum(chuyenHSsangPS(a),chuyenHSsangPS(b)));
}
void nhapMang(PhanSo a[],int n){
    for(int i=0;i<n;i++){
        nhapPS(a[i]);
    }
}
void xuatMang(PhanSo a[],int n){
    for (int i=0;i<n;i++){
        xuatPS(a[i]);
    }
}
