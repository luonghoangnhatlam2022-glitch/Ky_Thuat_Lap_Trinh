#include <iostream> 
#include <fstream> 
#include <bits/stdc++.h>
using namespace std; 
int main (){
    ofstream nhapfile;
    nhapfile.open("file.data");
    int a , b , c ; 
    cout << "nhap ba so a , b , c :" ; 
    cin >> a >> b >> c ; 
    nhapfile << a << b << c ;
    nhapfile.close(); 
    // giai phuong trinh ax^2 + bx + c 
    double denta= b * b - 4 * a * c ; 
    
    if( denta == 0 ){
        if ( b == 0 ) cout << " phuong trinh vo nghiem: "; 
    } else 




}